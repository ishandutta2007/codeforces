#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; scanf("%d", &n);
  vector<int> d(n);
  for (int i = 0; i < n; ++i) scanf("%d", &d[i]);
  vector<int> od(n);
  iota(od.begin(), od.end(), 0);
  sort(od.begin(), od.end(), [&](int i, int j) { return d[i] > d[j]; });
  vector<int> dep(2 * n), fa(2 * n, -1), wh(2 * n, -1);
  for (int i = 0; i < n; ++i) {
    dep[od[i] * 2] = i;
    if (i > 0) fa[od[i] * 2] = od[i - 1] * 2;
    wh[dep[od[i] * 2]] = od[i] * 2;
  }
  for (int i = 0; i < n; ++i) {
    int g = dep[od[i] * 2] + d[od[i]] - 1;
    assert(wh[g] != -1);
    fa[od[i] * 2 + 1] = wh[g];
    if (wh[g + 1] == -1) wh[g + 1] = od[i] * 2 + 1;
  }
  for (int i = 0; i < 2 * n; ++i) {
    if (fa[i] >= 0) printf("%d %d\n", i + 1, fa[i] + 1);
  }
}