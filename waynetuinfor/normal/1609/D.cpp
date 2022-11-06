#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, D;
  cin >> N >> D;
  vector<int> x(D), y(D);
  for (int i = 0; i < D; ++i) {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  vector<int> uf(N), ed(N), sz(N, 1);
  iota(uf.begin(), uf.end(), 0);

  function<int(int)> Find = [&](int x) {
    if (x == uf[x]) return x;
    return uf[x] = Find(uf[x]);
  };

  auto Merge = [&](int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) return;
    uf[x] = y;
    sz[y] += sz[x];
    ed[y] += ed[x];
  };

  for (int i = 0; i < D; ++i) {
    Merge(x[i], y[i]);
    ed[Find(x[i])]++;
    vector<int> degs;
    int more = 0;
    for (int j = 0; j < N; ++j) {
      if (Find(j) == j) {
        if (ed[j] > sz[j] - 1) more += ed[j] - sz[j] + 1;
        degs.push_back(sz[j]);
      }
    }
    sort(degs.rbegin(), degs.rend());
    int ans = 0;
    for (int j = 0; j < min<int>(degs.size(), more + 1); ++j) {
      ans += degs[j];
    }
    cout << ans - 1 << "\n";
  }
}