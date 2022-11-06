#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>
#include <array>
#include <numeric>
#include <memory>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

int w[100000];
int order[100000];

void solve() {
  int n;
  scanf("%d", &n);
  int64_t ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &w[i]);
    ans += w[i];
    order[i] = 0;
  }
  int u, v;
  for (int i = 0; i < n - 1; ++i) {
    scanf("%d %d", &u, &v);
    order[u - 1]++;
    order[v - 1]++;
  }
  vector<pair<int, int>> vs;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < order[i] - 1; ++j) {
      vs.push_back({w[i], i});
    }
  }
  sort(vs.begin(), vs.end());
  printf("%lld", ans);
  for (int i = 0; i < n - 2; ++i) {
    ans += vs[n - 3 - i].first;
    printf(" %lld", ans);
  }
  printf("\n");
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
}