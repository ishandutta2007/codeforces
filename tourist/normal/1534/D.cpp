/**
 *    author:  tourist
 *    created: 13.06.2021 18:43:33       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  set<pair<int, int>> res;
  auto Ask = [&](int v) {
    cout << "? " << v + 1 << endl;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
      cin >> d[i];
      if (d[i] == 1) {
        res.emplace(min(v, i), max(v, i));
      }
    }
    return d;
  };
  auto d = Ask(0);
  vector<int> cnt(2);
  for (int i = 0; i < n; i++) {
    cnt[d[i] % 2] += 1;
  }
  int u = (cnt[0] > cnt[1] ? 1 : 0);
  for (int i = 1; i < n; i++) {
    if (d[i] % 2 == u) {
      Ask(i);
    }
  }
  cout << "!" << endl;
  for (auto& p : res) {
    cout << p.first + 1 << " " << p.second + 1 << endl;
  }
  return 0;
}