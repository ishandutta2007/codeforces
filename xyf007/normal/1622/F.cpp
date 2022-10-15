#include <chrono>
#include <iostream>
#include <random>
#include <unordered_map>
std::mt19937 rng(
    std::chrono::_V2::steady_clock::now().time_since_epoch().count());
unsigned long long Rand(unsigned long long l = 0ULL,
                        unsigned long long r = 18446744073709551615ULL) {
  return std::uniform_int_distribution<unsigned long long>(l, r)(rng);
}
int n, d[1000001];
unsigned long long hs[1000001], a[1000001], f[1000001];
bool vis[1000001];
std::unordered_map<unsigned long long, int> mp;
void Init(int n) {
  std::iota(d + 1, d + n + 1, 1);
  for (int i = 2; i <= n; i++)
    if (d[i] == i)
      for (int j = i + i; j <= n; j += i)
        if (d[j] == j) d[j] = i;
  for (int i = 2; i <= n; i++)
    if (d[i] == i) hs[i] = Rand();
  for (int i = 2; i <= n; i++) {
    a[i] = a[i / d[i]] ^ hs[d[i]];
    mp[f[i] = f[i - 1] ^ a[i]] = i;
  }
}
void Print(const std::vector<int> &rem) {
  for (const auto &i : rem) vis[i] = true;
  std::cout << n - rem.size() << '\n';
  for (int i = 1; i <= n; i++)
    if (!vis[i]) std::cout << i << ' ';
  std::exit(0);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  Init(n);
  unsigned long long all = 0ULL;
  for (int i = 1; i <= n; i++) all ^= f[i];
  if (all == 0) Print({});
  for (int i = 1; i <= n; i++)
    if (f[i] == all) Print({i});
  for (int i = 2; i <= n; i++)
    if (mp.count(all ^ f[i])) Print({i, mp[all ^ f[i]]});
  all ^= f[n--];
  for (int i = 2; i <= n; i++)
    if (mp.count(all ^ f[i])) Print({i, mp[all ^ f[i]]});
  return 0;
}