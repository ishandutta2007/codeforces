#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
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
template <typename T>
void Mul(T &a, T b) {
  a = mul(a, b);
}
template <typename T, typename... Args>
void Mul(T &a, T b, Args... args) {
  Mul(a, mul(b, args...));
}
int n, dp[15][15], bit[15], f[15], ans;
std::vector<int> b;
int Ksm(int a, int b) {
  int s = 1;
  while (b) {
    if (b & 1) {
      Mul(s, a);
    }
    Mul(a, a);
    b >>= 1;
  }
  return s;
}
int C(int x, int y) {
  if (x < y || y < 0) {
    return 0;
  }
  int s = 1;
  for (int i = 1; i <= y; i++) {
    Mul(s, x - i + 1, Ksm(i, kMod - 2));
  }
  return s;
}
int Dfs(int now, int cnt, bool f) {
  if (!now) {
    return !cnt;
  }
  if (dp[now][cnt] != -1 && !f) {
    return dp[now][cnt];
  }
  int up = f ? bit[now] : 9, res = 0;
  for (int i = 0; i <= up; i++) {
    if (i == 4 || i == 7) {
      if (cnt) {
        Add(res, Dfs(now - 1, cnt - 1, f && i == up));
      }
    } else {
      Add(res, Dfs(now - 1, cnt, f && i == up));
    }
  }
  if (!f) {
    dp[now][cnt] = res;
  }
  return res;
}
void Solve(int tt, int now, int lst) {
  if (now == 7) {
    int c[15], s = 720;
    std::memset(c, 0, sizeof(c));
    if (std::accumulate(b.begin(), b.end(), 0) >= tt) {
      return;
    }
    for (auto &&i : b) {
      c[i]++;
    }
    for (int i = 0; i < 15; i++) {
      Mul(s, C(f[i], c[i]));
    }
    Add(ans, mul(f[tt], s));
    return;
  }
  for (int i = 0; i <= lst; i++) {
    b.emplace_back(i);
    Solve(tt, now + 1, i);
    b.pop_back();
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n;
  int cnt = 0, tmp = n;
  while (tmp) {
    bit[++cnt] = tmp % 10;
    tmp /= 10;
  }
  std::memset(dp, -1, sizeof(dp));
  for (int i = 0; i <= cnt; i++) {
    f[i] = Dfs(cnt, i, true);
  }
  f[0]--;
  for (int i = 1; i <= cnt; i++) {
    Solve(i, 1, i - 1);
  }
  std::cout << ans;
  return 0;
}