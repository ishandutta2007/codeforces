#include <bits/stdc++.h>

using namespace std;

const int md = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    long long ans = 1;
    for (int i = 0; i < k; i++) {
      ans *= n;
      ans %= md;
    }
    cout << ans << '\n';
  }
  return 0;
}