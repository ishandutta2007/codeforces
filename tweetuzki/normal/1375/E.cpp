#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

const int MaxN = 1000;

int N;
int A[MaxN + 5];
std::pair<int, int> B[MaxN + 5];

void init() {
  scanf("%d", &N);
  static std::pair<int, int> d[MaxN + 5];
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &A[i]);
    d[i] = std::make_pair(A[i], i);
  }
  std::sort(d + 1, d + 1 + N);
  for (int i = 1; i <= N; ++i)
    A[d[i].second] = i;
}

void solve() {
  static std::vector< std::pair<int, int> > ans;
  for (int i = 1; i <= N; ++i) B[i] = std::make_pair(A[i], i);
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j < N; ++j)
      if (B[j].first > B[j + 1].first) {
        ans.emplace_back(std::min(B[j].second, B[j + 1].second), std::max(B[j].second, B[j + 1].second));
        std::swap(B[j], B[j + 1]);
      }
  std::reverse(ans.begin(), ans.end());
  printf("%d\n", (int) ans.size());
  for (auto p : ans) printf("%d %d\n", p.first, p.second);
}

int main() {
  init();
  solve();
  return 0;
}