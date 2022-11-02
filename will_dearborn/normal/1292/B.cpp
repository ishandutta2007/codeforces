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

const ll MAX = 2e16;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  vl x(1), y(1);
  ll ax,ay,bx,by,xs,ys,t;
  cin >> x[0] >> y[0] >> ax >> ay >> bx >> by >> xs >> ys >> t;
  while (x.back() < MAX && y.back() < MAX) {
    ll nx = bx + ax * x.back();
    ll ny = by + ay * y.back();
    x.push_back(min(MAX, nx));
    y.push_back(min(MAX, ny));
  }
  cerr << x.size() << endl;
  ll res = 0;
  for (int s1 = 0; s1 < x.size(); ++s1) for (int e1 = 0; e1 < x.size(); ++e1) {
    vi was(x.size());
    ll rem = t;
    ll cx = xs, cy = ys;
    ll cnt = 0;
    for (int i = s1; rem >= 0;) {
      if (!was[i]) {
        ll d = abs(cx - x[i]) + abs(cy - y[i]);
        rem -= d;
        cx = x[i];
        cy = y[i];
        was[i] = 1;
        if (rem >= 0) ++cnt;
      }
      if (i == e1) break;
      if (i < e1) ++i;
      else --i;
    }
    res = max(res, cnt);
    for (int s2 = 0; s2 < x.size(); ++s2) for (int e2 = 0; e2 < x.size(); ++e2) {
      for (int i = s2; rem >= 0;) {
        if (!was[i]) {
          ll d = abs(cx - x[i]) + abs(cy - y[i]);
          rem -= d;
          cx = x[i];
          cy = y[i];
          was[i] = 1;
          if (rem >= 0) ++cnt;
        }
        if (i == e2) break;
        if (i < e2) ++i;
        else --i;
      }
      res = max(res, cnt);
    }
  }
  cout << res << endl;
  return 0;
}