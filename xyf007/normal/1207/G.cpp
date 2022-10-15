#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, ch[800001][26], tot, pos[400001], ans[400001], fail[800001],
    dfn[800001], sz[800001], cnt;
char s[10];
std::vector<std::pair<int, int>> b[800001];
std::vector<int> g[800001], son[800001];
template <typename T = int>
class FenwickTree {
 public:
  FenwickTree(int n = 200000) : n_(n) { Clear(); }
  void Init(int n) { n_ = n, Clear(); }
  void Add(int x, const T &v) {
    while (x <= n_) t_[x] += v, x += x & -x;
  }
  T Query(int x) {
    T s(0);
    while (x) s += t_[x], x -= x & -x;
    return s;
  }
  void Clear() { std::memset(t_ + 1, 0, sizeof(T) * n_); }
  ~FenwickTree() {}

 private:
  int n_;
  T t_[800001];
};
void Build() {
  std::queue<int> q;
  for (int i = 0; i < 26; i++)
    if (ch[0][i]) q.emplace(ch[0][i]), son[0].push_back(ch[0][i]);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < 26; i++)
      if (ch[u][i]) {
        son[u].push_back(ch[u][i]);
        fail[ch[u][i]] = ch[fail[u]][i], q.emplace(ch[u][i]);
      } else {
        ch[u][i] = ch[fail[u]][i];
      }
  }
  for (int i = 1; i <= tot; i++) g[fail[i]].push_back(i);
}
void Dfs(int u) {
  dfn[u] = ++cnt, sz[u] = 1;
  for (const auto &v : g[u]) Dfs(v), sz[u] += sz[v];
}
FenwickTree bit;
void Dfs2(int u) {
  bit.Add(dfn[u], 1);
  for (const auto &[x, id] : b[u])
    ans[id] = bit.Query(dfn[x] + sz[x] - 1) - bit.Query(dfn[x] - 1);
  for (const auto &v : son[u]) Dfs2(v);
  bit.Add(dfn[u], -1);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int op, x = 0;
    char c;
    std::cin >> op;
    if (op == 2) std::cin >> x;
    std::cin >> s;
    x = pos[x], c = s[0];
    if (!ch[x][c - 'a']) ch[x][c - 'a'] = ++tot;
    pos[i] = ch[x][c - 'a'];
  }
  std::cin >> m;
  std::string t;
  for (int i = 1; i <= m; i++) {
    int x;
    std::cin >> x >> t;
    int now = 0;
    for (std::size_t j = 0; j < t.size(); j++) {
      if (!ch[now][t[j] - 'a']) ch[now][t[j] - 'a'] = ++tot;
      now = ch[now][t[j] - 'a'];
    }
    b[pos[x]].emplace_back(now, i);
  }
  Build();
  Dfs(0);
  bit.Init(tot + 1);
  Dfs2(0);
  for (int i = 1; i <= m; i++) std::cout << ans[i] << '\n';
  return 0;
}