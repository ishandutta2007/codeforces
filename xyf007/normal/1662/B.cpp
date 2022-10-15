#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
int a[27], b[27], c[27];
char s[1005];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin.getline(s + 1, 1001);
  int la = std::strlen(s + 1);
  for (int i = 1; i <= la; i++) a[s[i] - 'A']++;
  std::cin.getline(s + 1, 1001);
  int lb = std::strlen(s + 1);
  for (int i = 1; i <= lb; i++) b[s[i] - 'A']++;
  std::cin.getline(s + 1, 1001);
  int lc = std::strlen(s + 1);
  for (int i = 1; i <= lc; i++) c[s[i] - 'A']++;
  int L = std::min({la, lb, lc}), tot = 0;
  std::vector<int> da, db, dc;
  da.reserve(la), db.reserve(lb), dc.reserve(lc);
  for (int i = 0; i < 26; i++) {
    int x = 0, y = 0, z = 0, s = 0;
    for (int xx = 0; xx <= a[i] && xx <= b[i]; xx++)
      for (int yy = 0; xx + yy <= b[i] && yy <= c[i] && xx + yy + tot <= L;
           yy++) {
        int zz = std::min({a[i] - xx, c[i] - yy, L - xx - yy - tot});
        if (xx + yy + zz > s) s = xx + yy + zz, x = xx, y = yy, z = zz;
      }
    tot += s;
    da.insert(da.end(), y, i), a[i] -= x + z;
    db.insert(db.end(), z, i), b[i] -= x + y;
    dc.insert(dc.end(), x, i), c[i] -= y + z;
  }
  std::vector<int> rema, remb, remc;
  rema.reserve(la), remb.reserve(lb), remc.reserve(lc);
  for (int i = 0; i < 26; i++) {
    rema.insert(rema.end(), a[i], i);
    remb.insert(remb.end(), b[i], i);
    remc.insert(remc.end(), c[i], i);
  }
  std::vector<std::pair<int, int>> ans;
  ans.reserve(la + lb + lc);
  auto f = [&ans](std::vector<int> &d, std::vector<int> &r) {
    ans.emplace_back(d.back(), r.back());
    d.pop_back(), r.pop_back();
  };
  while (!da.empty()) f(da, rema);
  while (!db.empty()) f(db, remb);
  while (!dc.empty()) f(dc, remc);
  while (!rema.empty() && (!remb.empty() || !remc.empty()))
    f(rema, remb.size() > remc.size() ? remb : remc);
  while (!remb.empty() && !remc.empty()) f(remb, remc);
  for (const auto x : rema) ans.emplace_back(x, 0);
  for (const auto x : remb) ans.emplace_back(x, 0);
  for (const auto x : remc) ans.emplace_back(x, 0);
  std::cout << ans.size() << '\n';
  for (const auto &[x, y] : ans) std::cout.put(x + 'A').put(y + 'A').put('\n');
  return 0;
}