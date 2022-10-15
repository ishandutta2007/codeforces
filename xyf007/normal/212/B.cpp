#pragma GCC optimize("O3,unroll-loops")
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <iostream>
#include <string>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, a[10001];
std::string s, t;
struct MyHash {
  static std::uint64_t splitmix64(std::uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  std::size_t operator()(std::uint64_t x) const {
    static const std::chrono::steady_clock::rep FIXED_RANDOM =
        std::chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
bool vis[67108865];
__gnu_pbds::gp_hash_table<int, int, MyHash> cnt;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> s >> m;
  n = s.size(), s = '\0' + s;
  for (int i = 1; i <= m; i++) {
    std::cin >> t;
    for (const auto &ch : t) a[i] |= 1 << (ch - 'a');
    vis[a[i]] = true;
  }
  std::vector<int> cur, nxt;
  for (int i = 1; i <= n; i++) {
    nxt.clear();
    int S = 1 << (s[i] - 'a');
    nxt.push_back(S);
    for (const auto &x : cur) {
      if (!(x & S) && vis[x]) cnt[x]++;
      nxt.push_back(x | S);
    }
    nxt.erase(std::unique(nxt.begin(), nxt.end()), nxt.end());
    std::swap(cur, nxt);
  }
  for (const auto &x : cur)
    if (vis[x]) cnt[x]++;
  for (int i = 1; i <= m; i++) std::cout << cnt[a[i]] << '\n';
  return 0;
}