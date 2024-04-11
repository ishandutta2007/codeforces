#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <algorithm>
#include <iostream>
constexpr int kMod = 1e9 + 9;
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
struct Node {
  int ls, rs, sz, f, g, val;
} t[100001];
int n, k, q, X[100001], Y[100001];
std::pair<int, int> a[100001];
long long A, B, C, D;
void Pushup(int x) {
  t[x].sz = t[t[x].ls].sz + t[t[x].rs].sz + 1;
  t[x].f = t[x].g = 0;
  if (t[x].ls) {
    t[x].g = std::max(t[x].g + std::max(t[t[x].ls].f, t[t[x].ls].g),
                      t[x].f + t[t[x].ls].f + 1);
    t[x].f += std::max(t[t[x].ls].f, t[t[x].ls].g);
  }
  if (t[x].rs) {
    t[x].g = std::max(t[x].g + std::max(t[t[x].rs].f, t[t[x].rs].g),
                      t[x].f + t[t[x].rs].f + 1);
    t[x].f += std::max(t[t[x].rs].f, t[t[x].rs].g);
  }
}
int Build(int l, int r) {
  if (l > r) return 0;
  int mid = std::max_element(Y + l, Y + r + 1) - Y;
  t[mid].ls = Build(l, mid - 1), t[mid].rs = Build(mid + 1, r);
  t[mid].val = Y[mid];
  Pushup(mid);
  return mid;
}
void Split(int p, int k, int &x, int &y) {
  if (!p) {
    x = y = 0;
    return;
  }
  if (k > t[t[p].ls].sz) {
    x = p;
    Split(t[p].rs, k - t[t[p].ls].sz - 1, t[p].rs, y);
  } else {
    y = p;
    Split(t[p].ls, k, x, t[p].ls);
  }
  Pushup(p);
}
int Merge(int x, int y) {
  if (!x || !y) return x + y;
  if (t[x].val > t[y].val) {
    t[x].rs = Merge(t[x].rs, y);
    Pushup(x);
    return x;
  } else {
    t[y].ls = Merge(x, t[y].ls);
    Pushup(y);
    return y;
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k;
  for (int i = 1; i <= k; i++) std::cin >> a[i].first >> a[i].second;
  std::cin >> A >> B >> C >> D;
  for (int i = k + 1; i <= n; i++) {
    a[i].first = (A * a[i - 1].first + B) % kMod;
    a[i].second = (C * a[i - 1].second + D) % kMod;
  }
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) X[i] = a[i].first;
  for (int i = 1; i <= n; i++) Y[i] = a[i].second;
  int rt = Build(1, n), x, y, z;
  std::cin >> q;
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    l = std::lower_bound(X + 1, X + n + 1, l) - X;
    r = std::upper_bound(X + 1, X + n + 1, r) - X - 1;
    if (l > r) {
      std::cout << "0\n";
      continue;
    }
    Split(rt, r, x, y), Split(x, l - 1, x, z);
    std::cout << std::max(t[z].f, t[z].g) << '\n';
    rt = Merge(Merge(x, z), y);
  }
  return 0;
}