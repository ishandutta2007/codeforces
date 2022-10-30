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
  vi c(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ++c[a[i]];
  }
  vi v;
  for (int i = 1; i <= n; ++i) if (!c[i]) v.push_back(i);
  int it = 0;
  vi w(n+1);
  cout << v.size() << endl;
  for (int i = 0; i < n; ++i) {
    if (!w[a[i]] && (c[a[i]] == 1 || it == v.size() || v[it] > a[i])) {
      cout << a[i] << ' ';
      w[a[i]] = 1;
    } else {
      cout << v[it] << ' ';
      --c[a[i]];
      ++it;
    }
  }
  return 0;
}