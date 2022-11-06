#include <bits/stdc++.h>
using namespace std;

int Scan(int a, int b) {
  cout << "SCAN " << a << ' ' << b << endl << flush;
  int x;
  cin >> x;
  return x;
}

int Dig(int a, int b) {
  cout << "DIG " << a << ' ' << b << endl << flush;
  int x;
  cin >> x;
  return x;
}

void solve() {
  int n, m;
  cin >> n >> m;
  int A = Scan(1, 1);
  int B = Scan(n, 1);

  int r1pr2 = -(B - A - 2 * n - 2) / 2;
  int C = Scan(r1pr2 / 2, 1);

  int r1 = (A - C + 2) / 2;
  int r2 = r1pr2 - r1;

  int c1pc2 = A + 4 - r1 - r2;
  int D = Scan(1, c1pc2 / 2);
  
  int c1 = (A - D + 2) / 2;
  int c2 = c1pc2 - c1;

  if (Dig(r1, c1)) {
    Dig(r2, c2);
  } else {
    Dig(r1, c2);
    Dig(r2, c1);
  }
}


int main() {
  int t; cin >> t;
  while (t--) solve();
}