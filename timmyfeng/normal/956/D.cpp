#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int order[N];

struct fraction {

  int n, d;

  fraction(int _n, int _d) : n(_n), d(_d) {
    if (d < 0) {
      n = -n;
      d = -d;
    }

    int g = __gcd(n, d);
    n /= g;
    d /= g;
  }

  bool operator<(fraction oth) const {
    return 1LL * n * oth.d < 1LL * oth.n * d;
  }

  bool operator==(fraction oth) const {
    return 1LL * n * oth.d == 1LL * oth.n * d;
  }

};

struct point {

  fraction x1, x2;
  int i;

  bool operator<(point oth) const {
    if (x1 == oth.x1) {
      if (x2 == oth.x2) {
        return i < oth.i;
      }
      return oth.x2 < x2;
    }
    return x1 < oth.x1;
  }

};

template <class T>
struct fenwick {

  T tree[N];

  void update(int a, T val) {
    for ( ; a < N; a += a & -a) {
      tree[a] += val;
    }
  }

  T query(int a) {
    T res = 0;
    for ( ; a; a -= a & -a) {
      res += tree[a];
    }
    return res;
  }

};

fenwick<int> fenw;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, w;
  cin >> n >> w;

  vector<point> upper;
  vector<point> lower;

  for (int i = 0; i < n; ++i) {
    int x, v;
    cin >> x >> v;
    fraction a(x, w - v);
    fraction b(x, -w - v);
    upper.push_back({a, b, i});
    lower.push_back({b, a, -i});
  }

  sort(upper.begin(), upper.end());
  sort(lower.begin(), lower.end());

  for (int i = 0; i < n; ++i) {
    order[upper[i].i] = i;
  }

  int64_t ans = int64_t(n) * (n - 1) / 2;
  for (int i = 0; i < n; ++i) {
    int ndx = order[-lower[i].i] + 1;
    ans -= fenw.query(ndx);
    fenw.update(ndx, 1);
  }

  cout << ans << "\n";
}