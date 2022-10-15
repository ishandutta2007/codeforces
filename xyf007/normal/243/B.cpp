#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
struct Edge {
  int to, nxt;
} e[200001];
int n, m, h, t, E, head[100001], deg[100001], c[100001];
void Add(int f, int t) {
  e[E].to = t;
  e[E].nxt = head[f];
  head[f] = E++;
}
bool vis[100001];
std::vector<int> v1, v2;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::memset(head, -1, sizeof(head));
  std::cin >> n >> m >> h >> t;
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    Add(u, v);
    Add(v, u);
    deg[u]++;
    deg[v]++;
  }
  for (int i = 1; i <= n; i++) {
    if (deg[i] <= h) {
      continue;
    }
    for (int j = head[i]; j != -1; j = e[j].nxt) {
      int v = e[j].to;
      if (deg[v] <= t) {
        continue;
      }
      if (deg[i] > h + t) {
        int cnt = 0;
        for (int k = head[v]; k != -1; k = e[k].nxt) {
          int vv = e[k].to;
          if (vv != i) {
            v2.emplace_back(vv);
            vis[vv] = true;
            if (++cnt == t) {
              break;
            }
          }
        }
        cnt = 0;
        for (int k = head[i]; k != -1; k = e[k].nxt) {
          int vv = e[k].to;
          if (vv != v && !vis[vv]) {
            v1.emplace_back(vv);
            vis[vv] = true;
            if (++cnt == h) {
              break;
            }
          }
        }
        std::cout << "YES\n" << i << ' ' << v << '\n';
        for (auto &&k : v1) {
          std::cout << k << ' ';
        }
        std::cout << '\n';
        for (auto &&k : v2) {
          std::cout << k << ' ';
        }
        return 0;
      } else if (deg[v] > h + t) {
        int cnt = 0;
        for (int k = head[i]; k != -1; k = e[k].nxt) {
          int vv = e[k].to;
          if (vv != v) {
            v1.emplace_back(vv);
            vis[vv] = true;
            if (++cnt == h) {
              break;
            }
          }
        }
        cnt = 0;
        for (int k = head[v]; k != -1; k = e[k].nxt) {
          int vv = e[k].to;
          if (vv != i && !vis[vv]) {
            v2.emplace_back(vv);
            vis[vv] = true;
            if (++cnt == t) {
              break;
            }
          }
        }
        std::cout << "YES\n" << i << ' ' << v << '\n';
        for (auto &&k : v1) {
          std::cout << k << ' ';
        }
        std::cout << '\n';
        for (auto &&k : v2) {
          std::cout << k << ' ';
        }
        return 0;
      } else {
        std::vector<int> tmp;
        for (int k = head[i]; k != -1; k = e[k].nxt) {
          int vv = e[k].to;
          if (vv == v) {
            continue;
          }
          vis[vv] = true;
          c[vv] = 1;
          tmp.emplace_back(vv);
        }
        for (int k = head[v]; k != -1; k = e[k].nxt) {
          int vv = e[k].to;
          if (vv == i) {
            continue;
          }
          if (!vis[vv]) {
            tmp.emplace_back(vv);
          }
          vis[vv] = true;
          c[vv] += 2;
        }
        if (static_cast<int>(tmp.size()) < h + t) {
          for (int k = head[i]; k != -1; k = e[k].nxt) {
            int vv = e[k].to;
            if (vv == v) {
              continue;
            }
            vis[vv] = false;
            c[vv] = 0;
          }
          for (int k = head[v]; k != -1; k = e[k].nxt) {
            int vv = e[k].to;
            if (vv == i) {
              continue;
            }
            vis[vv] = false;
            c[vv] = 0;
          }
          continue;
        }
        std::sort(
            tmp.begin(), tmp.end(),
            [](const int &x, const int &y) -> bool { return c[x] < c[y]; });
        int cnt0 = 0, cnt1 = 0;
        for (auto &&k : tmp) {
          if (c[k] == 1) {
            if (cnt0 < h) {
              v1.emplace_back(k);
              cnt0++;
            }
          } else if (c[k] == 2) {
            if (cnt1 < t) {
              v2.emplace_back(k);
              cnt1++;
            }
          } else {
            if (cnt0 < h) {
              v1.emplace_back(k);
              cnt0++;
            } else if (cnt1 < t) {
              v2.emplace_back(k);
              cnt1++;
            }
          }
        }
        std::cout << "YES\n" << i << ' ' << v << '\n';
        for (auto &&k : v1) {
          std::cout << k << ' ';
        }
        std::cout << '\n';
        for (auto &&k : v2) {
          std::cout << k << ' ';
        }
        return 0;
      }
    }
  }
  std::cout << "NO";
  return 0;
}