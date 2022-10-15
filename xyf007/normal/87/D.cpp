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
template <class T, typename = decltype(std::declval<T>().begin()),
          typename = decltype(std::declval<T>().end()),
          typename = typename std::enable_if<!std::is_base_of<
              std::string, typename std::decay<T>::type>::value>::type,
          typename value_type = typename T::value_type>
std::ostream &operator<<(std::ostream &out, const T &container) {
  for (auto it = container.begin(); it != container.end(); ++it)
    out << *it << ' ';
  return out;
}
std::ostream &operator<<(std::ostream &out, __int128_t x) {
  static int s[101], top;
  top = 0;
  while (x) s[top++] = x % 10, x /= 10;
  for (int i = top - 1; i >= 0; i--) out << s[i];
  return out;
}
struct Edge {
  int u, v, w, id;
} a[100001];
int n;
class LinkCutTree {
 public:
  int sz_[100001];
  LinkCutTree() {}
  void Splay(int x) {
    PushdownAll(x);
    while (NotRoot(x)) {
      int y = fa_[x];
      if (NotRoot(y)) Rotate(IsRson(x) == IsRson(y) ? y : x);
      Rotate(x);
    }
    Pushup(x);
  }
  void Access(int x) {
    for (int y = 0; x; y = x, x = fa_[x])
      Splay(x), sz2_[x] -= sz_[y] - sz_[ch_[x][1]], ch_[x][1] = y, Pushup(x);
  }
  void MakeRoot(int x) { Access(x), Splay(x), Reverse(x); }
  int FindRoot(int x) {
    while (ch_[x][0]) Pushdown(ch_[x][0]), x = ch_[x][0];
    Splay(x);
    return x;
  }
  void Split(int x, int y) { MakeRoot(x), Access(y), Splay(y); }
  void Link(int x, int y) {
    MakeRoot(x), MakeRoot(y), fa_[x] = y, sz2_[y] += sz_[x];
  }
  ~LinkCutTree() {}

 private:
  int ch_[100001][2], fa_[100001], sz2_[100001];
  bool rev_[100001];
  bool NotRoot(int x) { return ch_[fa_[x]][0] == x || ch_[fa_[x]][1] == x; }
  bool IsRson(int x) { return ch_[fa_[x]][1] == x; }
  void Reverse(int x) { std::swap(ch_[x][0], ch_[x][1]), rev_[x] ^= 1; }
  void Pushup(int x) { sz_[x] = sz_[ch_[x][0]] + sz_[ch_[x][1]] + sz2_[x] + 1; }
  void Pushdown(int x) {
    if (rev_[x]) {
      if (ch_[x][0]) Reverse(ch_[x][0]);
      if (ch_[x][1]) Reverse(ch_[x][1]);
      rev_[x] = false;
    }
  }
  void PushdownAll(int x) {
    if (NotRoot(x)) PushdownAll(fa_[x]);
    Pushdown(x);
  }
  void Rotate(int x) {
    int y = fa_[x], z = fa_[y], d1 = IsRson(x), d2 = IsRson(y),
        w = ch_[x][d1 ^ 1];
    if (NotRoot(y)) ch_[z][d2] = x;
    ch_[x][d1 ^ 1] = y, ch_[y][d1] = w;
    if (w) fa_[w] = y;
    fa_[x] = z, fa_[y] = x;
    Pushup(y);
  }
} lct;
long long ans[100001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i < n; i++)
    std::cin >> a[i].u >> a[i].v >> a[i].w, a[i].id = i;
  std::sort(a + 1, a + n,
            [](const Edge &lhs, const Edge &rhs) { return lhs.w < rhs.w; });
  for (int l = 1, r; l < n; l = r + 1) {
    r = l;
    while (r + 1 < n && a[r + 1].w == a[l].w) r++;
    for (int i = l; i <= r; i++) lct.Link(a[i].u, a[i].v);
    for (int i = l; i <= r; i++) {
      lct.Split(a[i].u, a[i].v);
      ans[a[i].id] = lct.sz_[a[i].u] *
                     static_cast<long long>(lct.sz_[a[i].v] - lct.sz_[a[i].u]);
    }
  }
  long long max = 0LL;
  std::vector<int> sol;
  for (int i = 1; i < n; i++)
    if (ans[i] > max)
      std::vector<int>(1, i).swap(sol), max = ans[i];
    else if (ans[i] == max)
      sol.push_back(i);
  std::cout << 2 * max << ' ' << sol.size() << '\n' << sol;
  return 0;
}