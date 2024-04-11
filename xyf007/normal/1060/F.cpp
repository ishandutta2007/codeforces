#include <cstring>
#include <iomanip>
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
int n, sz[51];
long double c[51][51], fac[51], f[51][51], h[51], tmp[51];
std::vector<int> g[51];
void Dfs(int u, int fa) {
  sz[u] = 1, f[u][0] = 1.0L;
  for (auto &&v : g[u]) {
    if (v == fa) continue;
    Dfs(v, u);
    std::memset(h, 0, 16 * (sz[v] + 1));
    for (int i = 1; i <= sz[v]; i++) h[i] = h[i - 1] + 0.5 * f[v][i - 1];
    for (int i = 0; i <= sz[v]; i++) h[i] += (sz[v] - i) * f[v][i];
    std::memset(tmp, 0, 16 * (sz[u] + sz[v]));
    for (int i = 0; i < sz[u]; i++)
      for (int j = 0; j <= sz[v]; j++)
        tmp[i + j] += f[u][i] * h[j] * c[i + j][i] *
                      c[sz[u] - i - 1 + sz[v] - j][sz[u] - i - 1];
    std::memcpy(f[u], tmp, 16 * (sz[u] += sz[v]));
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  c[0][0] = fac[0] = 1.0L;
  for (int i = 1; i <= n; i++) {
    c[i][0] = 1.0L;
    for (int j = 1; j <= i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;
  std::cout.precision(8), std::cout << std::fixed;
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    std::memset(f, 0, sizeof(f));
    Dfs(i, 0);
    std::cout << f[i][n - 1] / fac[n - 1] << '\n';
  }
  return 0;
}