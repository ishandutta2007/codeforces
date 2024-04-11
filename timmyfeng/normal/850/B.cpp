#include <bits/stdc++.h>
using namespace std;

const int A = 1'000'000 + 1;

long long sum[A];
int cnt[A];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  long long x, y;
  cin >> n >> x >> y;

  int mx_a = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ++cnt[a];
    sum[a] += a;
    mx_a = max(mx_a, a);
  }

  if (mx_a == 1) {
    cout << min(x, y) * n << "\n";
    exit(0);
  }

  for (int i = 1; i <= mx_a; ++i) {
    cnt[i] += cnt[i - 1];
    sum[i] += sum[i - 1];
  }

  long long ans = x * n;
  for (int i = 2; i <= mx_a; ++i) {
    long long res = 0;
    int r = min(i, int(x / y) + 1);
    for (int j = 0; j < mx_a; j += i) {
      int k = min(mx_a, j + i - r);
      int l = min(mx_a, j + i);
      res += x * (cnt[k] - cnt[j]);
      res += y * (1LL * (cnt[l] - cnt[k]) * (j + i) - (sum[l] - sum[k]));
    }
    ans = min(ans, res);
  }

  cout << ans << "\n";
}