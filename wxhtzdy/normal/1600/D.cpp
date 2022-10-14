/**
 *    author: m371
 *    created: 12.10.2021 16:30:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto Ask = [&](int x, int y) {
    cout << "? " << x << " " << y << endl;
    int foo;
    cin >> foo;
    return foo;  
  };
  const int inf = (int) 1e9;
  int dl = Ask(1, 1);
  int dr = Ask(1, inf);
  int L = 1, R = inf;
  if (dl < dr) {
    R -= (dr - dl);
  } else {
    L += (dl - dr);
  }
  cout << L << " " << R << '\n';
  int mid = (L + R) / 2;
  int dx = Ask(1, mid);
  int dy = Ask(inf, mid);
  cout << "! " << 1 + dx << " " << 1 + dl - dx << " " << inf - dy << " " << inf - (dr - dx) << endl;
  return 0;
}