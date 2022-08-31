/**
 *    author:  tourist
 *    created: 01.06.2019 18:25:29       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<tuple<int, int, int>> ret;
  vector<pair<int, int>> st;
  for (int i = 0; i < n; i++) {
    int diff = b[i] - a[i].first;
    if (diff > 0) {
      st.emplace_back(a[i].second, diff);
    }
    while (diff < 0) {
      if (st.empty()) {
        cout << "NO" << "\n";
        return 0;
      }
      int take = min(-diff, st.back().second);
      ret.emplace_back(st.back().first, a[i].second, take);
      diff += take;
      st.back().second -= take;
      if (st.back().second == 0) {
        st.pop_back();
      }
    }
  }
  if (!st.empty()) {
    cout << "NO" << '\n';
    return 0;
  }
  cout << "YES" << '\n';
  cout << ret.size() << '\n';
  for (auto& p : ret) {
    cout << get<0>(p) + 1 << " " << get<1>(p) + 1 << " " << get<2>(p) << '\n';
  }
  return 0;
}