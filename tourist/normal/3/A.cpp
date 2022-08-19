/**
 *    author:  tourist
 *    created: 10.01.2022 23:42:59       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a;
  string b;
  cin >> a >> b;
  vector<string> moves;
  while (a != b) {
    string mv = "";
    if (a[0] < b[0]) {
      mv += "R";
      a[0] += 1;
    }
    if (a[0] > b[0]) {
      mv += "L";
      a[0] -= 1;
    }
    if (a[1] < b[1]) {
      mv += "U";
      a[1] += 1;
    }
    if (a[1] > b[1]) {
      mv += "D";
      a[1] -= 1;
    }
    moves.push_back(mv);
  }
  cout << moves.size() << '\n';
  for (auto& s : moves) {
    cout << s << '\n';
  }
  return 0;
}