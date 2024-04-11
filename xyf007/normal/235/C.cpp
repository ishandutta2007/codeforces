#include <cstring>
#include <iostream>
struct Edge {
  int to, nxt;
} e[4000001];
int n, cnt[4000001], E, head[4000001];
char s[4000001];
std::string t;
int vis[4000001];
class SuffixAutomaton {
 public:
  struct Node {
    int len, link, nxt[26];
  } t_[4000001];
  int sz_;
  SuffixAutomaton() { t_[0].link = -1; }
  void Expand(char c) {
    int cur = ++sz_, p = last_;
    t_[cur].len = t_[last_].len + 1;
    cnt[cur] = 1;
    while (p != -1 && !t_[p].nxt[c - 'a'])
      t_[p].nxt[c - 'a'] = cur, p = t_[p].link;
    if (p == -1) {
      t_[cur].link = 0;
    } else {
      int q = t_[p].nxt[c - 'a'];
      if (t_[p].len + 1 == t_[q].len) {
        t_[cur].link = q;
      } else {
        int nq = ++sz_;
        t_[nq].len = t_[p].len + 1, t_[nq].link = t_[q].link;
        std::memcpy(t_[nq].nxt, t_[q].nxt, sizeof(t_[nq].nxt));
        while (p != -1 && t_[p].nxt[c - 'a'] == q)
          t_[p].nxt[c - 'a'] = nq, p = t_[p].link;
        t_[cur].link = t_[q].link = nq;
      }
    }
    last_ = cur;
  }
  void Build(const char *s) {
    std::size_t n = std::strlen(s);
    for (std::size_t i = 0; i < n; i++) Expand(s[i]);
  }
  ~SuffixAutomaton() {}

 private:
  int last_;
} sam;
void Add(int f, int t) { e[E] = {t, head[f]}, head[f] = E++; }
void Dfs(int u) {
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    Dfs(v), cnt[u] += cnt[v];
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::memset(head, -1, sizeof(head));
  std::cin >> s >> n;
  sam.Build(s);
  for (int i = 1; i <= sam.sz_; i++) Add(sam.t_[i].link, i);
  Dfs(0);
  for (int i = 1; i <= n; i++) {
    std::cin >> t;
    std::size_t len = t.size(), l = 0;
    t.append(t);
    int p = 0, ans = 0;
    for (std::size_t j = 0; j < t.size() - 1; j++) {
      while (p != -1 && !sam.t_[p].nxt[t[j] - 'a'])
        p = sam.t_[p].link, l = sam.t_[p].len;
      if (sam.t_[p].nxt[t[j] - 'a'])
        l++, p = sam.t_[p].nxt[t[j] - 'a'];
      else
        p = l = 0;
      if (l == len) {
        if (vis[p] != i) ans += cnt[p], vis[p] = i;
        if (sam.t_[p].link != -1 && (int)l == sam.t_[sam.t_[p].link].len + 1)
          p = sam.t_[p].link;
        l--;
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}