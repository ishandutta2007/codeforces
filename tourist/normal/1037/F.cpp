/**
 *    author:  tourist
 *    created: 02.09.2018 17:54:03       
**/
#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e9 + 7;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % md);
}

inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int a) {
  a %= md;
  if (a < 0) a += md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}

const int INV2 = inv(2);

inline int sum_positive(int start, int finish, int step) {
  if (start <= 0) {
    return 0;
  }
  if (finish < 0) {
    finish += abs(finish) / step * step;
  }
  while (finish < 0) {
    finish += step;
  }
  int cnt = (start - finish) / step + 1;
  int value = mul(mul(start + finish, cnt), INV2);
  return value;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<pair<int,int>> e(n);
  for (int i = 0; i < n; i++) {
    cin >> e[i].first;
    e[i].second = i;
  }
  sort(e.begin(), e.end());
  vector<int> pr(n), ne(n);
  for (int i = 0; i < n; i++) {
    pr[i] = i - 1;
    ne[i] = i + 1;
  }
  const int step = k - 1;
  int ans = 0;
  for (auto &pp : e) {
    int i = pp.second;
    int L = pr[i] + 1;
    int R = ne[i] - 1;
    int len = (R - L + 1);
    if (len >= k) {
      int pos = i - L;
      int xstart = k;
      int xfinish = k + (len - k) / step * step;
      int xcnt = (xfinish - xstart) / step + 1;
      {
        int value = sum_positive(pos + 1 - xstart, pos + 1 - xfinish, step);
        sub(ans, mul(value, pp.first));
      }
      {
        add(ans, mul(mul(pos, xcnt), pp.first));
        int value = sum_positive(xfinish + pos - len, xstart + pos - len, step);
        sub(ans, mul(value, pp.first));
      }
      add(ans, mul(xcnt, pp.first));
    }
    if (pr[i] != -1) {
      ne[pr[i]] = ne[i];
    }
    if (ne[i] != n) {
      pr[ne[i]] = pr[i];
    }
  }
  cout << ans << '\n';
  return 0;
}