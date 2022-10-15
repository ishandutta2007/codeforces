#include <cctype>
#include <cstring>
#include <iostream>
#include <numeric>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, q, pre[100001], nxt[100001];
char s[100005];
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
  int fa_[200001];
} dsu;
int len, cur, dir, f[2][100005][10], b[10];
bool vis[2][100005];
void Delete(int x) {
  pre[nxt[x]] = pre[x], nxt[pre[x]] = nxt[x];
  len--;
}
void Move() {
  int t;
  if (std::isdigit(s[cur])) {
    b[s[cur] - '0']++;
    if (s[cur] == '0')
      Delete(cur);
    else
      s[cur]--;
    t = dir == 1 ? nxt[cur] : pre[cur];
  } else {
    dir = s[cur] == '>';
    t = dir == 1 ? nxt[cur] : pre[cur];
    if (cur && !std::isdigit(s[t])) Delete(cur);
  }
  if (dir == 1 && !vis[1][t]) {
    vis[1][t] = true;
    std::memcpy(f[1][t], b, 40);
  }
  if (dir == 0) {
    int l = dsu.Find(t) + 1;
    while (l <= cur) {
      vis[0][l] = true;
      std::memcpy(f[0][l], b, 40);
      dsu.Merge(l - 1, l), l = dsu.Find(l) + 1;
    }
  }
  cur = t;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> q >> (s + 1);
  s[0] = '>';
  std::iota(pre + 1, pre + n + 1, 0), std::iota(nxt, nxt + n + 1, 1);
  len = n, dir = 1;
  dsu.Init(n);
  std::memset(f, 0x3f, sizeof(f));
  while (cur <= n && len) Move();
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    for (int i = 0; i < 10; i++)
      std::cout << (vis[0][l] ? std::min(f[0][l][i], f[1][r + 1][i])
                              : f[1][r + 1][i]) -
                       f[1][l][i]
                << " \n"[i == 9];
  }
  return 0;
}