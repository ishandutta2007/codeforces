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
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, ed[10000001];
std::string s[751];
class AhoCorasickAutomaton {
 public:
  struct Node {
    int ch[2], fail;
  } t_[10000001];
  AhoCorasickAutomaton() {}
  void Insert(const std::string &s, int id) {
    int now = 0;
    for (std::size_t i = 0; i < s.size(); i++) {
      int id = s[i] - 'a';
      if (!t_[now].ch[id]) t_[now].ch[id] = ++tot_;
      now = t_[now].ch[id];
    }
    ed[now] = id;
  }
  void Build() {
    std::queue<int> q;
    for (int i = 0; i < 2; i++)
      if (t_[0].ch[i]) q.emplace(t_[0].ch[i]);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (!ed[u]) ed[u] = ed[t_[u].fail];
      for (int i = 0; i < 2; i++)
        if (t_[u].ch[i])
          t_[t_[u].ch[i]].fail = t_[t_[u].fail].ch[i], q.emplace(t_[u].ch[i]);
        else
          t_[u].ch[i] = t_[t_[u].fail].ch[i];
    }
  }
  ~AhoCorasickAutomaton() {}

 private:
  int tot_;
} T;
int match[751], vis[751], cur;
bool e[751][751];
void Init(int x) {
  int now = 0;
  for (std::size_t i = 0; i < s[x].size(); i++) {
    int id = s[x][i] - 'a';
    now = T.t_[now].ch[id];
    if (ed[now] != x) e[x][ed[now]] = true;
  }
  e[x][ed[T.t_[now].fail]] = true;
}
bool Dfs(int u) {
  for (int v = 1; v <= n; v++)
    if (e[u][v] && vis[v] != cur) {
      vis[v] = cur;
      if (!match[v] || Dfs(match[v])) {
        match[v] = u;
        return true;
      }
    }
  return false;
}
bool ism[751], vl[751], vr[751];
void Dfs2(int u) {
  vl[u] = true;
  for (int v = 1; v <= n; v++)
    if (e[u][v] && match[v] != u && !vr[v]) {
      vr[v] = true;
      if (match[v]) Dfs2(match[v]);
    }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> s[i], T.Insert(s[i], i);
  T.Build();
  for (int i = 1; i <= n; i++) Init(i);
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (e[i][k] && e[k][j]) e[i][j] = true;
  int ans = n;
  for (cur = 1; cur <= n; cur++) ans -= Dfs(cur);
  std::cout << ans << '\n';
  for (int i = 1; i <= n; i++) ism[match[i]] = true;
  for (int i = 1; i <= n; i++)
    if (!ism[i]) Dfs2(i);
  for (int i = 1; i <= n; i++)
    if (vl[i] && !vr[i]) std::cout << i << ' ';
  return 0;
}