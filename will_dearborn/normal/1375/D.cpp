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

int mex(const vi& a) {
  vi w(a.size() + 1);
  for (int x : a) w[x] = 1;
  for (int i = 0; i < w.size(); ++i) if (!w[i]) return i;
  return w.size();
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vi res;
    while (1) {
      int x = mex(a);
      if (x < n) {
        res.push_back(x);
        a[x] = x;
      } else {
        bool ok = 1;
        for (int i = 0; i < a.size(); ++i) {
          if (a[i] != i) {
            ok = 0;
            res.push_back(i);
            a[i] = x;
            break;
          }
        }
        if (ok) break;
      }
    }
    cout << res.size() << '\n';
    for (int x : res) cout << x + 1 << ' ';
    cout << "\n";
  }
  return 0;
}