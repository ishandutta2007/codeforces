#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000 + 5;
int n, m, k, Max;
vector<pair<int, int>> vec, buy;

bool check(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    int f; cin >> f;
    Max = max(Max, f);
    vec.push_back(make_pair(f, INT_MIN));
  }
  for (int i = 0; i < m; ++i) {
    int s; cin >> s;
    Max = max(Max, s);
    vec.push_back(make_pair(s, -1));
    buy.push_back(make_pair(s, i + 1));
  }
  int ind = 0;
  sort(vec.begin(), vec.end());
  sort(buy.begin(), buy.end());
  for (int i = 0; i < vec.size(); ++i) {
    if (vec[i].second == -1) vec[i].second = ++ind;
  }
  int d = 1, x = 0;
  while (d <= m) d <<= 1;
  while (d >>= 1) if (x + d <= m) if (check(x + d)) x += d;
  if (!check(0)) return cout << "-1\n", 0;
  cout << x << '\n';
  for (int i = buy.size() - 1, j = 0; i >= 0 && j < x; --i, ++j) {
    cout << buy[i].second << ' ';
  }
  cout << '\n';
}

bool check(int x) {
  int buy = 0;
  int ind = 0;
  for (int i = 0; i <= Max; ++i) {
    for (int cnt = 0; cnt < k && ind < vec.size(); ++ind) {
      if (vec[ind].second == INT_MIN && vec[ind].first < i) return false;
      else if (vec[ind].second == INT_MIN) ++cnt;
      else if (vec[ind].second + x > m && vec[ind].first < i) return false;
      else if (vec[ind].second + x > m) ++cnt, ++buy;
    }
  }
  return buy == x;
}