#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, v;
  cin >> n >> v;
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    ans += max(0, i - v) + 1;
  }
  cout << ans << "\n";
}