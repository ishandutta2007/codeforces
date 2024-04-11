#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
constexpr long long kInf = 1000000000000000LL;
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
struct Node {
  int ls, rs, p;
} t[10000001];
int n, pre[100001], dp[100001], tot = 1;
long long d, a[100001];
int Max(int x, int y) { return dp[x] > dp[y] ? x : y; }
void Pushup(int x) { t[x].p = Max(t[t[x].ls].p, t[t[x].rs].p); }
void Modify(long long l, long long r, long long p, int v, int x) {
  if (l == r) {
    t[x].p = v;
    return;
  }
  long long mid = (l + r) >> 1;
  if (p <= mid) {
    if (!t[x].ls) t[x].ls = ++tot;
    Modify(l, mid, p, v, t[x].ls);
  } else {
    if (!t[x].rs) t[x].rs = ++tot;
    Modify(mid + 1, r, p, v, t[x].rs);
  }
  Pushup(x);
}
int Query(long long L, long long R, long long l, long long r, int x) {
  if (L > R || !x) return 0;
  if (L <= l && r <= R) return t[x].p;
  long long mid = (l + r) >> 1;
  if (R <= mid) return Query(L, R, l, mid, t[x].ls);
  if (L > mid) return Query(L, R, mid + 1, r, t[x].rs);
  return Max(Query(L, R, l, mid, t[x].ls), Query(L, R, mid + 1, r, t[x].rs));
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> d;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++) {
    pre[i] =
        Max(Query(1, a[i] - d, 1, kInf, 1), Query(a[i] + d, kInf, 1, kInf, 1));
    dp[i] = dp[pre[i]] + 1;
    Modify(1, kInf, a[i], i, 1);
  }
  int pos = std::max_element(dp + 1, dp + n + 1) - dp;
  std::cout << dp[pos] << '\n';
  std::vector<int> ans;
  while (pos) ans.emplace_back(pos), pos = pre[pos];
  std::reverse(ans.begin(), ans.end());
  for (auto &&i : ans) std::cout << i << ' ';
  return 0;
}