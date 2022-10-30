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
  int ma = -1e7;
  vi issq(2e6);
  for (int i = 0; i * i < issq.size(); ++i) issq[i*i] = 1;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] < 0 || !issq[a[i]]) ma = max(ma, a[i]);
  }
  cout << ma << endl;
  return 0;
}