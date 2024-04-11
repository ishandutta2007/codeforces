//begin read 20:10

#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

  string s;
  cin >> s;

  int mf;
  if (s.size()>1)
    mf = (10*(s[s.size()-2]-'0'))+s[s.size()-1]-'0';
  else
    mf = s[0]-'0';
  mf = mf%4;

  switch (mf) {
  case 0:
    printf("4\n");
    return 0;
  case 1:
  case 2:
  case 3:
    printf("0\n");
    return 0;
  }

  printf("arst\n");
  return 0;

}

//end 20:20