#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<int> k(n);
    for (auto &i : k) {
      cin >> i;
      --i;
    }
    sort(k.begin(), k.end());

    vector<int> c(m);
    for (auto &i : c) {
      cin >> i;
    }

    vector<long long> sum_k(n + 1);
    for (int i = 0; i < n; ++i) {
      sum_k[i + 1] = sum_k[i] + c[k[i]];
    }

    for (int i = 0; i < n; ++i) {
      k[i] -= i;
    }

    vector<long long> sum_c(m + 1);
    for (int i = 0; i < m; ++i) {
      sum_c[i + 1] = sum_c[i] + c[i];
    }

    int mini = INT_MAX;
    long long ans = LLONG_MAX;
    for (int i = n; i >= 0 && n - i <= m; --i) {
      if (i < n) {
        mini = min(mini, k[i]);
        if (mini + i < 0) {
          break;
        }
      }
      ans = min(ans, sum_k[i] + sum_c[n - i]);
    }

    cout << ans << "\n";
  }
}