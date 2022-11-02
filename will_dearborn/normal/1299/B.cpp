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

void no() {
  cout << "NO\n";
  exit(0);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  if (n % 2) no();
  for (int i = 0; i < n; ++i) {
    int j = (i + n / 2) % n;
    int i1 = (i + 1) % n;
    int j1 = (i1 + n / 2) % n;
    if (x[i] + x[j] != x[i1] + x[j1] || y[i] + y[j] != y[i1] + y[j1]) no();
  }
  cout << "YES\n";
  return 0;
}