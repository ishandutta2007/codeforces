#include <bits/stdc++.h>
using namespace std;

const int N = 101;
const int A = 101;

bitset<A * N> dp[N];
int cnt[A];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++cnt[a[i]];
  }

  int ans = 0;
  dp[0][0] = 1;
  for (int i = 1; i < A; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[j].reset();
    }
    for (int j = 1; j <= n; ++j) {
      for (int k = n; k > 0; --k) {
        if (a[j] != i) {
          dp[k] |= dp[k - 1] << a[j];
        }
      }
    }
    int res = 1;
    while (res <= cnt[i] && !dp[res][res * i]) {
      ++res;
    }
    if (res - 1 + ans == n) {
      ans = n;
    } else {
      ans = max(ans, res - 1);
    }
  }
  cout << ans << "\n";
}