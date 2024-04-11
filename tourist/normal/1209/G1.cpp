/**
 *    author:  tourist
 *    created: 14.09.2019 16:29:37       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, tt;
  cin >> n >> tt;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  const int MAX = 200010;
  vector<int> first(MAX, -1), last(MAX, -1), cnt(MAX, 0);
  for (int i = 0; i < n; i++) {
    if (first[a[i]] == -1) {
      first[a[i]] = i;
    }
    last[a[i]] = i;
    ++cnt[a[i]];
  }
  vector<pair<int, int>> e;
  for (int i = 0; i < MAX; i++) {
    if (first[i] != -1) {
      e.emplace_back(first[i], i);
    }
  }
  sort(e.begin(), e.end());
  int ans = 0;
  int ls = -1;
  int cmax = 0;
  for (int i = 0; i < (int) e.size(); i++) {
    int id = e[i].second;
    if (first[id] > ls) {
      ans += cmax;
      cmax = cnt[id];
      ls = last[id];
    } else {
      cmax = max(cmax, cnt[id]);
      ls = max(ls, last[id]);
    }
  }
  ans += cmax;
  cout << n - ans << '\n';
  return 0;
}