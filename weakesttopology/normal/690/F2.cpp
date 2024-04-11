#include <bits/stdc++.h>

template <int P>
struct Z {
  int x;
  Z() : x(0) {}
  Z(int64_t x_) {
    x = x_ % P;
    if (x < 0) x += P;
  }
  Z& operator+=(Z rhs) {
    x += rhs.x;
    if (x >= P) x -= P;
    return *this;
  }
  Z& operator-=(Z rhs) {
    x -= rhs.x;
    if (x < 0) x += P;
    return *this;
  }
  Z& operator*=(Z rhs) {
    x = int64_t(x) * rhs.x % P;
    return *this;
  }
  Z& operator/=(Z rhs) {
    return *this *= rhs.power(-1);
  }
  Z power(int64_t p) const {
    p %= P - 1;
    if (p < 0) p += P - 1;
    Z res = 1;
    for (Z y = *this; p; p >>= 1, y *= y) {
      if (p & 1) res *= y;
    }
    return res;
  }
  Z operator-() const {
    return Z() - *this;
  }
  bool operator==(Z rhs) const {
    return x == rhs.x;
  }
  bool operator!=(Z rhs) const {
    return x != rhs.x;
  }
  friend Z operator+(Z lhs, Z rhs) {
    return lhs += rhs;
  }
  friend Z operator-(Z lhs, Z rhs) {
    return lhs -= rhs;
  }
  friend Z operator*(Z lhs, Z rhs) {
    return lhs *= rhs;
  }
  friend Z operator/(Z lhs, Z rhs) {
    return lhs /= rhs;
  }
  friend std::ostream& operator<<(std::ostream& out, Z a) {
    return out << a.x;
  }
  friend std::istream& operator>>(std::istream& in, Z& a) {
    int64_t x;
    in >> x;
    a = Z(x);
    return in;
  }
};
using Zp = Z<(int)1e9 + 9>;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const Zp X = rng(), Y = rng();

struct Forest {
  int N;
  std::vector<std::vector<int>> E;
  std::vector<int> sz, dead;
  Forest(int N) : N(N), E(N), sz(N), dead(N) {}
  void add_edge(int u, int v) {
    E[u].push_back(v);
    E[v].push_back(u);
  }
  std::vector<int> centroids;
  void dfs(int u, int p, int n) {
    sz[u] = 1;
    int mx = 0;
    for (auto v : E[u]) {
      if (v == p || dead[v]) continue;
      dfs(v, u, n);
      sz[u] += sz[v];
      mx = std::max(mx, sz[v]);
    }
    if (mx <= n / 2 && (n - sz[u]) <= n / 2) {
      centroids.push_back(u);
    }
  }
  void find_centroids(int rt) {
    centroids.clear();
    dfs(rt, -1, -2);
    dfs(rt, -1, sz[rt]);
  }
  Zp subtree_hash(int u, int p) {
    Zp hash = 1;
    for (auto v : E[u]) {
      if (v == p || dead[v]) continue;
      hash *= X + subtree_hash(v, u);
    }
    return hash;
  }
  Zp tree_hash(int c) {
    find_centroids(c);
    if (centroids.size() == 1) {
      return subtree_hash(centroids[0], -1);
    } else {
      assert(centroids.size() == 2);
      int u = centroids[0], v = centroids[1];
      return (X + subtree_hash(u, v)) * (X + subtree_hash(v, u));
    }
  }
  Zp forest_hash() {
    std::fill(sz.begin(), sz.end(), 0);
    Zp hash = 1;
    for (int u = 0; u < N; ++u) {
      if (sz[u]) continue;
      if (dead[u]) {
        hash *= Y + 1;
      } else {
        hash *= Y + tree_hash(u);
      }
    }
    return hash;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int Z;
  std::cin >> Z;
  for (int z = 0; z < Z; ++z) {
    int N, K;
    std::cin >> N >> K;
    assert(K == N);
    std::vector<Forest> F;
    bool found = false;
    for (int i = 0; i < N; ++i) {
      int M;
      std::cin >> M;
      Forest f(N);
      for (int j = 0; j < M; ++j) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        f.add_edge(u, v);
      }
      F.push_back(std::move(f));
      if (!found && M == N - 2) {
        found = true;
        std::swap(F[0], F.back());
      }
    }
    bool good = false;
    if (found) {
      int s = -1;
      for (int u = 0; u < N; ++u) {
        if (F[0].E[u].empty()) {
          s = u;
          break;
        }
      }
      assert(s != -1);
      std::vector<Zp> h;
      for (int i = 1; i < N; ++i) {
        h.push_back(F[i].forest_hash());
      }
      std::sort(h.begin(), h.end(), [&](Zp a, Zp b) { return a.x < b.x; });
      auto& f = F[0];
      for (int u = 0; u < N; ++u) {
        if (u == s) continue;
        f.add_edge(u, s);
        std::vector<Zp> g;
        for (int v = 0; v < N; ++v) {
          if (v == s) continue;
          f.dead[v] = true;
          g.push_back(f.forest_hash());
          f.dead[v] = false;
        }
        std::sort(g.begin(), g.end(), [&](Zp a, Zp b) { return a.x < b.x; });
        if (h == g) {
          good = true;
          std::cout << "YES\n";
          for (int u = 0; u < N; ++u) {
            for (auto v : f.E[u]) {
              if (u < v) {
                std::cout << u + 1 << ' ' << v + 1 << '\n';
              }
            }
          }
          break;
        }
        f.E[u].pop_back();
        f.E[s].pop_back();
      }
    }
    if (!good) {
      std::cout << "NO\n";
    }
  }
  exit(0);
}