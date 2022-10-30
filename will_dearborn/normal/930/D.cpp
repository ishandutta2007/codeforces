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

const int MAX = 1e5;

void upd(vii& v) {
  sort(v.begin(), v.end());
  int mi = 1e9;
  vii res;
  for (pii p : v) {
    if (p.second < mi) {
      mi = p.second;
      res.push_back(p);
    }
  }
  v.swap(res);
}

int geth(const vii& v, int x) {
  int it = lower_bound(v.begin(), v.end(), pii(x + 1, -1e9)) - v.begin();
  if (it == 0) return 1e9;
  return v[it - 1].second;
}

void out(vii v) {
  for (pii p : v) cerr << p.first << ' ' << p.second << endl;
}

ll f(vii v) {
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  if (v.size() < 4) return 0;
  vi x;
  vii dl, dr, ul, ur;
  for (int i = 0; i < v.size(); ++i) {
    dl.emplace_back(v[i].first, v[i].second);
    dr.emplace_back(MAX - v[i].first, v[i].second);
    ul.emplace_back(v[i].first, MAX - v[i].second);
    ur.emplace_back(MAX - v[i].first, MAX - v[i].second);
    x.push_back(v[i].first);
//    x.push_back(v[i].first - 1);
  }
  upd(dl);
  upd(dr);
  upd(ul);
  upd(ur);
  sort(x.begin(), x.end());
  x.resize(unique(x.begin(), x.end()) - x.begin());
  ll res = 0;
  for (int i = 0; i + 1 < x.size(); ++i) {
    int dw = max(geth(dl, x[i]), geth(dr, MAX - x[i] - 1));
    int up = MAX - max(geth(ul, x[i]), geth(ur, MAX - x[i] - 1));
    if (up >= dw) {
      res += (x[i + 1] - x[i]) * (ll)(up - dw);
    }
//    cerr << x[i] << ' ' << x[i+1] << ' ' << dw << ' ' << up << ' ' << geth(dl, x[i]) << endl;
  }
//  out(v); cerr << res << endl;
  return res;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  while (cin >> n) {
  vi x(n), y(n);
  vii v1, v2;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    if ((y[i] - x[i]) % 2 == 0) {
      v1.emplace_back((x[i] + y[i]) / 2, (x[i] - y[i]) / 2);
    } else {
      v2.emplace_back((x[i] + 1 + y[i]) / 2, (x[i] + 1 - y[i]) / 2);
    }
  }
  cout << f(v1) + f(v2) << endl;
  }
  return 0;
}