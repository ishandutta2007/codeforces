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
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    bool fail = 0;
    for (int tt = 0; tt < 2; ++tt) {
      for (int i = 0; i + k < n; ++i) {
        if (s[i] != '?') {
          if (s[i + k] == '?') s[i + k] = s[i];
          else if (s[i] != s[i + k]) fail = 1;
        }
      }
      reverse(s.begin(), s.end());
    }
    vi c(2);
    for (int i = 0; i < k; ++i) if (s[i] != '?') ++c[s[i]-'0'];
    if (!fail && c[0] <= k / 2 && c[1] <= k / 2) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}