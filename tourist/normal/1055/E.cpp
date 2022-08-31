/**
 *    author:  tourist
 *    created: 10.11.2018 17:58:59       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, s, m, k;
  cin >> n >> s >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<int,int>> seg(s);
  for (int i = 0; i < s; i++) {
    cin >> seg[i].first >> seg[i].second;
    seg[i].first--;
    seg[i].second--;
  }
  sort(seg.begin(), seg.end());
  for (int i = 1; i < (int) seg.size(); i++) {
    if (seg[i].second <= seg[i - 1].second) {
      seg.erase(seg.begin() + i);
      i--;
    }
  }
  s = (int) seg.size();
  m = min(m, s);
  const int inf = (int) 1.01e9;
  int low = 0, high = inf;
  while (low < high) {
    int mid = (low + high) >> 1;
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + (a[i] <= mid);
    }
    vector<int> dp(s), new_dp(s);
    vector<int> value(s);
    vector<int> que;
    for (int take = 1; take <= m; take++) {
      int j = 0;
      int before = 0;
      que.clear();
      int ptr = 0;
      for (int i = 0; i < s; i++) {
        while (j < i && seg[j].second < seg[i].first) {
          before = max(before, dp[j]);
          if (ptr < (int) que.size() && que[ptr] == j) {
            ptr++;
          }
          j++;
        }
        new_dp[i] = before + pref[seg[i].second + 1] - pref[seg[i].first];
        if (ptr < (int) que.size()) {
          new_dp[i] = max(new_dp[i], value[que[ptr]] + pref[seg[i].second + 1]);
        }
        value[i] = dp[i] - pref[seg[i].second + 1];
        while ((int) que.size() > ptr && value[i] >= value[que.back()]) {
          que.pop_back();
        }
        que.push_back(i);
      }
      swap(dp, new_dp);
    }
    int cur = *max_element(dp.begin(), dp.end());
    if (cur >= k) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << (low == inf ? -1 : low) << '\n';
  return 0;
}