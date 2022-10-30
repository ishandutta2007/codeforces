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

int d (int x) {
  int s = 0;
  while (x) {
    s += x % 10;
    x /= 10;
  }
  return s;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi v;
  for (int i = max(1, n - 100); i < n; ++i) {
    if (i + d(i) == n) v.push_back(i);
  }
  cout << v.size() << endl;
  for (int i : v) cout << i << ' ';
  return 0;
}