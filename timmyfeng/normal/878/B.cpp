#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, m;
  cin >> n >> k >> m;

  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
  }

  int64_t ans = 1LL * n * m;
  deque<array<int, 2>> stk;
  for (auto i : a) {
    if (!stk.empty() && stk.back()[0] == i) {
      ++stk.back()[1];
    } else {
      stk.push_back({i, 1});
    }

    if (stk.back()[1] == k) {
      stk.pop_back();
      ans -= 1LL * m * k;
    }
  }

  int cnt = 0;
  while (!stk.empty() && stk[0][0] == stk.back()[0]) {
    if (stk.size() == 1u) {
      int64_t remain = 1LL * m * stk[0][1];
      ans -= remain - remain % k;
      if (remain % k == 0) {
        ans -= cnt * k;
      }
      break;
    }

    if (stk[0][1] + stk.back()[1] >= k) {
      stk[0][1] -= k - stk.back()[1];
      if (stk[0][1] == 0) {
        stk.pop_front();
      }
      stk.pop_back();
      ans -= 1LL * (m - 1) * k;
      ++cnt;
    } else {
      break;
    }
  }
  cout << ans << "\n";
}