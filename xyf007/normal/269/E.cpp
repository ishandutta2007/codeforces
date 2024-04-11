#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
constexpr int kBase = 499, kMod = 1e9 + 9;
template <typename T>
T add(T a, T b) {
  return a + b >= kMod ? a + b - kMod : a + b;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return a - b < 0 ? a - b + kMod : a - b;
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
  if ((a += b) >= kMod) a -= kMod;
}
template <typename T, typename... Args>
void Add(T &a, T b, Args... args) {
  Add(a, add(b, args...));
}
template <typename T>
void Sub(T &a, T b) {
  if ((a -= b) < 0) a += kMod;
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
int n, m, opp[400001], cnt[10], l[5], r[5], ac[100001], ar[100001];
auto rev = [](int pos) {
  if (pos <= m) return 'T';
  if (pos <= m + n) return 'R';
  if (pos <= 2 * m + n) return 'B';
  if (pos <= 2 * m + 2 * n) return 'L';
  return '?';
};
auto tr = [](char c, int x) {
  if (c == 'T') return x;
  if (c == 'R') return m + x;
  if (c == 'B') return m + n + x;
  if (c == 'L') return 2 * m + n + x;
  return -1;
};
auto ie = [](char a, char b) {
  if ((a == 'L' && b == 'T') || (a == 'T' && b == 'L')) return 1;
  if ((a == 'T' && b == 'R') || (a == 'R' && b == 'T')) return 2;
  if ((a == 'R' && b == 'B') || (a == 'B' && b == 'R')) return 3;
  if ((a == 'B' && b == 'L') || (a == 'L' && b == 'B')) return 4;
  if ((a == 'T' && b == 'B') || (a == 'B' && b == 'T')) return 5;
  if ((a == 'L' && b == 'R') || (a == 'R' && b == 'L')) return 6;
  return -1;
};
auto rp = [](int x) -> std::pair<int, int> {
  if (x <= m) return {1, x};
  if (x <= n + m) return {x - m, m};
  if (x <= 2 * m + n) return {n, x - m - n};
  if (x <= 2 * m + 2 * n) return {x - 2 * m - n, 1};
  return {-1, -1};
};
using cycle = std::vector<std::pair<int, int>>;
cycle Lmsr(cycle a) {
  a.reserve(2 * a.size());
  int n = a.size();
  for (int i = 0; i < n; i++) a.push_back(a[i]);
  int i = 0, j = 1, k = 0;
  while (i < n && j < n && k <= n) {
    if (a[i + k].first == a[j + k].first) {
      k++;
    } else {
      if (a[i + k].first > a[j + k].first)
        i += k + 1;
      else
        j += k + 1;
      if (i == j) i++;
      k = 0;
    }
  }
  int p = std::min(i, j);
  return cycle(a.begin() + p, a.begin() + p + n);
}
struct Graph {
  int to[400001];
  bool vis[400001];
  bool Add(int u, int v) {
    if (to[u] || to[v]) return false;
    to[u] = v, to[v] = u;
    return true;
  }
  const std::vector<std::pair<int, int>> Hash() {
    std::vector<std::pair<int, int>> res;
    for (int i = 1; i <= 2 * n + 2 * m; i++)
      if (!vis[i]) {
        cycle cyc, rcyc;
        for (int p = i; !vis[p]; p = opp[to[p]]) {
          cyc.emplace_back(ie(rev(p), rev(to[p])), p);
          vis[p] = vis[to[p]] = true;
        }
        rcyc.resize(cyc.size());
        std::reverse_copy(cyc.begin(), cyc.end(), rcyc.begin());
        for (auto &&[e, p] : rcyc) p = to[p];
        cyc = Lmsr(cyc), rcyc = Lmsr(rcyc);
        if (cyc > rcyc) std::swap(cyc, rcyc);
        int hs = 0;
        for (const auto &[e, p] : cyc) hs = add(mul(hs, kBase), e);
        res.emplace_back(hs, cyc[0].second);
      }
    std::sort(res.begin(), res.end());
    return res;
  }
} g1, g2;
bool vis[400001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) opp[tr('T', i)] = tr('B', i);
  for (int i = 1; i <= n; i++) opp[tr('R', i)] = tr('L', i);
  for (int i = 1; i <= m; i++) opp[tr('B', i)] = tr('T', i);
  for (int i = 1; i <= n; i++) opp[tr('L', i)] = tr('R', i);
  for (int i = 1; i <= n + m; i++) {
    char a[10], b[10];
    int c, d;
    std::cin >> a >> b >> c >> d;
    int u = tr(a[0], c), v = tr(b[0], d);
    g1.Add(u, v), g1.Add(v, u);
    cnt[ie(a[0], b[0])]++;
  }
  auto fail = []() {
    std::cout << "No solution";
    std::exit(0);
  };
  if (cnt[5] && cnt[6]) fail();
  r[1] = r[3] = m + 1, r[2] = r[4] = n + 1;
  for (int i = 1; i <= cnt[1]; i++)
    if (!g2.Add(tr('L', ++l[4]), tr('T', ++l[1]))) fail();
  for (int i = 1; i <= cnt[2]; i++)
    if (!g2.Add(tr('T', --r[1]), tr('R', ++l[2]))) fail();
  for (int i = 1; i <= cnt[3]; i++)
    if (!g2.Add(tr('R', --r[2]), tr('B', --r[3]))) fail();
  for (int i = 1; i <= cnt[4]; i++)
    if (!g2.Add(tr('B', ++l[3]), tr('L', --r[4]))) fail();
  for (int i = 1; i <= cnt[5]; i++)
    if (!g2.Add(tr('T', ++l[1]), tr('B', ++l[3]))) fail();
  for (int i = 1; i <= cnt[6]; i++)
    if (!g2.Add(tr('R', ++l[2]), tr('L', ++l[4]))) fail();
  auto c1 = g1.Hash(), c2 = g2.Hash();
  if (c1.size() != c2.size()) fail();
  for (std::size_t i = 0; i < c2.size(); i++)
    if (c1[i].first != c2[i].first) fail();
  for (std::size_t i = 0; i < c2.size(); i++)
    for (int p1 = c1[i].second, p2 = c2[i].second; !vis[p2];
         p1 = opp[p1], p2 = opp[p2]) {
      vis[p2] = vis[g2.to[p2]] = true;
      auto [x1, y1] = rp(p1);
      auto [x2, y2] = rp(p2);
      char z2 = rev(p2);
      if (z2 == 'T' || z2 == 'B') ac[y2] = y1;
      if (z2 == 'L' || z2 == 'R') ar[x2] = x1;
      p1 = g1.to[p1], p2 = g2.to[p2];
      std::tie(x1, y1) = rp(p1), std::tie(x2, y2) = rp(p2);
      z2 = rev(p2);
      if (z2 == 'T' || z2 == 'B') ac[y2] = y1;
      if (z2 == 'L' || z2 == 'R') ar[x2] = x1;
    }
  for (int i = 1; i <= n; i++) std::cout << ar[i] << " \n"[i == n];
  for (int i = 1; i <= m; i++) std::cout << ac[i] << " \n"[i == m];
  return 0;
}