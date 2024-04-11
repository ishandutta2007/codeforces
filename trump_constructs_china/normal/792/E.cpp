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
template <typename T, template <typename...> class Container_t>
std::ostream &operator<<(std::ostream &out, const Container_t<T> &v) {
  for (auto &&x : v) out << x << ' ';
  return out;
}
int n, a[501];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  long long ans = std::numeric_limits<long long>::max();
  auto upd = [&ans](int k) {
    if (k == 0) return;
    long long tmp = 0LL;
    for (int i = 1; i <= n; i++) {
      int A = a[i] / k, B = a[i] % k;
      if (B > A) return;
      tmp += A - (A - B) / (k + 1);
    }
    checkmin(ans, tmp);
  };
  for (int l = 1, r; l <= a[1]; l = r + 1) {
    int k = a[1] / l;
    r = a[1] / k;
    upd(k);
    if (a[1] % l == 0) upd(k - 1);
  }
  std::cout << ans;
  return 0;
}