#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <utility>
using std::literals::string_literals::operator""s;
constexpr int kN = 200000;
constexpr long long kInf = 0x3f3f3f3f3f3f3f3fLL;
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, s, ls[10000001], rs[10000001], tot;
long long min[10000001], tag[10000001];
void Pushup(int x) { min[x] = std::min(min[ls[x]], min[rs[x]]); }
void Add(int x, long long v) {
  if (min[x] != kInf) min[x] += v, tag[x] += v;
}
void Pushdown(int x) {
  if (tag[x]) {
    Add(ls[x], tag[x]), Add(rs[x], tag[x]);
    tag[x] = 0LL;
  }
}
void Modify(int l, int r, int p, long long v, int x) {
  if (l == r) {
    min[x] = v;
    return;
  }
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (p <= mid) {
    if (!ls[x]) ls[x] = ++tot;
    Modify(l, mid, p, v, ls[x]);
  } else {
    if (!rs[x]) rs[x] = ++tot;
    Modify(mid + 1, r, p, v, rs[x]);
  }
  Pushup(x);
}
int Merge(int l, int r, int x, int y) {
  if (!x || !y) return x + y;
  if (l == r) {
    checkmin(min[x], min[y]);
    return x;
  }
  Pushdown(x), Pushdown(y);
  int mid = (l + r) >> 1;
  ls[x] = Merge(l, mid, ls[x], ls[y]), rs[x] = Merge(mid + 1, r, rs[x], rs[y]);
  Pushup(x);
  return x;
}
long long Erase(int l, int r, int p, int x) {
  if (!x) return kInf;
  if (l == r) return std::exchange(min[x], kInf);
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (p <= mid)
    return Erase(l, mid, p, ls[x]);
  else
    return Erase(mid + 1, r, p, rs[x]);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> s;
  std::memset(min, 0x3f, sizeof(min));
  int rt = ++tot;
  Modify(0, kN, 0, 0LL, rt);
  std::string op;
  std::stack<int> st;
  for (int i = 1; i <= n; i++) {
    std::cin >> op;
    if (op == "set"s) {
      int x, v;
      std::cin >> x >> v;
      long long f = min[rt];
      if (f != kInf) {
        Add(rt, v);
        if (x != s) Modify(0, kN, x, f, rt);
      }
    } else if (op == "if"s) {
      int x, nrt = ++tot;
      std::cin >> x;
      long long f = Erase(0, kN, x, rt);
      if (f != kInf) Modify(0, kN, x, f, nrt);
      st.emplace(std::exchange(rt, nrt));
    } else {
      rt = Merge(0, kN, rt, st.top()), st.pop();
    }
  }
  std::cout << min[rt];
  return 0;
}