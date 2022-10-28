#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    long long x, y, k;
    cin >> x >> y >> k;
    long long total = k * (y + 1);
    cout << (total - 2) / (x - 1) + k + 1 << "\n";
  }
}