#include <iostream>
#include <numeric>
constexpr int kDx[] = {1, 1, 1, 0, -1, -1, -1, 0},
              kDy[] = {1, 0, -1, -1, -1, 0, 1, 1};
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, q;
bool vis[3001][6001];
class DisjointSet {
 public:
  DisjointSet() {}
  void Init(int n) { std::iota(fa_ + 1, fa_ + n + 1, 1); }
  int Find(int x) { return fa_[x] == x ? x : fa_[x] = Find(fa_[x]); }
  bool Merge(int x, int y) {
    int fx = Find(x), fy = Find(y);
    if (fx == fy) return false;
    fa_[fx] = fy;
    return true;
  }
  ~DisjointSet() {}

 private:
  int fa_[20000001];
} dsu;
auto id = [](int x, int y) { return (x - 1) * 2 * m + y; };
bool In(int &x, int &y) {
  if (y == 0) y = 2 * m;
  if (y == 2 * m + 1) y = 1;
  return x >= 1 && x <= n && vis[x][y];
}
bool Check(int x, int y) {
  int x1 = x, y1 = y + m;
  for (int i = 0; i < 8; i++) {
    int tx1 = x + kDx[i], ty1 = y + kDy[i];
    if (In(tx1, ty1))
      for (int j = 0; j < 8; j++) {
        int tx2 = x1 + kDx[j], ty2 = y1 + kDy[j];
        if (In(tx2, ty2))
          if (dsu.Find(id(tx1, ty1)) == dsu.Find(id(tx2, ty2))) return false;
      }
  }
  return true;
}
void Delete(int x, int y) {
  int x1 = x, y1 = y + m;
  for (int i = 0; i < 8; i++) {
    int tx = x + kDx[i], ty = y + kDy[i];
    if (In(tx, ty)) dsu.Merge(id(x, y), id(tx, ty));
  }
  for (int i = 0; i < 8; i++) {
    int tx = x1 + kDx[i], ty = y1 + kDy[i];
    if (In(tx, ty)) dsu.Merge(id(x1, y1), id(tx, ty));
  }
  vis[x][y] = vis[x1][y1] = true;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> q;
  if (m == 1) {
    std::cout << 0;
    return 0;
  }
  dsu.Init(2 * n * m);
  int ans = 0;
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    if (Check(x, y)) Delete(x, y), ans++;
  }
  std::cout << ans;
  return 0;
}