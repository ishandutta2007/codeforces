#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>

const int MaxN = 1000000 + 5;

int N, K, L;
int A[MaxN];
std::pair<int, int> F[MaxN];

void init() {
  scanf("%d %d %d", &N, &K, &L);
  static char s[MaxN];
  scanf("%s", s + 1);
  for (int i = 1; i <= N; ++i)
    if (s[i] >= 'a' && s[i] <= 'z') A[i] = 1;
}

inline bool check(int mid) {
  F[0] = std::make_pair(0, 0);
  for (int i = 1; i <= N; ++i) {
    F[i] = F[i - 1];
    F[i].first += A[i];
    std::pair<int, int> p = F[std::max(0, i - L)];
    p.first += mid, p.second++;
    F[i] = std::min(F[i], p);
  }
  if (F[N].second <= K) return true;
  else return false;
}

int getMin() {
  int lbound = 0, rbound = N + 1, ans = 0;
  while (lbound <= rbound) {
    int mid = (lbound + rbound) >> 1;
    if (check(mid) == false) {
      ans = mid + 1;
      lbound = mid + 1;
    } else rbound = mid - 1;
  }
  check(ans);
  return F[N].first - ans * K;
}

void solve() {
  int res = getMin();
  for (int i = 1; i <= N; ++i) A[i] ^= 1;
  res = std::min(res, getMin());
  printf("%d\n", res);
}

int main() {
  init();
  solve();
  return 0;
}