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
int n, m, k;
bool g[12][12];
std::vector<int> match, col;
std::set<std::vector<int>> s;
long long ans, f[13];
void Init(int now) {
  if (now == n) {
    std::vector<std::vector<int>> p;
    for (int i = 0; i < n; i++)
      if (i < match[i]) p.push_back({i, match[i]});
    bool ok[6][6];
    for (int i = 0; i < n / 2; i++)
      for (int j = 0; j < n / 2; j++) ok[i][j] = false;
    for (int i = 0; i < n / 2; i++) ok[i][i] = g[p[i][0]][p[i][1]];
    for (int i = 0; i < n / 2; i++)
      for (int j = 0; j < n / 2; j++) {
        if (j == i) continue;
        for (int x = 0; x < 2; x++)
          ok[i][j] |= g[p[i][0]][p[j][x]] && g[p[i][1]][p[j][1 - x]];
      }
    std::vector<int> per(n / 2);
    std::iota(per.begin(), per.end(), 0);
    do {
      bool f = ok[per[0]][per[0]];
      for (int i = 0; i + 1 < n / 2 && f; i++)
        if (!ok[per[i]][per[i + 1]]) f = false;
      if (f) {
        s.emplace(match);
        return;
      }
    } while (std::next_permutation(per.begin(), per.end()));
    return;
  }
  if (match[now] != -1) {
    Init(now + 1);
    return;
  }
  for (int i = now + 1; i < n; i++)
    if (match[i] == -1) {
      match[now] = i, match[i] = now;
      Init(now + 1);
      match[now] = match[i] = -1;
    }
}
int nc;
std::vector<int> c[13];
bool Calc(int now) {
  if (now == n) {
    if (s.count(match)) {
      ans += f[nc];
      return true;
    }
    return false;
  }
  if (match[now] != -1) return Calc(now + 1);
  for (auto &&u : c[col[now]]) {
    if (u == now || match[u] != -1) continue;
    match[now] = u, match[u] = now;
    if (Calc(now + 1)) return true;
    match[now] = match[u] = -1;
  }
  return false;
}
void Solve(int now) {
  if (now == n) {
    for (int i = 0; i < nc; i++)
      if (c[i].size() & 1) return;
    std::vector<int>(n, -1).swap(match), Calc(0);
    return;
  }
  int oc = nc;
  for (int i = 0; i < oc + 1; i++) {
    col[now] = i, c[i].emplace_back(now), checkmax(nc, i + 1);
    Solve(now + 1);
    c[i].pop_back();
  }
  nc = oc;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> k;
  f[0] = 1LL;
  for (int i = 1; i <= k; i++) f[i] = f[i - 1] * (k - i + 1);
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v, u--, v--;
    g[u][v] = g[v][u] = true;
  }
  std::vector<int>(n, -1).swap(match), Init(0);
  col.resize(n), Solve(0);
  std::cout << ans;
  return 0;
}