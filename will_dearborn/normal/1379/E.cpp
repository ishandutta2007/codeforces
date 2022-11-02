#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

bool isp2(int n) {
  while (n % 2 == 0) n /= 2;
  return n == 1;
}

int maxk(int n) {
  return (n - 3) / 2;
}

bool ok(int n, int k) {
  if (n < 0 || k < 0 || n % 2 == 0) return false;
  if (k == 0) {
    return isp2(n + 1);
  }
  if (k == 1) {
    return !isp2(n + 1);
  }
  return k <= maxk(n) && !((n == 7 && k == 1) || (n == 9 && k == 2));
}

pii getl(int n, int k) {
  for (int l = 1; l <= min(11, n / 2); l += 2) {
    int r = n - 1 - l;
    int add = 2 * l <= r;
    int sum = k - add;
    for (int k1 = 0; k1 <= maxk(l); ++k1) {
      if (ok(l, k1) && ok(r, sum - k1)) {
//        if (n == 11 && k == 2 && l == 3 && k1 == 0) cerr << l << ' ' << r << ' ' << sum << endl;
        return pii(l, k1);
      }
    }
  }
  for (int l2 = 1; l2 < n; l2 = 2 * l2 + 1) {
    int r = n - 1 - l2;
    int add = 2 * min(l2, r) <= max(l2, r);
    int sum = k - add;
    if (ok(r, sum)) {
//      if (n == 11 && k == 2) cerr << l2 << ' ' << r << ' ' << sum << endl;
      if (l2 <= r) return pii(l2, 0);
      else return pii(r, sum);
    }
  }
  int l = n / 2, r = n - l - 1;
  int add = 2 * l <= r;
  int sum = k - add;
  int k1 = min(maxk(l), sum - 1);
  return pii(l, k1);
}

void solve(vi& v, int s0, int n, int k, int pr) {
  v[s0] = pr;
  if (n == 1) {
    return;
  }
  assert(ok(n, k));
  pii p = getl(n, k);
  int l = p.first, kl = p.second;
  int r = n - 1 - l;
  int add = 2 * l <= r;
  int kr = k - kl - add;
  solve(v, s0 + 1, l, kl, s0 + 1);
  solve(v, s0 + 1 + l, r, kr, s0 + 1);
}

void solve(int n, int k) {
  if (!ok(n, k)) {
    cout << "NO\n";
    return;
  }
  if (k == 0) {
    if (isp2(n + 1)) {
      cout << "YES\n";
      for (int i = 0; i < n; ++i) cout << (i + 1) / 2 << ' ';
      cout << endl;
    } else {
      cout << "NO\n";
    }
    return;
  }
  vi s(n);
  solve(s, 0, n, k, 0);
  cout << "YES\n";
  for (int x : s) cout << x << ' ';
  cout << endl;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
/*  vvi prec(100);
  prec[1] = prec[3] = vi(1, 0);
  for (int n = 5; n < prec.size(); n += 2) {
    for (int l = 1; 2 * l < n; l += 2) {
      int r = n - 1 - l;
      int add = 2 * l <= r;
      for (int x : prec[l]) for (int y : prec[r]) {
        prec[n].push_back(x + y + add);
      }
    }
    sort(prec[n].begin(), prec[n].end());
    prec[n].resize(unique(prec[n].begin(), prec[n].end()) - prec[n].begin());
    cerr << n << ":";
    for (int x : prec[n]) cerr << " " << x;
    cerr << endl;
  }*/
/*  for (int n = 3; n <= 10000; n += 2) for (int k = 0; k < maxk(n); ++k) {
    if (ok(n, k)) {
      pii p = getl(n, k);
//      cerr << n << ' ' << k << ' ' << p.first << ' ' << p.second << endl;
      int add = p.first * 2 <= n - p.first - 1;
      assert(ok(n - p.first - 1, k - p.second - add));
    }
  }*/
  if (0) for (int n = 1; n < 1000; ++n) for (int k = 0; k < 1000; ++k) {
    cerr << n << ' ' << k << endl;
    solve(n, k);
  }
  int n, k;
  cin >> n >> k;
  solve(n, k);
  return 0;
}