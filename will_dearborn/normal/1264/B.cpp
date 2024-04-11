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
  vi v(4);
  cin >> v[0] >> v[1] >> v[2] >> v[3];
  int n = v[0] + v[1] + v[2] + v[3];
  if (n <= 1) {
    cout << "YES\n";
    for (int i = 0; i < 4; ++i) if (v[i]) cout << i << endl;
    return 0;
  }
  for (int s = 0; s < 4; ++s) for (int e = 0; e < 4; ++e) {
    vi res(n);
    res[0] = s;
    res[n - 1] = e;
    vi rem = v;
    --rem[s]; --rem[e];
    for (int i = 1; i + 1 < n; ++i) {
      if (res[i - 1] == 0) res[i] = 1;
      else if (res[i - 1] == 3) res[i] = 2;
      else if (res[i - 1] == 1) {
        if (rem[0] > 0) res[i] = 0;
        else res[i] = 2;
      } else {
        assert(res[i - 1] == 2);
        if (rem[3] > 0) res[i] = 3;
        else res[i] = 1;
      }
      --rem[res[i]];
    }
    bool fail = 0;
    for (int i = 0; i < 4; ++i) if (rem[i] != 0) fail = 1;
    for (int i = 0; i + 1 < n; ++i) if (abs(res[i] - res[i + 1]) != 1) fail = 1;
    if (!fail) {
      cout << "YES\n";
      for (int x : res) cout << x << ' ';
      cout << endl;
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}