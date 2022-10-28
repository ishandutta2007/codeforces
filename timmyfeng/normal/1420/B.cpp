#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      ++cnt[__builtin_clz(a)];
    }

    long long ans = 0;
    for (auto [a, b] : cnt) {
      ans += (long long) b * (b - 1) / 2;
    }
    cout << ans << "\n";
  }
}