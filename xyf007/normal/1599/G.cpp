#include <algorithm>
#include <cmath>
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
constexpr double kEps = 1e-8;
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
bool Eq0(double x) { return std::fabs(x) < kEps; }
struct Vector {
  double x, y;
  int id;
  Vector(double x = 0.0, double y = 0.0, int id = 0) : x(x), y(y), id(id) {}
  double Magnitude() const { return std::sqrt(x * x + y * y); }
  bool operator<(const Vector &rhs) const {
    return Eq0(x - rhs.x) ? y < rhs.y : x < rhs.x;
  }
  Vector operator-(const Vector &rhs) const {
    return Vector(x - rhs.x, y - rhs.y);
  }
} a[200005], P, K;
double Dis(const Vector &lhs, const Vector &rhs) {
  return (lhs - rhs).Magnitude();
}
double Cross(const Vector &lhs, const Vector &rhs) {
  return lhs.x * rhs.y - lhs.y * rhs.x;
}
int n, k, sp;
bool Check(const Vector &x, const Vector &y) {
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (!Eq0(Cross(a[i] - x, a[i] - y))) sp = i, cnt++;
  return cnt == 1;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cout.precision(8), std::cout << std::fixed;
  std::cin >> n >> k;
  std::string s;
  for (int i = 1; i <= n; i++) {
    std::cin >> s, a[i].x = std::stod(s), std::cin >> s, a[i].y = std::stod(s);
    a[i].id = i;
  }
  if (!Check(a[1], a[2]))
    if (!Check(a[1], a[3])) Check(a[2], a[3]);
  P = a[sp], K = a[k];
  for (int i = sp; i < n; i++) a[i] = a[i + 1];
  n--;
  std::sort(a + 1, a + n + 1);
  double dis0 = Dis(a[1], a[n]) + std::min(Dis(P, a[1]), Dis(P, a[n]));
  if (k == sp) {
    std::cout << dis0;
    return 0;
  }
  double d1 = Dis(P, a[1]), dn = Dis(P, a[n]), d1n = Dis(a[1], a[n]),
         ans = std::min(Dis(P, K) + dis0,
                        d1n + std::min(Dis(K, a[n]) + d1, Dis(K, a[1]) + dn));
  for (int i = 1; i < n; i++)
    if (a[i].id == k)
      checkmin(ans,
               d1n - Dis(a[i], a[i + 1]) + d1 + std::min(Dis(P, a[i + 1]), dn));
  for (int i = 2; i <= n; i++)
    if (a[i].id == k)
      checkmin(ans,
               d1n - Dis(a[i], a[i - 1]) + dn + std::min(Dis(P, a[i - 1]), d1));
  for (int i = 1; i < n; i++)
    checkmin(ans, d1n - Dis(a[i], a[i + 1]) +
                      std::min(Dis(K, a[1]) + Dis(a[i], P), Dis(K, a[i]) + d1) +
                      std::min(Dis(a[i + 1], P), dn));
  for (int i = 2; i <= n; i++)
    checkmin(ans, d1n - Dis(a[i - 1], a[i]) +
                      std::min(Dis(K, a[n]) + Dis(a[i], P), Dis(K, a[i]) + dn) +
                      std::min(Dis(a[i - 1], P), d1));
  if (a[1].id == k) checkmin(ans, d1n + Dis(a[n], P));
  if (a[n].id == k) checkmin(ans, d1n + Dis(a[1], P));
  std::cout << ans;
  return 0;
}