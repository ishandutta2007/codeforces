#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    cout << max(n - r, r - 1) + max(m - c, c - 1) << "\n";
  }
}