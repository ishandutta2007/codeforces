/**
 *    author:  tourist
 *    created: 22.01.2022 18:59:59       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
struct TPoint {
  T x;
  T y;
  int id;

  TPoint() : x(0), y(0), id(-1) {}
  TPoint(const T& x_, const T& y_) : x(x_), y(y_), id(-1) {}
  TPoint(const T& x_, const T& y_, int id_) : x(x_), y(y_), id(id_) {}

  static constexpr T eps = static_cast<T>(1e-9);

  inline TPoint operator+(const TPoint& rhs) const { return TPoint(x + rhs.x, y + rhs.y); }
  inline TPoint operator-(const TPoint& rhs) const { return TPoint(x - rhs.x, y - rhs.y); }
  inline TPoint operator*(const T& rhs) const { return TPoint(x * rhs, y * rhs); }
  inline TPoint operator/(const T& rhs) const { return TPoint(x / rhs, y / rhs); }

  friend T smul(const TPoint& a, const TPoint& b) {
    return a.x * b.x + a.y * b.y;
  }

  friend T vmul(const TPoint& a, const TPoint& b) {
    return a.x * b.y - a.y * b.x;
  }

  inline T abs2() const {
    return x * x + y * y;
  }

  inline bool operator<(const TPoint& rhs) const {
    return (y < rhs.y || (y == rhs.y && x < rhs.x));
  }

  inline bool is_upper() const {
    return (y > eps || (abs(y) <= eps && x > eps));
  }

  inline int cmp_polar(const TPoint& rhs) const {
    assert(abs(x) > eps || abs(y) > eps);
    assert(abs(rhs.x) > eps || abs(rhs.y) > eps);
    bool a = is_upper();
    bool b = rhs.is_upper();
    if (a != b) {
      return (a ? -1 : 1);
    }
    long long v = x * rhs.y - y * rhs.x;
    return (v > eps ? -1 : (v < -eps ? 1 : 0));
  }
};

using Point = TPoint<long long>;
//using Point = TPoint<long double>;

template <typename T>
string to_string(const TPoint<T>& p) {
  return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}

class segtree {
 public:
  struct node {
    int val = -1;

    void apply(int l, int r, int v) {
      val = v;
    }
  };

  node unite(const node &a, const node &b) const {
    node res;
    res.val = 0;
    return res;
  }

  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (tree[x].val != 0) {
      tree[x + 1].apply(l, y, tree[x].val);
      tree[z].apply(y + 1, r, tree[x].val);
      tree[x].val = 0;
    }
  }

  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  int n;
  vector<node> tree;

  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }

  template <typename M>
  void build(int x, int l, int r, const vector<M> &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
    pull(x, z);
  }

  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    pull(x, z);
    return res;
  }

  template <typename... M>
  void modify(int x, int l, int r, int ll, int rr, const M&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }

  int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
    pull(x, z);
    return res;
  }

  int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[z])) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
    pull(x, z);
    return res;
  }

  int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  segtree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }

  template <typename M>
  segtree(const vector<M> &v) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }

  node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, 0, n - 1, ll, rr);
  }

  node get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }

  template <typename... M>
  void modify(int ll, int rr, const M&... v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v...);
  }

  // find_first and find_last call all FALSE elements
  // to the left (right) of the sought position exactly once

  int find_first(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_first(0, 0, n - 1, ll, rr, f);
  }

  int find_last(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_last(0, 0, n - 1, ll, rr, f);
  }
};

bool Intersect(Point a, Point b, Point c, Point d) {
  debug(a, b, c, d);
  long long A = b.y - a.y;
  long long B = a.x - b.x;
  long long C = -A * a.x - B * a.y;
  long long z1 = A * c.x + B * c.y + C;
  long long z2 = A * d.x + B * d.y + C;
  if (z1 < 0 && z2 < 0) return false;
  if (z1 > 0 && z2 > 0) return false;
  A = d.y - c.y;
  B = c.x - d.x;
  C = -A * c.x - B * c.y;
  z1 = A * a.x + B * a.y + C;
  z2 = A * b.x + B * b.y + C;
  if (z1 < 0 && z2 < 0) return false;
  if (z1 > 0 && z2 > 0) return false;
  if (z1 == 0 && z2 == 0) {
    long long xa = a.x;
    long long xb = b.x;
    long long xc = c.x;
    long long xd = d.x;
    if (xa > xb) swap(xa, xb);
    if (xc > xd) swap(xc, xd);
    if (xb < xc || xd < xa) return false;
    xa = a.y;
    xb = b.y;
    xc = c.y;
    xd = d.y;
    if (xa > xb) swap(xa, xb);
    if (xc > xd) swap(xc, xd);
    if (xb < xc || xd < xa) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<Point> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;
  }
  int q;
  cin >> q;
  vector<Point> s(q);
  for (int i = 0; i < q; i++) {
    cin >> s[i].x >> s[i].y;
  }
  vector<bool> res(q, false);
  auto Test = [&](Point vy) {
    Point vx(vy.y, -vy.x);
    auto Rotate = [&](Point p) {
      return Point(smul(p, vx), smul(p, vy));
    };
    vector<Point> ar(n), br(n);
    vector<long long> A(n), B(n), C(n);
    for (int i = 0; i < n; i++) {
      ar[i] = Rotate(a[i]);
      br[i] = Rotate(b[i]);
      if (ar[i].x > br[i].x) {
        swap(ar[i], br[i]);
      }
      A[i] = ar[i].y - br[i].y;
      B[i] = br[i].x - ar[i].x;
      C[i] = -A[i] * ar[i].x - B[i] * ar[i].y;
    }
    vector<Point> sr(q);
    for (int i = 0; i < q; i++) {
      sr[i] = Rotate(s[i]);
    }
    sr.push_back(Point(0, 0));
    vector<pair<long long, int>> ev;
    for (int i = 0; i < n; i++) {
      ev.emplace_back(ar[i].x, ~i);
      ev.emplace_back(br[i].x, i + q + 1);
    }
    for (int i = 0; i <= q; i++) {
      ev.emplace_back(sr[i].x, i);
    }
    sort(ev.begin(), ev.end());
    long long X = 0;
    auto cmp = [&](int i, int j) { 
      if (i < n && j < n) {
        long long num_i = (-X * A[i] - C[i]);
        long long den_i = B[i];
        long long num_j = (-X * A[j] - C[j]);
        long long den_j = B[j];
        if (den_i == 0) num_i = ar[i].y, den_i = 1;
        if (den_j == 0) num_j = ar[j].y, den_j = 1;
        return __int128(num_i) * den_j < __int128(num_j) * den_i;
      }
      if (i >= n && j >= n) {
        return sr[i - n].y < sr[j - n].y;
      }
      if (i < n && j >= n) {
        long long num_i = (-X * A[i] - C[i]);
        long long den_i = B[i];
        if (den_i == 0) num_i = ar[i].y, den_i = 1;
        return num_i < sr[j - n].y * den_i;
      }
      assert(i >= n && j < n);
      long long num_j = (-X * A[j] - C[j]);
      long long den_j = B[j];
      if (den_j == 0) num_j = ar[j].y, den_j = 1;
      return sr[i - n].y * den_j < num_j;
    };
    vector<vector<int>> g(n + q + 1);
    multiset<int, decltype(cmp)> segs(cmp);
    for (auto& e : ev) {
      X = e.first;
      int id = e.second;
      if (id < 0) {
        id = ~id;
        auto it = segs.insert(id);
        if (it != segs.begin()) {
          g[*prev(it)].push_back(id);
        }
        auto it2 = next(it);
        if (it2 != segs.end()) {
          g[id].push_back(*it2);
        }
        continue;
      }
      if (id >= q + 1) {
        id -= q + 1;
        auto it = segs.find(id);
        if (it != segs.begin()) {
          auto itR = next(it);
          if (itR != segs.end()) {
            g[*prev(it)].push_back(*itR);
          }
        }
        segs.erase(it);
        continue;
      }
      auto it = segs.lower_bound(n + id);
      if (it != segs.begin()) {
        g[*prev(it)].push_back(n + id);
      }
      if (it != segs.end()) {
        g[n + id].push_back(*it);
      }
    }
    vector<int> deg(n + q + 1);
    for (int i = 0; i < n + q + 1; i++) {
      for (int j : g[i]) {
        deg[j] += 1;
      }
    }
    vector<int> que;
    for (int i = 0; i < n + q + 1; i++) {
      if (deg[i] == 0) {
        que.push_back(i);
      }
    }
    for (int b = 0; b < (int) que.size(); b++) {
      for (int j : g[que[b]]) {
        if (--deg[j] == 0) {
          que.push_back(j);
        }
      }
    }
    assert((int) que.size() == n + q + 1);
    vector<long long> xs(1, 0);
    for (int i = 0; i < n; i++) {
      xs.push_back(ar[i].x);
      xs.push_back(br[i].x);
    }
    for (int i = 0; i < q; i++) {
      xs.push_back(sr[i].x);
    }
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    auto GetX = [&](long long x) {
      auto it = lower_bound(xs.begin(), xs.end(), x);
      assert(it != xs.end() && (*it) == x);
      return (int) (it - xs.begin());
    };
    int cnt = (int) xs.size();
    debug(vx, vy, que, g);
    segtree st(cnt);
    for (int i : que) {
//      vector<int> vs;
//      for (int ii = 0; ii < cnt; ii++) vs.push_back(st.get(ii, ii).val);
//      debug(vs);
      if (i == n + q) {
        int x = GetX(0);
        st.modify(x, x, 1);
        continue;
      }
      if (i >= n) {
        int x = GetX(sr[i - n].x);
        if (st.get(x, x).val == 1) {
          res[i - n] = true;
        }
        continue;
      }
      long long dx = abs(ar[i].x - br[i].x);
      long long dy = abs(ar[i].y - br[i].y);
      int ax = GetX(ar[i].x);
      int bx = GetX(br[i].x);
      if (dx >= dy) {
        st.modify(ax, bx, -1);
      } else {
        int val = (ar[i].y < br[i].y ? st.get(ax, ax).val : st.get(bx, bx).val);
        st.modify(ax, bx, val);
      }
    }
  };
  for (int i = 0; i < n; i++) {
    Test(a[i]);
    Test(b[i]);
  }
  for (int i = 0; i < q; i++) {
    Point p0(0, 0);
    Point p1 = s[i];
    bool ok = true;
    for (int j = 0; j < n; j++) {
      auto got = Intersect(p0, p1, a[j], b[j]);
      debug(got);
      if (got) {
        ok = false;
        break; 
      }
    }
    if (ok) {
      res[i] = true;
    }
  }
  for (int i = 0; i < q; i++) {
    cout << (res[i] ? "YES" : "NO") << '\n';
  }
  return 0;
}