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

int d[55][55];

int main() {
  int n;
  cin >> n;
  vi c(101);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    c[x]++;
  }
  int cnt = 0, ma = 0;
  for (int i = 0; i < c.size(); ++i) {
    cnt += c[i] > 0;
    ma = max(ma, c[i]);
  }
  if (cnt == 2 && ma == n / 2) {
    cout << "YES\n";
    for (int i = 0; i < c.size(); ++i) if (c[i]) cout << i << ' ';
  } else {
    cout << "NO\n";
  }
  return 0;
}