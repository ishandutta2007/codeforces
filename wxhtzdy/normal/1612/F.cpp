#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int q;
  cin >> q;
  map<pair<int, int>, bool> is;
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    is[{a, b}] = true;
  }
  vector<vector<pair<int, int>>> vec(n + m + 1);
  vec[0].emplace_back(1, 1);
  function<void(pair<int, int>, int)> Add = [&](pair<int, int> st, int d) {
    if (st.first >= n && st.second >= m) {
      cout << d - 1 << '\n';
      exit(0);
    }
    int tot = st.first + st.second + is[{st.first, st.second}];
    vec[d].emplace_back(min(n, tot), st.second);
    vec[d].emplace_back(st.first, min(m, tot));
  };
  for (int i = 0; i <= n + m; i++) {
    sort(vec[i].begin(), vec[i].end(), [&](pair<int, int> x, pair<int, int> y) {
      return x.first > y.first || (x.first == y.first && x.second > y.second);
    });
    Add(vec[i][0], i + 1);
    sort(vec[i].begin(), vec[i].end(), [&](pair<int, int> x, pair<int, int> y) {
      return x.second > y.second || (x.second == y.second && x.first > y.first);
    });
    Add(vec[i][0], i + 1);
  }
  return 0;
}