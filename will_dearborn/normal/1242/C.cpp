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

void no() {
  cout << "No\n";
  exit(0);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vvi a(n);
  vl sum(n);
  ll s = 0;
  vi ts;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    a[i].resize(t);
    for (int j = 0; j < t; ++j) {
      cin >> a[i][j];
      s += a[i][j];
      sum[i] += a[i][j];
      ts.push_back(a[i][j]);
    }
    sort(a[i].begin(), a[i].end());
  }
  if (s % n) no();
  s /= n;
  for (int i = 0; i < n; ++i) sum[i] -= s;
  sort(ts.begin(), ts.end());
  for (int i = 0; i < n; ++i) for (auto& x : a[i]) x = lower_bound(ts.begin(), ts.end(), x) - ts.begin();
  vvi prec(n, vi(ts.size(), -1));
  for (int i = 0; i < n; ++i) {
    int it = 0;
    for (int j = 0; j < ts.size(); ++j) {
      while (it < a[i].size() && ts[a[i][it]] < sum[i] + ts[j]) ++it;
      if (it < a[i].size() && ts[a[i][it]] == sum[i] + ts[j]) prec[i][j] = a[i][it];
    }
  }
  vi d(1 << n);
  vvi v(1 << n);
  for (int i = 0; i < v.size(); ++i) {
    v[i].reserve(1000);
  }
  for (int i = 0; i < n; ++i) for (int x : a[i]) {
    v[1 << i].push_back(x);
  }
  for (int mask = 1; mask < (1 << n); ++mask) if (!v[mask].empty()) {
    ll curs = 0;
    for (int i = 0; i < n; ++i) {
      if (!(mask & (1 << i))) {
        int nmask = mask | (1 << i);
        for (int x : v[mask]) {
          if (prec[i][x] != -1) v[nmask].push_back(prec[i][x]);
        }
      } else {
        curs += sum[i];
      }
    }
/*    sort(v[mask].begin(), v[mask].end());
    ll curs = 0;
    for (int i = 0; i < n; ++i) {
      if (!(mask & (1 << i))) {
        int it = 0, nmask = mask | (1 << i);
        for (ll x : v[mask]) {
          while (it < a[i].size() && ts[a[i][it]] < sum[i] + ts[x]) ++it;
          if (it >= a[i].size()) break;
          if (ts[a[i][it]] == sum[i] + ts[x]) {
            v[nmask].push_back(a[i][it]);
          }
        }
      } else {
        curs += sum[i];
      }
    }*/
    if (curs == 0) d[mask] = 1;
  }
  for (int i = 0; i < n; ++i) for (auto& x : a[i]) x = ts[x];
  vi dd(1 << n);
  for (int mask = 1; mask < dd.size(); ++mask) {
    if (d[mask]) {
      dd[mask] = mask;
      for (int m1 = mask; m1 < dd.size(); m1 = (m1 + 1) | mask) if (dd[mask ^ m1]) {
        dd[m1] = mask;
      }
    }
  }
  if (!dd.back()) no();
  cout << "Yes\n";
  int cur = dd.size() - 1; 
  vi path;
  while (cur) {
    path.push_back(dd[cur]);
    cur ^= dd[cur];
  }
  vii res(n);
  for (int mask0 : path) {
    int mask = mask0;
    assert(d[mask] && !v[mask].empty());
    int x = ts[v[mask][0]];
    vi p, q;
    while (mask) {
      bool found = 0;
      for (int i = 0; i < n; ++i) if (mask & (1 << i)) if (binary_search(a[i].begin(), a[i].end(), x)) {
        p.push_back(i);
        q.push_back(x);
        mask ^= 1 << i;
        found = 1;
        x = x - sum[i];
        break;
      }
      assert(found);
    }
    for (int i = 0; i < p.size(); ++i) {
      int j = (i - 1 + p.size()) % p.size();
      res[p[i]] = pii(p[j], q[i]);
    }
  }
  for (int i = 0; i < n; ++i) cout << res[i].second << ' ' << res[i].first + 1 << endl;
  return 0;
}