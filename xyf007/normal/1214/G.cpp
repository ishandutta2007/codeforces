#include <bitset>
#include <iostream>
#include <set>
#include <utility>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
std::size_t n, m, q, cnt[2000];
std::bitset<2000> full, a[2000];
std::set<std::pair<std::size_t, std::size_t>> res;
struct Cmp {
  bool operator()(std::size_t x, std::size_t y) const {
    return cnt[x] == cnt[y] ? x < y : cnt[x] < cnt[y];
  }
};
std::set<std::size_t, Cmp> s;
void Print() {
  if (res.empty()) {
    std::cout << "-1\n";
    return;
  }
  auto [x1, x2] = *res.begin();
  std::bitset<2000> dif = a[x1] ^ a[x2];
  std::size_t y1 = (dif & a[x1])._Find_first(),
              y2 = (dif & a[x2])._Find_first();
  if (x1 > x2) std::swap(x1, x2);
  if (y1 > y2) std::swap(y1, y2);
  std::cout << ++x1 << ' ' << ++y1 << ' ' << ++x2 << ' ' << ++y2 << '\n';
}
inline bool Check(int x, int y) { return cnt[x] && (a[x] & a[y]) != a[x]; }
void Erase(std::size_t p) {
  std::set<std::size_t>::iterator it = s.find(p), pr, nx = std::next(it);
  if (it != s.begin()) pr = std::prev(it);
  if (it != s.begin()) res.erase({*pr, *it});
  if (nx != s.end()) res.erase({*it, *nx});
  if (it != s.begin() && nx != s.end() && Check(*pr, *nx))
    res.emplace(*pr, *nx);
  s.erase(it);
}
void Insert(std::size_t p) {
  std::set<std::size_t>::iterator it = s.emplace(p).first, pr,
                                  nx = std::next(it);
  if (it != s.begin()) pr = std::prev(it);
  if (it != s.begin() && nx != s.end()) res.erase({*pr, *nx});
  if (it != s.begin() && Check(*pr, *it)) res.emplace(*pr, *it);
  if (nx != s.end() && Check(*it, *nx)) res.emplace(*it, *nx);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> q;
  for (std::size_t i = 0; i < m; i++) full.set(i);
  for (std::size_t i = 0; i < n; i++) s.emplace_hint(s.end(), i);
  while (q--) {
    std::size_t p, l, r;
    std::cin >> p >> l >> r, p--, l--, r--;
    Erase(p);
    a[p] ^= full >> (m - (r - l + 1)) << l, cnt[p] = a[p].count();
    Insert(p);
    Print();
  }
  return 0;
}