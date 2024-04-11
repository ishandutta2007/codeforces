#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <algorithm>
#include <iostream>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
struct Edge {
  int to, nxt;
} e[1000001];
int n, E, head[1000001], a[100001];
long long w[1000001];
std::string s[100001];
void Add(int f, int t) { e[E] = {t, head[f]}, head[f] = E++; }
class GeneralSuffixAutomaton {
 public:
  GeneralSuffixAutomaton() { t_[0].link = -1; }
  void Insert(const std::string &s, int v) {
    for (const auto &c : s) Expand(c, v);
    last_ = 0;
  }
  void Build() {
    std::fill(head, head + sz_ + 1, -1);
    for (int i = 1; i <= sz_; i++) Add(t_[i].link, i);
  }
  int len(int x) const { return t_[x].len; }
  ~GeneralSuffixAutomaton() {}

 private:
  struct Node {
    int len, link, nxt[26];
  } t_[1000001];
  int sz_, last_;
  void Expand(char c, int v) {
    int p = last_;
    if (t_[p].nxt[c - 'a']) {
      int q = t_[p].nxt[c - 'a'];
      if (t_[q].len == t_[p].len + 1) {
        w[last_ = q] += v;
      } else {
        int nq = ++sz_;
        t_[nq].len = t_[p].len + 1, t_[nq].link = t_[q].link;
        std::copy(t_[q].nxt, t_[q].nxt + 26, t_[nq].nxt);
        while (p != -1 && t_[p].nxt[c - 'a'] == q)
          t_[p].nxt[c - 'a'] = nq, p = t_[p].link;
        t_[q].link = nq;
        w[last_ = nq] += v;
      }
      return;
    }
    int cur = ++sz_;
    t_[cur].len = t_[last_].len + 1, w[cur] += v;
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
} gsam;
long long ans;
void Dfs(int u) {
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    Dfs(v), w[u] += w[v];
  }
  checkmax(ans, w[u] * gsam.len(u));
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> s[i];
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++) gsam.Insert(s[i], a[i]);
  gsam.Build();
  Dfs(0);
  std::cout << ans;
  return 0;
}