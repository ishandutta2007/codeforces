#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi a(n);
  vi s(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    s[i + 1] = s[i] + (a[i] == 2);
  }
  int res = 1, c1 = 0;
  for (int i = 0; i <= n; ++i) {
    res = max(res, c1 + s[n] - s[i]);
    int ma = 0, sum = 0;
    for (int j = i; j < n; ++j) {
      sum += a[j] == 2;
      ma += a[j] == 1;
      ma = max(ma, sum);
      res = max(res, c1 + s[n] - s[j + 1] + ma);
    }
    if (i < n) c1 += a[i] == 1;
  }
  cout << res << endl;
  return 0;
}