/*
_/_/_/_/    _/_/_/_/_/  _/_/_/
_/      _/      _/    _/      _/
_/      _/      _/    _/      _/
_/      _/      _/    _/      _/
_/      _/      _/    _/  _/  _/
_/      _/  _/  _/    _/    _/_/
_/_/_/_/      _/_/     _/_/_/_/_/

_/_/_/_/    _/    _/  _/      _/
_/      _/   _/  _/   _/_/  _/_/
_/      _/    _/_/    _/ _/_/ _/
_/      _/     _/     _/  _/  _/
_/      _/    _/_/    _/      _/
_/      _/   _/  _/   _/      _/
_/_/_/_/    _/    _/  _/      _/

_/_/_/_/_/ _/_/_/_/_/ _/_/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/         _/     _/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/     _/_/_/_/_/ _/_/_/_/_/

_/_/_/_/_/ _/_/_/_/_/ _/_/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/         _/     _/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/     _/_/_/_/_/ _/_/_/_/_/
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>
char Gc() {
  static char now[1 << 20], *S, *T;
  if (T == S) {
    T = (S = now) + std::fread(now, 1, 1 << 20, stdin);
    if (T == S) return EOF;
  }
  return *S++;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Gc()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x);
  Read(args...);
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, k;
std::vector<std::pair<int, std::pair<int, int>>> r, c, nim;
std::vector<int> a, b;
std::vector<std::pair<int, int>> va[100005], vb[100005];
std::unordered_set<int> visa, visb;
int main(int argc, char const *argv[]) {
  Read(n, m, k);
  for (int i = 1; i <= k; i++) {
    int x1, y1, x2, y2;
    Read(x1, y1, x2, y2);
    if (x1 == x2) {
      r.emplace_back(x1, std::make_pair(std::min(y1, y2), std::max(y1, y2)));
      a.emplace_back(x1);
      visa.emplace(x1);
    } else {
      c.emplace_back(y1, std::make_pair(std::min(x1, x2), std::max(x1, x2)));
      b.emplace_back(y1);
      visb.emplace(y1);
    }
  }
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  a.erase(std::unique(a.begin(), a.end()), a.end());
  b.erase(std::unique(b.begin(), b.end()), b.end());
  if (n - 1 > static_cast<int>(a.size()))
    for (int i = 1; i < n; i++)
      if (!visa.count(i)) {
        a.emplace_back(i);
        visa.emplace(i);
        if ((n - 1 - a.size()) & 1)
          for (int j = i + 1; j < n; j++)
            if (!visa.count(j)) {
              a.emplace_back(j);
              visa.emplace(j);
              break;
            }
        break;
      }
  if (m - 1 > static_cast<int>(b.size()))
    for (int i = 1; i < m; i++)
      if (!visb.count(i)) {
        b.emplace_back(i);
        visb.emplace(i);
        if ((m - 1 - b.size()) & 1)
          for (int j = i + 1; j < m; j++)
            if (!visb.count(j)) {
              b.emplace_back(j);
              visb.emplace(j);
              break;
            }
        break;
      }
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  for (auto &&i : r)
    va[std::lower_bound(a.begin(), a.end(), i.first) - a.begin()].emplace_back(
        i.second);
  for (auto &&i : c)
    vb[std::lower_bound(b.begin(), b.end(), i.first) - b.begin()].emplace_back(
        i.second);
  for (std::size_t i = 0; i < a.size(); i++) {
    std::sort(va[i].begin(), va[i].end());
    int len = 0, l = 0, r = 0;
    for (auto &&j : va[i])
      if (j.first <= r) {
        checkmax(r, j.second);
      } else {
        len += r - l;
        l = j.first;
        r = j.second;
      }
    len += r - l;
    nim.emplace_back(m - len, std::make_pair(0, a[i]));
  }
  for (std::size_t i = 0; i < b.size(); i++) {
    std::sort(vb[i].begin(), vb[i].end());
    int len = 0, l = 0, r = 0;
    for (auto &&j : vb[i])
      if (j.first <= r) {
        checkmax(r, j.second);
      } else {
        len += r - l;
        l = j.first;
        r = j.second;
      }
    len += r - l;
    nim.emplace_back(n - len, std::make_pair(1, b[i]));
  }
  int ans = 0;
  for (auto &&i : nim) ans ^= i.first;
  if (!ans) {
    std::printf("SECOND");
    return 0;
  }
  std::printf("FIRST\n");
  for (auto &&i : nim)
    if ((i.first ^ ans) < i.first) {
      ans = i.first - (ans ^ i.first);
      std::vector<std::pair<int, int>> tmp;
      if (!i.second.first) {
        std::printf("%d 0 %d ", i.second.second, i.second.second);
        int r = 0, sum = 0;
        for (auto &&j :
             va[std::lower_bound(a.begin(), a.end(), i.second.second) -
                a.begin()]) {
          if (j.first <= r) {
            checkmax(r, j.second);
          } else {
            tmp.emplace_back(r, j.first);
            r = j.second;
          }
        }
        if (r < m) tmp.emplace_back(r, m);
        for (auto &&j : tmp)
          if (sum + j.second - j.first < ans) {
            sum += j.second - j.first;
          } else {
            std::printf("%d", j.first + ans - sum);
            return 0;
          }
      } else {
        std::printf("0 %d ", i.second.second);
        int r = 0, sum = 0;
        for (auto &&j :
             vb[std::lower_bound(b.begin(), b.end(), i.second.second) -
                b.begin()]) {
          if (j.first <= r) {
            checkmax(r, j.second);
          } else {
            tmp.emplace_back(r, j.first);
            r = j.second;
          }
        }
        if (r < n) tmp.emplace_back(r, n);
        for (auto &&j : tmp)
          if (sum + j.second - j.first < ans) {
            sum += j.second - j.first;
          } else {
            std::printf("%d %d", j.first + ans - sum, i.second.second);
            return 0;
          }
      }
    }
  return 0;
}