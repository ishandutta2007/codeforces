#include <bits/stdc++.h>
using namespace std;

const int64_t I = 1e18;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<array<int, 2>> tasks(n);
  for (int i = 0; i < 2; ++i) {
    for (auto& j : tasks) {
      cin >> j[i];
    }
  }
  sort(tasks.rbegin(), tasks.rend());

  vector<int> vals;
  for (auto i : tasks) {
    vals.push_back(i[0]);
  }
  sort(vals.rbegin(), vals.rend());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  int m = vals.size();

  int64_t lo = 0;
  int64_t hi = 1e11;
  while (lo <= hi) {
    int64_t mid = (lo + hi) / 2;

    int ptr = 0;
    vector<int64_t> dp(n + 1, -I);
    dp[0] = 0;

    for (int i = 0; i < m; ++i) {
      int pre = ptr;
      vector<int64_t> pre_sum = {0};
      while (ptr < n && tasks[ptr][0] == vals[i]) {
        pre_sum.push_back(tasks[ptr][1]);
        ++ptr;
      }
      int cnt = ptr - pre;

      for (int j = 1; j <= cnt; ++j) {
        pre_sum[j] += pre_sum[j - 1];
      }

      vector<int64_t> dp_nxt(n + 1, -I);
      for (int j = 0; j <= pre; ++j) {
        for (int k = 0; k <= min(j, cnt); ++k) {
          int used = cnt - k;
          int nxt = j + used - k;
          dp_nxt[nxt] = max(dp_nxt[nxt], dp[j] + mid * pre_sum[used] - 1000LL * used * vals[i]);
        }
      }
      dp = dp_nxt;
    }

    if (*max_element(dp.begin(), dp.end()) >= 0) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo << "\n";
}