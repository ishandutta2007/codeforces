#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
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
  int n, a, b;
  cin >> n >> a >> b;
  for (int i = 0; i <= n; i += a) if ((n - i) % b == 0) {
    int it = 1;
    for (int x = 0; x < i / a; ++x) {
      for (int j = 0; j < a; ++j) {
        cout << it + (j + 1) % a << ' ';
      }
      it += a;
    }
    for (int y = 0; y < (n - i) / b; ++y) {
      for (int j = 0; j < b; ++j) {
        cout << it + (j + 1) % b << ' ';
      }
      it += b;
    }
    return 0;
  }
  cout << -1 << endl;
  return 0;
}