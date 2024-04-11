#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> s(N);
  vector<int> balance(N), mbalance(N);
  vector<map<int, vector<int>>> vec(N);
  vector<map<int, int>> fi(N);
  for (int i = 0; i < N; ++i) {
    cin >> s[i];
    for (int j = 0; j < s[i].size(); ++j) {
      char c = s[i][j];
      if (c == '(') balance[i]++;
      else balance[i]--;
      mbalance[i] = min(mbalance[i], balance[i]);
      vec[i][balance[i]].push_back(j);
      if (fi[i].find(balance[i]) == fi[i].end()) {
        fi[i][balance[i]] = j;
      }
    }
    for (auto iter = next(fi[i].begin()); iter != fi[i].end(); iter++) {
      iter->second = min(iter->second, prev(iter)->second);
    }
  }
  constexpr int kInf = 1'000'000'000;
  vector<int> dp(1 << N, -kInf);
  int ans = 0;
  dp[0] = 0;
  for (int s = 0; s < (1 << N); ++s) {
    if (dp[s] == -kInf) continue;
    int sb = 0;
    for (int i = 0; i < N; ++i) {
      if (s >> i & 1) {
        sb += balance[i];
      }
    }
    for (int i = 0; i < N; ++i) {
      if (s >> i & 1) continue;
      auto iter = vec[i].lower_bound(-sb);
      int c = 0;
      if (iter != vec[i].begin()) {
        auto piter = prev(fi[i].lower_bound(-sb));
        int p = piter->second;
        if (iter != vec[i].end() && iter->first == -sb) {
          c = lower_bound(iter->second.begin(), iter->second.end(), p) - iter->second.begin();
        }
      } else {
        if (iter != vec[i].end() && iter->first == -sb) {
          c = iter->second.size();
        }
      }
      ans = max(ans, dp[s] + c);
      if (sb + mbalance[i] >= 0) {
        dp[s ^ (1 << i)] = max(dp[s ^ (1 << i)], dp[s] + c);
      }
    }
  }
  cout << ans << "\n";
  return 0;
}