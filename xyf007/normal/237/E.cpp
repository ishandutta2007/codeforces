#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
struct Edge {
  int to, nxt, cost, flow;
} e[20001];
int n, E, cnt[26], head[201], S, T, dis[201], flow[201], le[201], pre[201];
char s[101], t[201];
bool vis[201];
void Add(int f, int t, int c, int w) {
  e[E].to = t;
  e[E].cost = c;
  e[E].flow = w;
  e[E].nxt = head[f];
  head[f] = E++;
}
bool Spfa() {
  std::memset(dis, 0x3f, sizeof(dis));
  dis[S] = 0;
  pre[T] = -1;
  std::memset(vis, false, sizeof(vis));
  std::memset(flow, 0x3f, sizeof(flow));
  std::queue<int> q;
  q.emplace(S);
  vis[S] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = false;
    for (int i = head[u]; i != -1; i = e[i].nxt) {
      int v = e[i].to;
      if (dis[u] + e[i].cost < dis[v] && e[i].flow) {
        dis[v] = dis[u] + e[i].cost;
        pre[v] = u;
        le[v] = i;
        flow[v] = std::min(flow[u], e[i].flow);
        if (!vis[v]) {
          q.emplace(v);
          vis[v] = true;
        }
      }
    }
  }
  return pre[T] != -1;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::memset(head, -1, sizeof(head));
  std::cin >> s >> n;
  T = n + 27;
  for (size_t i = 0, sz = std::strlen(s); i < sz; i++) {
    cnt[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    Add(n + i + 1, T, 0, cnt[i]);
    Add(T, n + i + 1, 0, 0);
  }
  for (int i = 1; i <= n; i++) {
    int lim;
    std::memset(cnt, 0, sizeof(cnt));
    std::cin >> t >> lim;
    Add(S, i, i, lim);
    Add(i, S, -i, 0);
    for (size_t j = 0, sz = std::strlen(t); j < sz; j++) {
      cnt[t[j] - 'a']++;
    }
    for (int j = 0; j < 26; j++) {
      Add(i, n + j + 1, 0, cnt[j]);
      Add(n + j + 1, i, 0, 0);
    }
  }
  int max = 0, ans = 0;
  while (Spfa()) {
    max += flow[T];
    ans += flow[T] * dis[T];
    int p = T;
    while (p != S) {
      e[le[p]].flow -= flow[T];
      e[le[p] ^ 1].flow += flow[T];
      p = pre[p];
    }
  }
  if (max < (int)std::strlen(s)) {
    std::cout << -1;
  } else {
    std::cout << ans;
  }
  return 0;
}