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

vi f(string a) {
  vi s(a.size() + 1);
  for (int i = 0; i < a.size(); ++i) {
    s[i + 1] = s[i] + (a[i] != 'A');
  }
  return s;
}

vi g(string a) {
  vi l(a.size());
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == 'A') {
      if (i) l[i] = 1 + l[i-1];
      else l[i] = 1;
    }
  }
  return l;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  string a, b;
  cin >> a >> b;
  vi sa = f(a), sb = f(b);
  vi pa = g(a), pb = g(b);
  int T;
  cin >> T;
  for (int test = 0; test < T; ++test) {
    int l1,r1,l2,r2;
    cin >> l1 >> r1 >> l2 >> r2;
    --l1; --r1; --l2; --r2;
    int n = sa[r1 + 1] - sa[l1], m = sb[r2 + 1] - sb[l2];
    int k = std::min(pa[r1], r1 - l1 + 1), i = min(pb[r2], r2 - l2 + 1);
//    cerr << n << ' ' << m << ' ' << k << ' ' << i << endl;
    int d = k - i;
    if (((bool)(d % 3)) * 2 + n > m || k < i || (n - m) % 2 || (n == 0 && m > 0 && d == 0)) cout << "0";
    else cout << "1";
  }
  cout << endl;
  return 0;
}