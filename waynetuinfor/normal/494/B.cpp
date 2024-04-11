#include <bits/stdc++.h>
using namespace std;

namespace kmp {

template <class String>
vector<size_t> Failure(const String &s) {
    vector<size_t> f(s.size(), 0);
    size_t k = 0;
    for (size_t i = 1; i < s.size(); ++i) {
        while (k > 0 && s[i] != s[k]) k = f[k - 1];
        if (s[i] == s[k]) k++;
        f[i] = k;
    }
    return f;
}

template <class String>
vector<size_t> Search(const String &s, const String &t) {
    auto f = Failure(t);
    vector<size_t> res;
    for (size_t i = 0, k = 0; i < s.size(); ++i) {
        while (k > 0 && (k == t.size() || s[i] != t[k])) k = f[k - 1];
        if (s[i] == t[k]) k++;
        if (k == t.size()) res.push_back(i - t.size() + 1);
    }
    return res;
}

}  // namespace kmp

int main() {
  string s, t;
  cin >> s >> t;
  auto res = kmp::Search(s, t);
  if (res.empty()) {
    cout << "0\n";
    return 0;
  }
  const int n = s.size();
  constexpr int kMod = 1'000'000'000 + 7;
  vector<vector<int>> dp(n + 1, vector<int>(2));
  vector<vector<int>> sum(n + 1, vector<int>(2));
  dp[0][0] = 1;
  sum[0][0] = 1;
  for (int i = 1, j = 0; i <= n; ++i) {
    while (j < res.size() && res[j] + t.size() <= i) j++;
    dp[i][0] = dp[i - 1][0];
    dp[i][1] = dp[i - 1][1];
    if (j > 0) {
      int pv = res[j - 1];
      (dp[i][1] += sum[pv][0]) >= kMod ? dp[i][1] -= kMod : 0;
      (dp[i][1] += sum[pv][1]) >= kMod ? dp[i][1] -= kMod : 0;
    }
    sum[i][0] = (sum[i - 1][0] + dp[i][0]) % kMod;
    sum[i][1] = (sum[i - 1][1] + dp[i][1]) % kMod;
  }
  cout << dp[n][1] << "\n";
}