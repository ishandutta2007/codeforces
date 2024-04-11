#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  int n;
  cin >> n;
  vector<int> x(100);
  vector<int> y(100);
  vector<tuple<string, int, int>> ans;
  for (int i = 0; i < n; i++) {
    int t, id;
    char ch, card;
    cin >> t >> ch >> id >> card;
    if (ch == 'h') {
      if (x[id] < 2 && (x[id] == 1 || card == 'r')) {
        x[id] = 2;
        ans.emplace_back(a, id, t);
      } else {
        if (x[id] == 0 && card == 'y') {
          x[id] = 1;
        }
      }
    } else {
      if (y[id] < 2 && (y[id] == 1 || card == 'r')) {
        y[id] = 2;
        ans.emplace_back(b, id, t);
      } else {
        if (y[id] == 0 && card == 'y') {
          y[id] = 1;
        }
      }
    }
  }
  sort(ans.begin(), ans.end(), [&](tuple<string, int, int> x, tuple<string, int, int> y) {
    return get<2>(x) < get<2>(y);
  });
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i]) << '\n';
  }
  return 0;
}