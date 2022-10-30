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

ll stupid(const vi& a) {
  int n = a.size();
  ll res = 0;
  for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
    int ma = 0, r = 0;
    for (int l = i; l <= j; ++l) {
      ma = max(ma, a[l]);
      r |= a[l];
    }
    if (ma < r) ++ res;
  }
  return res;
}

ll solve(const vi& a) {
  int n = a.size();
  vii ts;
  vvi b(31, vi(1, -1));
  for (int i = 0; i < n; ++i) {
    ts.emplace_back(a[i], i);
    for (int x = 0; x < 31; ++x) if (a[i] & (1 << x)) {
      b[x].push_back(i);
    }
  }
  for (int x = 0; x < b.size(); ++x) b[x].push_back(n);
  sort(ts.begin(), ts.end());
  ll res = n * (ll)(n-1) / 2;
  vi pr(n, -1), nx(n, n);
  for (int i = 0; i < n; ++i) {
    pr[i] = i-1;
    nx[i] = i+1;
  }
  for (pii p : ts) {
    int i = p.second;
    int l = pr[i], r = nx[i];
    if (pr[i] != -1) nx[pr[i]] = nx[i];
    if (nx[i] < n) pr[nx[i]] = pr[i];
    for (int x = 0; x < 31; ++x) if (!(a[i] & (1 << x))) {
      auto it = lower_bound(b[x].begin(), b[x].end(), i);
      r = min(r, *it);
      --it;
      l = max(l, *it);
    }
//    cerr << i << ' ' << l << ' ' << r << endl;
    res -= (r - i)*(ll)(i - l) - 1;
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  for (int n = 1; n <= 0; ++n) for (int test = 0; test < 10000; ++test) {
    vi a(n);
    for (int i = 0; i < n; ++i) a[i] = rand() % 1000000000;
    assert(solve(a) == stupid(a));
  }
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << solve(a) << endl;
  return 0;
}