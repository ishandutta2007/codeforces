#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;
const int A = 64;

int pre_sum[N];
int a[N];

int cnt[2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    long long b;
    cin >> b;
    a[i] = __builtin_popcountll(b);
    pre_sum[i] = a[i] + pre_sum[i - 1];
  }

  cnt[0] = 1;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += cnt[pre_sum[i] % 2];
    ++cnt[pre_sum[i] % 2];
  }

  for (int i = 1; i <= n; ++i) {
    int max_a = 0;
    for (int j = i; j <= n && j - i + 1 <= A; ++j) {
      max_a = max(max_a, a[j]);
      int sum = pre_sum[j] - pre_sum[i - 1];
      ans -= (sum % 2 == 0 && sum < 2 * max_a);
    }
  }
  cout << ans << "\n";
}