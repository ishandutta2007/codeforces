#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

  string msg;
  int cost = 0;
  int pop = 0;

  while (getline(cin,msg)) {
    if (msg[0]=='+')
      pop++;
    else if (msg[0]=='-')
      pop--;
    else
      cost+=pop*(msg.length()-msg.find(":")-1);
  }

  cout << cost << endl;

  return 0;

}