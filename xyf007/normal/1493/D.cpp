#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <unordered_map>
constexpr int kMod = 1e9 + 7;
struct Node {
  int ls, rs, val;
} t[14000001];
int n, q, a[200001], p[200001], tot, id[200001], cnt;
bool not_prime[200001];
void Pushup(int x) { t[x].val = std::min(t[t[x].ls].val, t[t[x].rs].val); }
void Modify(int l, int r, int p, int v, int x) {
  if (l == r) {
    t[x].val += v;
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid) {
    if (!t[x].ls) {
      t[x].ls = ++cnt;
    }
    Modify(l, mid, p, v, t[x].ls);
  } else {
    if (!t[x].rs) {
      t[x].rs = ++cnt;
    }
    Modify(mid + 1, r, p, v, t[x].rs);
  }
  Pushup(x);
}
int Ksm(int a, int b) {
  int s = 1;
  while (b) {
    if (b & 1) {
      s = s * static_cast<long long>(a) % kMod;
    }
    a = a * static_cast<long long>(a) % kMod;
    b >>= 1;
  }
  return s;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  not_prime[1] = true;
  for (int i = 2; i <= 200000; i++) {
    if (!not_prime[i]) {
      p[id[i] = ++tot] = i;
    }
    for (int j = 1; j <= tot && i * p[j] <= 200000; j++) {
      not_prime[i * p[j]] = true;
      if (!(i % p[j])) {
        break;
      }
    }
  }
  cnt = tot;
  std::cin >> n >> q;
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    for (int j = 1; j <= tot && p[j] * p[j] <= a[i]; j++) {
      if (!(a[i] % p[j])) {
        int cnt = 0, pre = t[j].val;
        while (!(a[i] % p[j])) {
          cnt++;
          a[i] /= p[j];
        }
        Modify(1, n, i, cnt, j);
        ans = ans * static_cast<long long>(Ksm(p[j], t[j].val - pre)) % kMod;
      }
    }
    if (a[i] > 1) {
      int pre = t[id[a[i]]].val;
      Modify(1, n, i, 1, id[a[i]]);
      ans = ans * static_cast<long long>(Ksm(a[i], t[id[a[i]]].val - pre)) % kMod;
    }
  }
  while (q--) {
    int pos, x;
    std::cin >> pos >> x;
    for (int j = 1; j <= tot && p[j] * p[j] <= x; j++) {
      if (!(x % p[j])) {
        int cnt = 0, pre = t[j].val;
        while (!(x % p[j])) {
          cnt++;
          x /= p[j];
        }
        Modify(1, n, pos, cnt, j);
        ans = ans * static_cast<long long>(Ksm(p[j], t[j].val - pre)) % kMod;
      }
    }
    if (x > 1) {
      int pre = t[id[x]].val;
      Modify(1, n, pos, 1, id[x]);
      ans = ans * static_cast<long long>(Ksm(x, t[id[x]].val - pre)) % kMod;
    }
    std::cout << ans << '\n';
  }
  return 0;
}