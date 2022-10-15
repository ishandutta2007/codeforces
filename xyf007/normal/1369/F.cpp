#include <iostream>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n;
long long s[100001], e[100001];
bool Win(long long s, long long e) {
  if (s > e) return true;
  while (~e & 1) {
    long long x = e >> 1;
    if (s > x) return s & 1;
    e = x >> 1;
    if (s > e) return true;
  }
  return ~s & 1;
}
bool Lose(long long s, long long e) {
  if (s > e) return false;
  if (s > (e >> 1)) return true;
  e >>= 1;
  while (~e & 1) {
    long long x = e >> 1;
    if (s > x) return s & 1;
    e = x >> 1;
    if (s > e) return true;
  }
  return ~s & 1;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> s[i] >> e[i];
  bool w1 = Win(s[n], e[n]), l1 = Lose(s[n], e[n]),
       w2 = Win(s[n] + 1, e[n]) && Win(2 * s[n], e[n]),
       l2 = Lose(s[n] + 1, e[n]) && Lose(2 * s[n], e[n]);
  for (int i = n - 1; i >= 1; i--) {
    bool cw1 = Win(s[i], e[i]), cl1 = Lose(s[i], e[i]),
         cw2 = Win(s[i] + 1, e[i]) && Win(2 * s[i], e[i]),
         cl2 = Lose(s[i] + 1, e[i]) && Lose(2 * s[i], e[i]),
         nw1 = (cw1 && w2) || (cl1 && w1) || (w1 && w2),
         nl1 = (cw1 && l2) || (cl1 && l1) || (l1 && l2),
         nw2 = (cw2 && w2) || (cl2 && w1) || (w1 && w2),
         nl2 = (cw2 && l2) || (cl2 && l1) || (l1 && l2);
    w1 = nw1, l1 = nl1, w2 = nw2, l2 = nl2;
  }
  std::cout << w1 << ' ' << l1;
  return 0;
}