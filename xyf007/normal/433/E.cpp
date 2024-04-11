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
struct Number {
  std::size_t len;
  std::vector<int> val;
} L, R, a[201];
int n, m, k, c[201];
std::istream &operator>>(std::istream &in, Number &x) {
  in >> x.len, x.val.resize(x.len);
  for (auto &&i : x.val) in >> i;
  return in;
}
class AhoCorasickAutomaton {
 public:
  struct Node {
    int ch[20], s, fail;
  } t_[201];
  int tot_;
  void Insert(const Number &x, int v) {
    int now = 0;
    for (std::size_t i = 0; i < x.len; i++) {
      if (!t_[now].ch[x.val[i]]) t_[now].ch[x.val[i]] = ++tot_;
      now = t_[now].ch[x.val[i]];
    }
    t_[now].s += v;
  }
  void Build() {
    std::queue<int> q;
    for (int i = 0; i < m; i++)
      if (t_[0].ch[i]) q.emplace(t_[0].ch[i]);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int i = 0; i < m; i++)
        if (t_[u].ch[i]) {
          t_[t_[u].ch[i]].fail = t_[t_[u].fail].ch[i];
          t_[t_[u].ch[i]].s += t_[t_[t_[u].fail].ch[i]].s;
          q.emplace(t_[u].ch[i]);
        } else {
          t_[u].ch[i] = t_[t_[u].fail].ch[i];
        }
    }
  }
  AhoCorasickAutomaton() {}
  ~AhoCorasickAutomaton() {}
} ac;
int Solve(const Number &x) {
  int n = x.len, dp[n + 1][ac.tot_ + 1][2][2][k + 1];
  std::memset(dp, 0, sizeof(dp));
  dp[0][0][1][1][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= ac.tot_; j++)
      for (int hi = 0; hi <= 1; hi++)
        for (int ld0 = 0; ld0 <= 1; ld0++)
          for (int s = 0; s <= k; s++)
            if (dp[i][j][hi][ld0][s] > 0)
              for (int c = 0; c < m; c++) {
                if (hi && c > x.val[i]) break;
                if (ld0 && c == 0) {
                  Add(dp[i + 1][j][0][1][s], dp[i][j][hi][ld0][s]);
                  continue;
                }
                int nj = ac.t_[j].ch[c];
                if (s + ac.t_[nj].s > k) continue;
                Add(dp[i + 1][nj][hi && c == x.val[i]][0][s + ac.t_[nj].s],
                    dp[i][j][hi][ld0][s]);
              }
  int ans = 0;
  for (int i = 0; i <= ac.tot_; i++)
    for (int hi = 0; hi <= 1; hi++)
      for (int ld0 = 0; ld0 <= 1; ld0++)
        for (int s = 0; s <= k; s++) Add(ans, dp[n][i][hi][ld0][s]);
  return ans;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> k >> L >> R;
  for (int i = 1; i <= n; i++) std::cin >> a[i] >> c[i];
  for (int i = 1; i <= n; i++) ac.Insert(a[i], c[i]);
  ac.Build();
  L.val.back()--;
  for (int i = L.len - 1; i > 0; i--)
    if (L.val[i] < 0) L.val[i] += m, L.val[i - 1]--;
  while (L.val.size() > 1 && !L.val[0]) L.val.erase(L.val.begin());
  L.len = L.val.size();
  std::cout << sub(Solve(R), Solve(L));
  return 0;
}