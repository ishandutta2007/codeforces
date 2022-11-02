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

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vi l(n + 1), r(n + 1);
  for (int i = 0; i < n; ++i) l[i + 1] = l[i] | a[i];
  for (int i = n - 1; i >= 0; --i) r[i] = r[i + 1] | a[i];
  pii ma(0, 0);
  for (int i = 0; i < n; ++i) {
    int y = l[i] | r[i + 1];
    ma = max(ma, pii((a[i] | y) - y, i));
  }
  cout << a[ma.second];
  for (int i = 0; i < n; ++i) if (i != ma.second) cout << ' ' << a[i];
  cout << endl;
  //cout << ma << endl;
  return 0;
}