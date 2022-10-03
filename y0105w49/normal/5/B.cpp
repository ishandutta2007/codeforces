#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {

  vector< string > msgs;
  string msg;
  int maxlen = 0;
  int cost = 0;
  int pop = 0;
  int offset = 0;

  while (getline(cin,msg)) {
    if (msg.length()>maxlen)
      maxlen=msg.length();
    msgs.push_back(msg);
  }

  for (int i = 0; i<maxlen+2; i++)
    printf("*");
  printf("\n");

  for (int i = 0; i<msgs.size(); i++) {
    msg=msgs[i];
    int shift = (maxlen-msg.length())/2;
    if ((maxlen^msg.length())&1==1) {
      shift+=offset;
      offset=1-offset;
    }

    printf("*");
    for (int j = 0; j<shift; j++)
      printf(" ");

    cout << msg;

    for (int j = 0; j<(maxlen-msg.length()-shift); j++)
      printf(" ");
    printf("*\n");
  }

  for (int i = 0; i<maxlen+2; i++)
    printf("*");
  printf("\n");

  return 0;

}