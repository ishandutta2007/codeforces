#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <queue>
#include <random>
struct TS {
  int c, q;
  bool operator<(const TS a) const {
    if (q == a.q) return c < a.c;
    return q > a.q;
  }
} a[200001];
int n, m, val[200001], ch[200001][2], rd[200001], minu[200001], add[200001],
    ans[200001], tot, root;
std::mt19937 rng(
    std::chrono::_V2::steady_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> Rand(0, 2147483647);
int NewNode(int x) {
  val[++tot] = x;
  rd[tot] = Rand(rng);
  return tot;
}
void Pushdown(int x) {
  if (minu[x]) {
    if (ch[x][0]) val[ch[x][0]] -= minu[x], minu[ch[x][0]] += minu[x];
    if (ch[x][1]) val[ch[x][1]] -= minu[x], minu[ch[x][1]] += minu[x];
    minu[x] = 0;
  }
  if (add[x]) {
    if (ch[x][0]) ans[ch[x][0]] += add[x], add[ch[x][0]] += add[x];
    if (ch[x][1]) ans[ch[x][1]] += add[x], add[ch[x][1]] += add[x];
    add[x] = 0;
  }
}
void Split(int p, int now, int &x, int &y) {
  if (!p) {
    x = y = 0;
    return;
  }
  Pushdown(p);
  if (now >= val[p]) {
    x = p;
    Split(ch[p][1], now, ch[p][1], y);
  } else {
    y = p;
    Split(ch[p][0], now, x, ch[p][0]);
  }
}
int Merge(int x, int y) {
  if (!x || !y) return x + y;
  if (rd[x] < rd[y]) {
    Pushdown(x);
    ch[x][1] = Merge(ch[x][1], y);
    return x;
  } else {
    Pushdown(y);
    ch[y][0] = Merge(x, ch[y][0]);
    return y;
  }
}
void Pushdownall(int x) {
  Pushdown(x);
  if (ch[x][0]) Pushdownall(ch[x][0]);
  if (ch[x][1]) Pushdownall(ch[x][1]);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i].c >> a[i].q;
  std::sort(a + 1, a + n + 1);
  std::cin >> m;
  int x, y, z;
  for (int i = 1; i <= m; i++) {
    int b;
    std::cin >> b;
    Split(root, b, x, y);
    root = Merge(Merge(x, NewNode(b)), y);
  }
  for (int i = 1; i <= n; i++) {
    Split(root, a[i].c - 1, x, y), Split(y, 2 * a[i].c - 1, y, z);
    val[z] -= a[i].c, minu[z] += a[i].c;
    ans[z]++, add[z]++;
    std::queue<int> q;
    q.emplace(y);
    while (!q.empty()) {
      int t = q.front();
      q.pop();
      Pushdown(t);
      if (ch[t][0]) q.emplace(ch[t][0]);
      if (ch[t][1]) q.emplace(ch[t][1]);
      int X, Y;
      Split(x, val[t] - a[i].c, X, Y);
      val[t] -= a[i].c;
      ch[t][0] = ch[t][1] = minu[t] = add[t] = 0;
      ans[t]++;
      x = Merge(Merge(X, t), Y);
    }
    root = Merge(x, z);
  }
  Pushdownall(root);
  for (int i = 1; i <= m; i++) std::cout << ans[i] << ' ';
  return 0;
}