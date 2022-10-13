#include <bits/stdc++.h>
using namespace std;


int main() {
  int w;
  cin >> w;

  if(w == 2) {
    cout << "NO" << "\n";
  }
  else if(w % 2 == 0) {
    cout << "YES" << "\n";
  }
  else { //w is odd 
    cout << "NO" << "\n";
  }


  //Condensed problem: Is it possible to split an integer w into 2 parts of positive weight that are even?

  //w = 1 ==> NO
  //w = 2 ==> NO
  //w = 3 ==> NO
  //w = 4 ==> YES
  //w odd ==> NO
  //w is even > 2 ==> YES (take 2 and w - 2)
  //w is 2 ==> NO
}