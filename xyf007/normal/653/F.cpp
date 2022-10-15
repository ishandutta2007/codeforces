#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = std::getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = std::getchar()) >= '0' && c <= '9') x = x * 10 + (c - '0');
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &... args) {
  Read(x);
  Read(args...);
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, sum[500005], min[20][500005], lg[500005], ed[1000001];
char s[500001];
long long ans;
class SuffixAutomaton {
 public:
  struct Node {
    int len, link, nxt[2];
  } t_[1000001];
  int sz_ = 1, last_ = 1;
  SuffixAutomaton() {}
  void Expand(char c) {
    int cur = ++sz_, p = last_;
    t_[cur].len = t_[p].len + 1;
    while (p && !t_[p].nxt[c - '(']) {
      t_[p].nxt[c - '('] = cur;
      p = t_[p].link;
    }
    if (!p) {
      t_[cur].link = 1;
    } else {
      int q = t_[p].nxt[c - '('];
      if (t_[q].len == t_[p].len + 1) {
        t_[cur].link = q;
      } else {
        int nq = ++sz_;
        t_[nq].len = t_[p].len + 1;
        t_[nq].link = t_[q].link;
        std::memcpy(t_[nq].nxt, t_[q].nxt, sizeof(t_[q].nxt));
        while (p && t_[p].nxt[c - '('] == q) {
          t_[p].nxt[c - '('] = nq;
          p = t_[p].link;
        }
        t_[cur].link = t_[q].link = nq;
      }
    }
    last_ = cur;
  }
  ~SuffixAutomaton() {}
} S;
std::vector<int> v[1000001], g[1000001];
int Query(int l, int r) {
  int len = lg[r - l + 1];
  return std::min(min[len][l], min[len][r - (1 << len) + 1]);
}
void Dfs(int u) {
  for (auto &&v : g[u]) {
    Dfs(v);
    ed[u] = ed[v];
  }
  int l = ed[u] - S.t_[u].len + 1, sr = ed[u] - S.t_[S.t_[u].link].len,
      r = sr + 1, tmp = n + sum[ed[u] + 1];
  while (l < r) {
    int mid = (l + r) >> 1;
    if (Query(mid, ed[u]) >= sum[ed[u] + 1])
      r = mid;
    else
      l = mid + 1;
  }
  ans += std::upper_bound(v[tmp].begin(), v[tmp].end(), sr) -
         std::lower_bound(v[tmp].begin(), v[tmp].end(), r);
}
int main(int argc, char const *argv[]) {
  Read(n);
  std::scanf("%s", s + 1);
  for (int i = n; i >= 1; i--)
    min[0][i] = sum[i] = sum[i + 1] + (s[i] == '(' ? -1 : 1);
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= n + 1; i++) v[n + sum[i]].emplace_back(i);
  for (int i = 1; i <= lg[n]; i++)
    for (int j = 1; j + (1 << i) - 1 <= n; j++)
      min[i][j] = std::min(min[i - 1][j], min[i - 1][j + (1 << (i - 1))]);
  for (int i = 1; i <= n; i++) S.Expand(s[i]);
  for (int i = 1, p = 1; i <= n; i++) ed[p = S.t_[p].nxt[s[i] - '(']] = i;
  for (int i = 2; i <= S.sz_; i++) g[S.t_[i].link].emplace_back(i);
  Dfs(1);
  std::printf("%lld", ans);
  return 0;
}