#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  cout << (n - 1) / m * 2 + min(2, (n - 1) % m) << "\n";

  for (int i = 2; i <= n; ++i) {
    cout << i << " " << max(1, i - m) << "\n";
  }
}