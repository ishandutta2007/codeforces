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

bool ok(int n) {
  for (int i = 2; i * i <= n; ++i) if (n % i == 0) return 1;
  return 0;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    cin >> n;
    //cerr << t << ' ' << n << endl;
    vi a(n);
    int s = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      s += a[i];
    }
    //cerr << t << ' ' << n << ' ' << s << endl;
    if (ok(s)) {
      cout << n << endl;
      for (int i = 0; i < n; ++i) cout << i + 1 << ' ';
      cout << endl;
      continue;
    }
    for (int i = 0; i < n; ++i) {
      int x = s - a[i];
      //cerr << t << ' ' << s << ' ' << x << endl;
      if (x % 2 == 0 && x != 2) {
        cout << n-1 << endl;
        for (int j = 0; j < n; ++j) if (j != i) cout << j + 1 << ' ';
        cout << endl;
        break;
      }
    }
    //assert(0);
  }
  return 0;
}