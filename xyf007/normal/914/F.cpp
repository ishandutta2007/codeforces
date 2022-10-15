#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, q, B = 170, tot, pos[100001], L[601], R[601], nxt[100001];
char s[100005], t[100005];
bool vis[601];
class SuffixAutomaton {
 private:
  struct Node {
    int len, link, nxt[26];
  } t_[350];
  int sz_, last_, cnt_[350];
  std::vector<int> g_[350];

 public:
  SuffixAutomaton() { t_[0].link = -1; }
  void Clear() {
    for (int i = 0; i <= sz_; i++)
      t_[i].len = t_[i].link = 0, std::memset(t_[i].nxt, 0, sizeof(t_[i].nxt));
    std::memset(cnt_, 0, 4 * (sz_ + 1));
    for (int i = 0; i <= sz_; i++) g_[i].clear();
    sz_ = last_ = 0, t_[0].link = -1;
  }
  void Expand(char c) {
    int cur = ++sz_, p = last_;
    t_[cur].len = t_[last_].len + 1, cnt_[cur] = 1;
    while (p != -1 && !t_[p].nxt[c - 'a'])
      t_[p].nxt[c - 'a'] = cur, p = t_[p].link;
    if (p == -1) {
      t_[cur].link = 0;
    } else {
      int q = t_[p].nxt[c - 'a'];
      if (t_[q].len == t_[p].len + 1) {
        t_[cur].link = q;
      } else {
        int nq = ++sz_;
        t_[nq].len = t_[p].len + 1, t_[nq].link = t_[q].link;
        std::copy(t_[q].nxt, t_[q].nxt + 26, t_[nq].nxt);
        while (p != -1 && t_[p].nxt[c - 'a'] == q)
          t_[p].nxt[c - 'a'] = nq, p = t_[p].link;
        t_[cur].link = t_[q].link = nq;
      }
    }
    last_ = cur;
  }
  void Build() {
    for (int i = 1; i <= sz_; i++) g_[t_[i].link].push_back(i);
  }
  void Dfs(int u) {
    for (const auto &v : g_[u]) Dfs(v), cnt_[u] += cnt_[v];
  }
  int Query(const char *s) {
    int n = std::strlen(s), p = 0;
    for (int i = 0; i < n; i++) {
      if (!t_[p].nxt[s[i] - 'a']) return 0;
      p = t_[p].nxt[s[i] - 'a'];
    }
    return cnt_[p];
  }
  ~SuffixAutomaton() {}
} sam[601];
void Rebuild(int x) {
  sam[x].Clear();
  for (int i = L[x]; i <= R[x]; i++) sam[x].Expand(s[i]);
  sam[x].Build(), sam[x].Dfs(0);
}
void Kmp() {
  for (int i = 2, j = 0; i <= m; i++) {
    while (j && t[j + 1] != t[i]) j = nxt[j];
    if (t[j + 1] == t[i]) j++;
    nxt[i] = j;
  }
}
int Query(int l, int r) {
  int pl = pos[l], pr = pos[r], ans = 0;
  if (pl == pr) {
    for (int i = l, j = 0; i <= r; i++) {
      while (j && t[j + 1] != s[i]) j = nxt[j];
      if (t[j + 1] == s[i]) j++;
      if (j == m) ans++, j = nxt[j];
    }
    return ans;
  }
  for (int i = l, j = 0; i <= R[pl]; i++) {
    while (j && t[j + 1] != s[i]) j = nxt[j];
    if (t[j + 1] == s[i]) j++;
    if (j == m) ans++, j = nxt[j];
  }
  for (int i = pl + 1; i < pr; i++) {
    if (vis[i]) Rebuild(i), vis[i] = false;
    ans += sam[i].Query(t + 1);
  }
  for (int i = L[pr], j = 0; i <= r; i++) {
    while (j && t[j + 1] != s[i]) j = nxt[j];
    if (t[j + 1] == s[i]) j++;
    if (j == m) ans++, j = nxt[j];
  }
  for (int i = pl; i < pr; i++) {
    int ql = std::max(l, L[i + 1] - (m - 1)), qr = std::min(R[i] + m - 1, r);
    for (int j = ql, k = 0; j <= qr; j++) {
      while (k && t[k + 1] != s[j]) k = nxt[k];
      if (t[k + 1] == s[j]) k++;
      if (k == m) ans++, k = nxt[k];
    }
  }
  return ans;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> (s + 1), n = std::strlen(s + 1);
  for (int i = 1; i <= n; i++) pos[i] = (i - 1) / B + 1;
  tot = pos[n];
  for (int i = 1; i <= tot; i++) L[i] = R[i - 1] + 1, R[i] = i * B;
  R[tot] = n;
  std::memset(vis + 1, 1, tot);
  std::cin >> q;
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int x;
      char c[10];
      std::cin >> x >> c;
      s[x] = c[0], vis[pos[x]] = true;
    } else {
      int l, r;
      std::cin >> l >> r >> (t + 1), m = std::strlen(t + 1);
      if (m > r - l + 1) {
        std::cout << "0\n";
        continue;
      }
      Kmp();
      if (m > B) {
        int ans = 0;
        for (int i = l, j = 0; i <= r; i++) {
          while (j && t[j + 1] != s[i]) j = nxt[j];
          if (t[j + 1] == s[i]) j++;
          if (j == m) ans++, j = nxt[j];
        }
        std::cout << ans << '\n';
      } else {
        std::cout << Query(l, r) << '\n';
      }
    }
  }
  return 0;
}