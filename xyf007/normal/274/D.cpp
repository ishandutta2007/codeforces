#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
char Gc() {
  static char now[1 << 20], *S, *T;
  if (T == S) {
    T = (S = now) + std::fread(now, 1, 1 << 20, stdin);
    if (T == S) return EOF;
  }
  return *S++;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Gc()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
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
std::size_t n, m, tot;
std::vector<std::vector<std::pair<int, int>>> a;
std::vector<int> g[200001];
int E, head[200001], ind[200001];
int main(int argc, char const *argv[]) {
  std::memset(head, -1, sizeof(head));
  Read(n, m);
  tot = m;
  a.resize(n);
  for (auto &&v : a) {
    v.resize(m);
    for (std::size_t i = 0; i < m; i++) {
      Read(v[i].first);
      v[i].second = i;
    }
  }
  for (auto &&v : a) {
    std::sort(v.begin(), v.end());
    std::size_t l = 0, r;
    std::vector<std::pair<std::size_t, std::size_t>> s;
    while (l < m) {
      r = l;
      while (v[r].first == v[l].first) r++;
      s.emplace_back(l, r);
      l = r;
    }
    for (std::size_t i = v[s.front().first].first == -1; i + 1 < s.size();
         i++) {
      for (std::size_t j = s[i].first; j < s[i].second; j++) {
        g[v[j].second].emplace_back(tot);
        ind[tot]++;
      }
      for (std::size_t j = s[i + 1].first; j < s[i + 1].second; j++) {
        g[tot].emplace_back(v[j].second);
        ind[v[j].second]++;
      }
      tot++;
    }
  }
  std::queue<std::size_t> q;
  for (std::size_t i = 0; i < tot; i++)
    if (!ind[i]) q.emplace(i);
  std::vector<int> ans;
  while (!q.empty()) {
    std::size_t u = q.front();
    q.pop();
    if (u < m) ans.emplace_back(u);
    for (auto &&v : g[u])
      if (!--ind[v]) q.emplace(v);
  }
  if (ans.size() < m)
    std::printf("-1");
  else
    for (auto &&i : ans) std::printf("%d ", i + 1);
  return 0;
}