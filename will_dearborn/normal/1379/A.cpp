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

string x = "abacaba";
int calc(const string& s) {
  int c = 0;
  for (int i = 0; i + x.size() <= s.size(); ++i) {
    if (s.substr(i, x.size()) == x) ++c;
  }
  return c;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int c = calc(s);
    if (c > 1) cout << "no\n";
    else if (c == 1) {
      for (int i = 0; i < n; ++i) if (s[i] == '?') s[i] = 'z';
      cout << "yes\n" << s << '\n';
    } else {
      bool ok = 0;
      for (int i = 0; i + x.size() <= n; ++i) {
        ok = 1;
        for (int j = 0; j < x.size(); ++j) {
          if (s[i + j] != x[j]) {
            if (s[i + j] != '?') ok = 0;
          }
        }
        if (ok) {
          string s1 = s;
          for (int j = 0; j < x.size(); ++j) s1[i + j] = x[j];
          if (calc(s1) == 1) {
            s = s1;
            break;
          } else ok = 0;
        }
      }
      if (!ok) {
        cout << "no\n";
      } else {
        for (int i = 0; i < n; ++i) if (s[i] == '?') s[i] = 'z';
        cout << "yes\n" << s << '\n';
      }
    }
  }
  return 0;
}