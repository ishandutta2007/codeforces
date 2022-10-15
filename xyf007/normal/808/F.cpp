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
constexpr int kInf = 0x3f3f3f3f;
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
template <typename T, template <typename...> class Container_t>
std::ostream &operator<<(std::ostream &out, const Container_t<T> &v) {
  for (auto &&x : v) out << x << ' ';
  return out;
}
struct Card {
  int p, c;
  Card(int p = 0, int c = 0) : p(p), c(c) {}
};
int n, k;
std::vector<Card> v[101], avail;
bool np[200001];
void Init(int n) {
  np[1] = true;
  for (int i = 2; i <= n; i++)
    if (!np[i])
      for (int j = i + i; j <= n; j += i) np[j] = true;
}
namespace mincut {
struct Edge {
  int to, nxt, cost;
} e[200001];
int s, t, E, head[1001], dep[1001], cur[1001];
void Add(int f, int t, int c) { e[E] = {t, head[f], c}, head[f] = E++; }
void Build() {
  E = 0, std::memset(head, -1, 4 * (t + 1));
  std::vector<Card> odd, even;
  for (auto &&[p, c] : avail) (c & 1 ? odd : even).emplace_back(p, c);
  int n = odd.size(), m = even.size();
  for (int i = 1; i <= n; i++) Add(s, i, odd[i - 1].p), Add(i, s, 0);
  for (int i = 1; i <= m; i++) Add(n + i, t, even[i - 1].p), Add(t, n + i, 0);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!np[odd[i - 1].c + even[j - 1].c])
        Add(i, n + j, kInf), Add(n + j, i, 0);
}
bool Bfs() {
  std::memset(dep + 1, 0x3f, 4 * t);
  std::memcpy(cur, head, 4 * (t + 1));
  std::queue<int> q;
  q.emplace(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i != -1; i = e[i].nxt) {
      if (!e[i].cost) continue;
      int v = e[i].to;
      if (dep[u] + 1 < dep[v]) dep[v] = dep[u] + 1, q.emplace(v);
    }
  }
  return dep[t] != 0x3f3f3f3f;
}
int Dfs(int u, int sum) {
  if (u == t || !sum) return sum;
  int ans = 0;
  for (int i = cur[u]; i != -1; i = e[i].nxt) {
    if (!e[i].cost) continue;
    int v = e[i].to;
    if (dep[v] == dep[u] + 1) {
      int min = Dfs(v, std::min(sum, e[i].cost));
      if (min) {
        e[i].cost -= min, e[i ^ 1].cost += min;
        ans += min, sum -= min;
        if (!sum) break;
      }
    }
    cur[u] = e[i].nxt;
  }
  if (!ans) dep[u] = -1;
  return ans;
}
int MinCut() {
  int ans = 0;
  while (Bfs()) ans += Dfs(s, kInf);
  return ans;
}
}  // namespace mincut
void Solve(int x) {
  for (auto &&card : v[x])
    if (card.c == 1) {
      bool f = false;
      for (auto &&[p, c] : avail)
        if (c == 1) {
          checkmax(p, card.p);
          f = true;
          break;
        }
      if (!f) avail.push_back(card);
    } else {
      avail.push_back(card);
    }
  mincut::t = avail.size() + 1;
  mincut::Build();
  int sum = 0;
  for (auto &&card : avail) sum += card.p;
  if (sum - mincut::MinCut() >= k) {
    std::cout << x;
    std::exit(0);
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  Init(200000);
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int p, c, l;
    std::cin >> p >> c >> l;
    v[l].emplace_back(p, c);
  }
  avail.reserve(n);
  for (int i = 1; i <= n; i++) Solve(i);
  std::cout << -1;
  return 0;
}