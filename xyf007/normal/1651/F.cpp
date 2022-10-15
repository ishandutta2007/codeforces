#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <numeric>
constexpr int kN = 1e9;
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
struct Segment {
  int l, r, t;
  long long c;  // c  0 iff l = r
} s[200001];
int n, q, top, tot, rt[2000001];
long long c[200001], r[200001], d[200001];
struct Node {
  int ls, rs;
  long long sr, sc;
} t[8000001];
void Pushup(int x) {
  t[x].sr = t[t[x].ls].sr + t[t[x].rs].sr;
  t[x].sc = t[t[x].ls].sc + t[t[x].rs].sc;
}
int Modify(int l, int r, int p, const std::pair<long long, long long> &v,
           int x) {
  int xx = ++tot;
  t[xx] = t[x];
  if (l == r) {
    t[xx].sr += v.first, t[xx].sc += v.second;
    return xx;
  }
  long long mid = (l + r) >> 1;
  if (p <= mid)
    t[xx].ls = Modify(l, mid, p, v, t[x].ls);
  else
    t[xx].rs = Modify(mid + 1, r, p, v, t[x].rs);
  Pushup(xx);
  return xx;
}
long long QueryR(int L, int R, int l, int r, int x, int y) {
  if (L <= l && r <= R) return t[y].sr - t[x].sr;
  int mid = (l + r) >> 1;
  long long ans = 0LL;
  if (L <= mid) ans += QueryR(L, R, l, mid, t[x].ls, t[y].ls);
  if (R > mid) ans += QueryR(L, R, mid + 1, r, t[x].rs, t[y].rs);
  return ans;
}
long long QueryC(int L, int R, int l, int r, int x, int y) {
  if (L <= l && r <= R) return t[y].sc - t[x].sc;
  long long ans = 0LL;
  int mid = (l + r) >> 1;
  if (L <= mid) ans += QueryC(L, R, l, mid, t[x].ls, t[y].ls);
  if (R > mid) ans += QueryC(L, R, mid + 1, r, t[x].rs, t[y].rs);
  return ans;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> c[i] >> r[i];
  for (int i = 1; i <= n; i++) d[i] = (c[i] + r[i] - 1) / r[i];
  for (int i = n; i >= 1; i--) s[++top] = {i, i, 0LL, c[i]};
  for (int i = 1; i <= n; i++)
    rt[i] = Modify(0LL, kN, d[i], {r[i], c[i]}, rt[i - 1]);
  std::cin >> q;
  long long ans = 0LL;
  while (q--) {
    int t;
    long long h;
    std::cin >> t >> h;
    int rr = 0;
    while (top) {
      auto [pl, pr, lst, lc] = s[top];
      if (pl == pr) {
        long long cur = std::min(lc + r[pl] * (t - lst), c[pl]);
        if (h > cur) {
          h -= cur, rr = pl;
        } else {
          s[top].t = t, s[top].c = cur - h;
          break;
        }
      } else {
        long long sumc = QueryC(0, t - lst, 0, kN, rt[pl - 1], rt[pr]),
                  sumr = QueryR(t - lst + 1, kN, 0, kN, rt[pl - 1], rt[pr]),
                  all = sumc + sumr * (t - lst);
        if (all < h) {
          h -= all, rr = pr;
        } else if (all == h) {
          h = 0LL, rr = pr, top--;
          break;
        } else {
          int L = pl, R = pr, best = pl - 1;
          while (L <= R) {
            int mid = (L + R) >> 1;
            sumc = QueryC(0, t - lst, 0, kN, rt[pl - 1], rt[mid]);
            sumr = QueryR(t - lst + 1, kN, 0, kN, rt[pl - 1], rt[mid]);
            all = sumc + sumr * (t - lst);
            if (h >= all)
              best = mid, L = mid + 1;
            else
              R = mid - 1;
          }
          rr = best;
          sumc = QueryC(0, t - lst, 0, kN, rt[pl - 1], rt[best]);
          sumr = QueryR(t - lst + 1, kN, 0, kN, rt[pl - 1], rt[best]);
          all = sumc + sumr * (t - lst);
          h -= all;
          if (h) {
            if (best == s[top].r - 1)
              top--;
            else
              s[top].l = best + 2;
            long long cur = std::min(c[best + 1], r[best + 1] * (t - lst));
            s[++top] = {best + 1, best + 1, t, cur - h};
          } else {
            s[top].l = best + 1;
          }
          break;
        }
      }
      top--;
    }
    if (!top) ans += h;
    if (rr) s[++top] = {1, rr, t, 0LL};
  }
  std::cout << ans;
  return 0;
}