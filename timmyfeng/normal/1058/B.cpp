#include <bits/stdc++.h>
using namespace std;

int dist(int x1, int y1, int x2, int y2) {
  return abs(x2 - x1) + abs(y2 - y1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, d, m;
  cin >> n >> d >> m;

  while (m--) {
    int x, y;
    cin >> x >> y;
    cout << (min(dist(x, y, 0, 0), dist(x, y, n, n)) < d || min(dist(x, y, 0, n), dist(x, y, n, 0)) < n - d ? "NO" : "YES") << "\n";
  }
}