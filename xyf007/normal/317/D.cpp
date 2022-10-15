#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
constexpr int kSg[] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6,  2, 1, 8, 7,  5,
                       9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
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
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + (c - '0');
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
int n, cnt[30];
std::unordered_set<int> vis;
// std::unordered_map<int, int> sg;
// int Dfs(int S, int n) {
//   if (sg.count(S)) return sg[S];
//   bool v2[31];
//   std::memset(v2, false, sizeof(v2));
//   for (int i = 1; i <= n; i++)
//     if ((S >> (i - 1)) & 1) {
//       int T = S;
//       for (int j = i; j <= n; j += i) T &= ~(1 << (j - 1));
//       v2[Dfs(T, n)] = true;
//     }
//   for (int i = 0;; i++)
//     if (!v2[i]) {
//       sg[S] = i;
//       break;
//     }
//   return sg[S];
// }
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 2; i * i <= n; i++) {
    if (vis.count(i)) continue;
    int tot = 0;
    for (long long j = i; j <= n; j *= i) {
      vis.emplace(j);
      tot++;
    }
    cnt[tot]++;
  }
  cnt[1] = n;
  for (int i = 2; i < 30; i++) cnt[1] -= cnt[i] * i;
  int ans = 0;
  for (int i = 1; i < 30; i++)
    if (cnt[i] & 1) ans ^= kSg[i];
  if (ans)
    std::printf("Vasya");
  else
    std::printf("Petya");
  return 0;
}