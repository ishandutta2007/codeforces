#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> L(n, -1);
  vector<map<int, int>> mp(n);
  mp[0][a[0]] = 0;
  for (int i = 1; i < n; i++) {
    mp[i][a[i]] = 0;
    for (auto it : mp[i - 1]) {
      int ng = __gcd(it.first, a[i]);
      mp[i][ng] = max(mp[i][ng], it.second + 1);
    }
  }
  for (int i = 0; i < n; i++) {
    vector<pair<int, int>> vec;
    for (auto it : mp[i]) {
      vec.emplace_back(it.first, it.second + 1);
    }
    reverse(vec.begin(), vec.end());
    vector<tuple<int, int, int>> segs;
    int curr = 1;
    for (int j = 0; j < vec.size(); j++) {
      segs.emplace_back(vec[j].first, vec[j].second, curr);
      curr = vec[j].second + 1;
    }
    for (int j = 0; j < segs.size(); j++) {
      int g = get<0>(segs[j]);
      int l = get<2>(segs[j]);
      int r = get<1>(segs[j]);
      if (l <= g && g <= r) {
        L[i] = max(L[i], i - g + 1);
      }
    }
  }
  for (int i = 1; i < n; i++) {
    L[i] = max(L[i], L[i - 1]);
  }
  vector<int> dp(n);
  for (int i = 0; i < n; i++) {
    if (L[i] == -1) {
      dp[i] = 0;
    } else {
      dp[i] = (L[i] <= 0 ? 0 : dp[L[i] - 1]) + 1;
    }
    cout << dp[i] << " ";
  }
  return 0;
}