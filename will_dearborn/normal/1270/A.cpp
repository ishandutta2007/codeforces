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

int f(int t) {
  int ma = 0;
  for (int i = 0; i < t; ++i) {
    int x;
    cin >> x;
    ma = max(ma, x);
  }
  return ma;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int ma1 = f(k1);
    int ma2 = f(k2);
    if (ma1 > ma2) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}