/**
 *    author:  tourist
 *    created: 13.03.2021 12:07:24       
**/
#include <bits/stdc++.h>

using namespace std;

template<typename T>
T extgcd(T a, T b, T &x, T &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  T p = b / a;
  T g = extgcd(b - p * a, a, y, x);
  x -= p * y;
  return g;
}

template<typename T>
bool diophantine(T a, T b, T c, T &x, T &y, T &g) {
  if (a == 0 && b == 0) {
    if (c == 0) {
      x = y = g = 0;
      return true;
    }
    return false;
  }
  if (a == 0) {
    if (c % b == 0) {
      x = 0;
      y = c / b;
      g = abs(b);
      return true;
    }
    return false;
  }
  if (b == 0) {
    if (c % a == 0) {
      x = c / a;
      y = 0;
      g = abs(a);
      return true;
    }
    return false;
  }
  g = extgcd(a, b, x, y);
  if (c % g != 0) {
    return false;
  }
  T dx = c / a;
  c -= dx * a;
  T dy = c / b;
  c -= dy * b;
  x = dx + (T) ((__int128) x * (c / g) % b);
  y = dy + (T) ((__int128) y * (c / g) % a);
  g = abs(g);
  return true;
  // |x|, |y| <= max(|a|, |b|, |c|) [tested]
}

bool crt(long long k1, long long m1, long long k2, long long m2, long long &k, long long &m) {
  k1 %= m1;
  if (k1 < 0) k1 += m1;
  k2 %= m2;
  if (k2 < 0) k2 += m2;
  long long x, y, g;
  if (!diophantine(m1, -m2, k2 - k1, x, y, g)) {
    return false;
  }
  long long dx = m2 / g;
  long long delta = x / dx - (x % dx < 0);
  k = m1 * (x - dx * delta) + k1;
  m = m1 / g * m2;
  assert(0 <= k && k < m);
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  long long k;
  cin >> n >> m >> k;
  int sz = 2 * max(n, m);
  vector<int> pa(sz, -1);
  vector<int> pb(sz, -1);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
    pa[a[i]] = i;
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    --b[i];
    pb[b[i]] = i;
  }
  vector<long long> good;
  long long md = -1;
  for (int i = 0; i < sz; i++) {
    if (pa[i] != -1 && pb[i] != -1) {
      long long x, y;
      if (crt(pa[i], n, pb[i], m, x, y)) {
        good.push_back(x);
        assert(md == -1 || md == y);
        md = y;
      }
    }
  }
  if (md == -1) {
    cout << k << '\n';
    return 0;
  }
  sort(good.begin(), good.end());
  good.resize(unique(good.begin(), good.end()) - good.begin());
  long long low = 0, high = (long long) 4e18;
  while (low < high) {
    long long mid = (low + high) >> 1;
    long long cc = mid;
    cc -= (mid / md) * (long long) good.size();
    long long r = mid % md;
    for (long long x : good) {
      if (x < r) {
        cc -= 1;
      }
    }
    if (cc >= k) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << low << '\n';
  return 0;
}