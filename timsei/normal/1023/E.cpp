#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int r1, c1, r2, c2;

bool ask(int r1, int c1, int r2, int c2) {
  printf("? %d %d %d %d\n", r1, c1, r2, c2);
  fflush(stdout);
  string cxt;
  cin >> cxt;
  if(cxt == "YES") return 1;
  else return 0;
}

main(void) {
  int n;
  cin >> n;
  int x1 = 1, y1 = 1;
  while(x1 + y1 < n + 1) {
    if(ask(x1 + 1, y1, n, n)) {
      s1 += 'D';
      ++ x1;
    }
    else {
      ++ y1; s1 += 'R';
    }
  }
  x1 = n, y1 = n;
  while(x1 + y1 > n + 1) {
    if(ask(1, 1, x1, y1 - 1)) {
      s2 += 'R';
      -- y1;
    }
    else s2 += 'D', -- x1;
  }
  reverse(s2.begin(), s2.end());
  s1 += s2;
  cout << "! ";
  cout << s1 << endl;
}