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
  int n, b, d;
  cin >> n >> d >> b;
  vi a(n), L(n), R(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    L[i] = max(0, i / (d + 1));
    R[i] = min(n-1, n-1 - (n-1-i) / (d + 1));
//    cerr << L[i] << ' ' << R[i] << endl;
  }
  int l = -1, r = n / 2;
  while (r - l > 1) {
    int m = (l + r) / 2;
    vii q;
    int it = 0, j = 0, fail = 0;
    for (int i = m; i < n - m; ++i) {
      while (it < n && L[it] <= i) {
        q.emplace_back(a[it], R[it]);
        ++it;
      }
      while (j < q.size() && q[j].second < i) ++j;
      int rem = b;
      while (rem && j < q.size()) {
        int mi = min(rem, q[j].first);
        rem -= mi;
        q[j].first -= mi;
        if (q[j].first == 0) ++j;
      }
      if (rem) {
        fail = 1; break;
      }
    }
    if (fail) l = m;
    else r = m;
  }
  cout << r << endl;
  return 0;
}