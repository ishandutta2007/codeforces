#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 1;

int pre_min[N], pre_max[N], suf_min[N], suf_max[N], sum[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    string s;
    cin >> n >> m >> s;

    for (int i = 0; i < n; ++i) {
      sum[i + 1] = sum[i] + (s[i] == '-' ? -1 : 1);
    }

    pre_min[0] = pre_max[0] = 0;
    for (int i = 1; i <= n; ++i) {
      pre_min[i] = min(pre_min[i - 1], sum[i]);
      pre_max[i] = max(pre_max[i - 1], sum[i]);
    }

    suf_min[n] = suf_max[n] = sum[n];
    for (int i = n - 1; i > 0; --i) {
      suf_min[i] = min(suf_min[i + 1], sum[i]);
      suf_max[i] = max(suf_max[i + 1], sum[i]);
    }

    while (m--) {
      int l, r;
      cin >> l >> r;

      int a = min(pre_min[l - 1], sum[l - 1] + suf_min[r] - sum[r]);
      int b = max(pre_max[l - 1], sum[l - 1] + suf_max[r] - sum[r]);

      cout << b - a + 1 << "\n";
    }
  }
}