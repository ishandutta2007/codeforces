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

int f(int n, int p) {
  int res = 0;
  while (n) {
    n /= p;
    res += n;
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  vi erat(5001, 1);
  erat[0] = erat[1] = 0;
  for (int i = 2; i * i < erat.size(); ++i) if (erat[i])
    for (int j = i * i; j < erat.size(); j += i) erat[j] = 0;
  vi p;
  for (int i = 2; i < erat.size(); ++i) if (erat[i]) p.push_back(i);
  int n;
  cin >> n;
  vi c(5001);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    ++c[k];
  }
  vvi pw(5001, vi(p.size()));
  vl cpw(pw.size()), scpw(pw.size() + 1), sc(pw.size() + 1);
  for (int i = 0; i < pw.size(); ++i) {
    for (int j = 0; j < p.size(); ++j) {
      pw[i][j] = f(i, p[j]);
      cpw[i] += pw[i][j];
    }
    scpw[i + 1] = scpw[i] + c[i] * (ll)cpw[i];
    sc[i + 1] = sc[i] + c[i];
  }
  ll res = 0;
  for (int i = 0; i < c.size(); ++i) {
//    if (c[i]) cerr << i << ' ' << c[i] << ' ' << cpw[i] << endl;
    res += c[i] * (ll)cpw[i];
  }
//  cerr << res << endl;
  vi lca(c.size() - 1);
  for (int i = 0; i + 1 < (int)c.size(); ++i) {
    for (int j = p.size() - 1; j >= 0; --j) {
      lca[i] += min(pw[i][j], pw[i + 1][j]);
      if (pw[i][j] != pw[i + 1][j]) break;
    }
  }
  if (0) for (int l = 0; l < 100; ++l) for (int r = l + 1; r < 100; ++r) {
    int lc = lca[l];
    for (int i = l; i < r; ++i) lc = min(lc, lca[i]);
    int lc1 = 0;
    for (int j = p.size() - 1; j >= 0; --j) {
      lc1 += min(pw[l][j], pw[r][j]);
      if (pw[l][j] != pw[r][j]) break;
    }
    assert(lc == lc1);
  }
  for (int l = 2; l < (int)c.size(); ++l) {
    int len = cpw[l];
//    ll s1 = 0;
    for (int r = l; r < (int)c.size() && len > 0; ++r) {
      ll cand = 0;
      for (int i = l; i <= r; ++i) cand += c[i] * (ll)(cpw[i] - len);
      int l1 = len;
      for (int i = r + 1; i < (int)c.size(); ++i) {
        l1 = min(l1, lca[i - 1]);
        if (l1 == 0) {
          cand += scpw.back() - scpw[i] + (sc.back() - sc[i]) * (ll)len;
          break;
        }
        cand += c[i] * (ll)(cpw[i] - l1 + len - l1);
      }
      l1 = len;
      for (int i = l - 1; i >= 0; --i) {
        l1 = min(l1, lca[i]);
        if (l1 == 0) {
          cand += scpw[i + 1] + sc[i + 1] * (ll)len;
          break;
        }
        cand += c[i] * (ll)(cpw[i] - l1 + len - l1);
      }
      if (r + 1 < c.size()) {
//        s1 += (r - l + 1) * (ll)(len - lca[r]);
        len = min(len, lca[r]);
//        s1 += cpw[r + 1] - len;
      }
//      if (cand == 2) cerr << l << ' ' << r << ' ' << cand << endl;
      res = min(res, cand);
    }
  }
  cout << res << endl;
  return 0;
}