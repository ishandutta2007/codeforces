/**
 *    author:  tourist
 *    created: 20.09.2021 17:36:57       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    int other = a + b + c - max(a, max(b, c));
    int L = a + b + c - 1 - 2 * other;
    int R = a - 1 + b - 1 + c - 1;
    cout << (L <= m && m <= R ? "YES" : "NO") << '\n';
  }
  return 0;
}