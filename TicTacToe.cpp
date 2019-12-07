#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class TicTacToe
{

  private:
    vector<std::string> board;

  public:
    TicTacToe();
    void printBoard();
    bool makeMove(int position, std::string player);
    int checkWin();

};

TicTacToe::TicTacToe()
{
  for(int i = 0; i<9; i++)
  {
    board.push_back(to_string(i));
  }
}

void TicTacToe::printBoard()
{
  cout << "Tic Tac Toe: Player 1 is X, Player 2 is O" << endl;
  int pos = 0;
  for(int i = 0; i<5; i++)// Each loop in outer for loop indicates the row number
  {
    if(i%2 == 0)
    {
      for(int k = 0; k<5; k++)// This loops for each piece of the current row if it holds a box
      {
        if(k%2 == 0)
        {
          std::cout << board[pos++];//Adds box number or player piece
        }
        else
        {
          std::cout << "|";//Adds vertical boundary
        }
      }
    }
    else
    {
      for(int k = 0; k<5; k++)// This loops for each piece of the current row if it only has the boundaries
      {
      if(k%2 == 0)
      {
        std::cout << "-"; //Adds horizontal boundary
      }
      else
      {
        std::cout << "+";//Adds boundary intersections
      }
      }
    }
    std::cout << std::endl;
  }
}


bool TicTacToe::makeMove(int position, std::string player)//Determines if the move submitted by player is valid or not
{
  if(position < board.size() && position >= 0)
  {
    if(board[position] != "X" && board[position] != "O")//If move is valid, adds piece to the board
    {
      board[position] = player;
      return true;
    }
    else
    {
      cout << "Box already taken!" << endl;//Error for already occupied space
    }
  }
  else
  {
    cout << "Invalid box!" << endl;//Error for position being out of bounds
  }
  return false;
}

int TicTacToe::checkWin()//Function runs through all possibilities for winning a tic tac toe game
{
  std::string player = "";
  for(int i = 0; i<=6; i+=3)//Check horizontal matches
  {
    if(board[i] == board[i+1] && board[i+1] == board[i+2])
    {
      player = board[i];
    }
  }
  for(int i = 0; i<3; i++)//Check vertical matches
  {
    if(board[i] == board[i+3] && board[i+3] == board[i+6])
    {
      player = board[i];
    }
  }
  if(board[0] == board[4] && board[4] == board[8])//Checks top left to bottom right diagonal
  {
    player = board[0];
  }
  if(board[2] == board[4] && board[2] == board[6])//Checks top right to botton left diagonal
  {
    player = board[2];
  }
  if(player == "X")//If player 1 has a match, returns p1
  {
    return 1;
  }
  else if(player == "O")//If player 2 has a match, returns p2
  {
    return 2;
  }
  else//If no winners, returns 0
  {
    return 0;
  }
}


int main()
{
  TicTacToe game1;//Using OOP concept to implement game
  int gameOver = 0;
  int move = 0;
  for(int i = 0; i<9; i++)//Game loop, only goes to 9 as there is a maximum number of combined moves
  {
    game1.printBoard();
    cout << "Player 1, enter your box: ";
    cin >> move;
    while(!game1.makeMove(move, "X"))//Loop to make sure Player 1 gives a valid move
    {
      cout << "Player 1, enter your box: ";
      cin >> move;
    }
    i++;
    if(game1.checkWin() != 0)//Checks if Player 1 has a winning layout
    {
      gameOver = game1.checkWin();
      i = 9;
      game1.printBoard();
    }
    else if(i<9)
    {
      game1.printBoard();
      cout << "Player 2, enter your box: ";
      cin >> move;
      while(!game1.makeMove(move, "O"))//loop to make sure Player 2 gives a valid move
      {
        cout << "Player 2, enter your box: ";
        cin >> move;
      }
      if(game1.checkWin() != 0)//Checks if Player 2 has a winning layout
      {
        gameOver = game1.checkWin();
        i = 9;
        game1.printBoard();
      }
    }
  }
  if(gameOver == 0)
    cout << "It's a tie!" << endl;
  else
    cout << "Player " << gameOver << " wins!" << endl;


}
