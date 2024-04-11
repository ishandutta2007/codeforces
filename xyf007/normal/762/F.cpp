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
constexpr int kMod = 1e9 + 7;
template <typename T>
T add(T a, T b) {
  return (a + b) % kMod;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return (a + kMod - b) % kMod;
}
template <typename T, typename... Args>
T sub(T a, T b, Args... args) {
  return sub(sub(a, b), args...);
}
template <typename T>
T mul(T a, T b) {
  return a * static_cast<long long>(b) % kMod;
}
template <typename T, typename... Args>
T mul(T a, T b, Args... args) {
  return mul(mul(a, b), args...);
}
template <typename T>
void Add(T &a, T b) {
  a = add(a, b);
}
template <typename T, typename... Args>
void Add(T &a, T b, Args... args) {
  Add(a, add(b, args...));
}
template <typename T>
void Sub(T &a, T b) {
  a = sub(a, b);
}
template <typename T, typename... Args>
void Sub(T &a, T b, Args... args) {
  Sub(a, add(b, args...));
}
template <typename T>
void Mul(T &a, T b) {
  a = mul(a, b);
}
template <typename T, typename... Args>
void Mul(T &a, T b, Args... args) {
  Mul(a, mul(b, args...));
}
template <typename T1, typename T2>
T1 Ksm(T1 a, T2 b) {
  T1 s = 1;
  while (b) {
    if (b & 1) Mul(s, a);
    Mul(a, a);
    b >>= 1;
  }
  return s;
}
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
using Tree = std::vector<std::vector<int>>;
Tree S, T;
void Delete(std::vector<int> &v, int element) {
  for (auto it = v.begin(); it != v.end(); ++it)
    if (*it == element) {
      v.erase(it);
      break;
    }
}
Tree GetRoot(Tree tree, int rt) {
  std::queue<int> q;
  q.emplace(rt);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &&v : tree[u]) Delete(tree[v], u), q.emplace(v);
  }
  return tree;
}
int n, m, lg[100001];
std::vector<int> dp[1000][12];
class Solver {
 private:
  int Dfs(const Tree &ss, const Tree &tt, int u, int x) {
    std::vector<int> &res = dp[u][x];
    if (!res.empty()) return res.back();
    res.resize(1 << tt[x].size());
    res[0] = 1;
    for (auto &&v : ss[u]) {
      for (int i = res.size() - 1; i >= 0; i--)
        for (int j = i; j; j ^= j & -j) {
          int y = lg[j & -j];
          if (res[i ^ (1 << y)])
            Add(res[i], mul(res[i ^ (1 << y)], Dfs(ss, tt, v, tt[x][y])));
        }
    }
    return res.back();
  }

 public:
  Solver() {}
  int match(const Tree &S, const Tree &T) {
    if (S.size() < T.size()) return 0;
    if (T.size() == 1) return static_cast<int>(S.size());
    auto clear = [&]() {
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) std::vector<int>().swap(dp[i][j]);
    };
    int ans = 0;
    Tree s = GetRoot(S, 0);
    for (int j = 0; j < m; j++) {
      Tree t = GetRoot(T, j);
      for (int i = 0; i < static_cast<int>(S.size()); i++)
        Add(ans, Dfs(s, t, i, j));
      clear();
    }
    return ans;
  }
  ~Solver() {}
} solver;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  auto readtree = [&](Tree &tree, int n) {
    tree.resize(n);
    for (int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v, u--, v--;
      tree[u].push_back(v), tree[v].push_back(u);
    }
  };
  std::cin >> n, readtree(S, n);
  std::cin >> m, readtree(T, m);
  for (int i = 2; i <= 1 << m; i++) lg[i] = lg[i >> 1] + 1;
  std::cout << mul(solver.match(S, T), Ksm(solver.match(T, T), kMod - 2));
  return 0;
}