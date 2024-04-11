/**
 *    author:  tourist
 *    created: 28.02.2021 17:06:08       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    --c[i];
  }
  vector<pair<int, int>> ret;
  auto Do = [&](int i, int j) {
    ret.emplace_back(i, j);
    swap(c[i], c[j]);
    c[i] = ~c[i];
    c[j] = ~c[j];
  };
  vector<vector<int>> cycles;
  vector<bool> was(n, false);
  for (int i = 0; i < n; i++) {
    if (was[i]) {
      continue;
    }
    vector<int> cyc;
    int p = i;
    while (!was[p]) {
      cyc.push_back(p);
      was[p] = true;
      p = c[p];
    }
    cycles.push_back(cyc);
  }
  while (cycles.size() >= 2) {
    auto c1 = cycles.back();
    cycles.pop_back();
    auto c2 = cycles.back();
    cycles.pop_back();
    for (int i = 0; i < (int) c1.size(); i++) {
      Do(c1[i], c2[0]);
    }
    for (int i = 1; i < (int) c2.size(); i++) {
      Do(c1[0], c2[i]);
    }
    Do(c1[0], c2[0]);
  }
  if (cycles.size() == 1) {
    auto c = cycles.back();
    if (c.size() == 2) {
      int other = (c[0] > 0 ? 0 : (c[1] > 1 ? 1 : 2));
      Do(c[0], other);
      Do(c[1], other);
      Do(c[0], other);
    }
    if (c.size() > 2) {
      Do(c[0], c[1]);
      for (int i = 2; i < (int) c.size(); i++) {
        Do(c[1], c[i]);
      }
      Do(c[0], c[2]);
      Do(c[0], c[1]);
    }
  }
  for (int i = 0; i < n; i++) {
    assert(c[i] == i);
  }
  cout << ret.size() << '\n';
  for (int i = 0; i < (int) ret.size(); i++) {
    cout << ret[i].first + 1 << " " << ret[i].second + 1 << '\n';
  }
  return 0;
}