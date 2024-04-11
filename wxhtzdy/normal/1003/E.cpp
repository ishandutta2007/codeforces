#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, d, k;
  cin >> n >> d >> k;
  if (d >= n) {
    cout << "NO" << '\n';
    return 0;
  }
  vector<pair<int, int>> ans;
  vector<int> cnt(n, 0);
  for (int i = 0; i < d; i++) {
    cnt[i] += 1;
    cnt[i + 1] += 1;
    ans.emplace_back(i, i + 1);
  }
  for (int i = 0; i < n; i++) {
    if (cnt[i] > k) {
      cout << "NO" << '\n';
      return 0;
    }
  }
  multiset<pair<int, int>> s;
  for (int i = 1; i < d; i++) {
    if (cnt[i] == k) {
      continue;
    }
    int dist = i;
    dist = max(dist, d - i);
    s.insert({dist, i});
  }
  for (int i = d + 1; i < n; i++) {
    while ((int) s.size() > 0 && cnt[s.begin() -> second] >= k) {
      s.erase(s.begin());
    }
    if ((int) s.size() == 0 || s.begin() -> first == d) {
      cout << "NO" << '\n';
      return 0;
    }
    auto it = s.begin();
    auto val = *it;
    cnt[i] += 1;
    cnt[val.second] += 1;
    ans.emplace_back(i, val.second);
    s.insert({val.first + 1, i});
  }
  cout << "YES" << '\n';
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
  }
  return 0;
}