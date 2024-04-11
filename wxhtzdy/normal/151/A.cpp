#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int x = (k * l) / nl;
  int y = c * d;
  int z = p / np;
  cout << (int) (min({x, y, z}) / n) << '\n';
  return 0;
}