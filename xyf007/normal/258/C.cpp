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
int n, a[100001], sum[100001];
std::vector<int> d[100001];
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
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    sum[a[i]]++;
  }
  int max = *std::max_element(a + 1, a + n + 1), ans = 0;
  std::partial_sum(sum + 1, sum + max + 1, sum + 1);
  for (int i = 1; i <= max; i++) {
    for (int j = i; j <= max; j += i) {
      d[j].emplace_back(i);
    }
  }
  for (int i = 1; i <= max; i++) {
    int tmp = 1;
    for (std::size_t j = 0; j < d[i].size() - 1; j++) {
      Mul(tmp, Ksm(j + 1, sum[d[i][j + 1] - 1] - sum[d[i][j] - 1]));
    }
    int cnt = n - sum[d[i].back() - 1];
    Mul(tmp, sub(Ksm(d[i].size(), cnt), Ksm(d[i].size() - 1, cnt)));
    Add(ans, tmp);
  }
  std::cout << ans;
  return 0;
}