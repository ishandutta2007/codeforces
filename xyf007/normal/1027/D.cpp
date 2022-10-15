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
int n, a[200001], p[200001], ind[200001];
bool vis[200001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++) std::cin >> p[i], ind[p[i]]++;
  std::queue<int> q;
  for (int i = 1; i <= n; i++)
    if (!ind[i]) q.emplace(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = true;
    if (!--ind[p[u]]) q.emplace(p[u]);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      int min = a[i];
      vis[i] = true;
      for (int j = p[i]; j != i; j = p[j]) {
        checkmin(min, a[j]);
        vis[j] = true;
      }
      ans += min;
    }
  std::cout << ans;
  return 0;
}