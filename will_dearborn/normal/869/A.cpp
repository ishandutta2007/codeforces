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
  vi a(n), b(n), w(3e6);
  for (int i = 0; i < n; ++i) {cin >> a[i]; w[a[i]] = 1;}
  for (int i = 0; i < n; ++i) {cin >> b[i]; w[b[i]] = 1;}
  int c = 0;
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (w[a[i]^b[j]]) ++c;
  if (c % 2 == 0) cout << "Karen\n";
  else cout << "Koyomi\n";
//  cerr << c << endl;
  return 0;
}