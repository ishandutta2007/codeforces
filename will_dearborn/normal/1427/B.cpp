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
    vii ts;
    for (int i = 0; i < n; ++i) if (s[i] == 'L') {
      int j = i;
      while (j < n && s[j] == 'L') ++j;
      if (i != 0 && j != n) ts.emplace_back(j - i, i);
      i = j - 1;
    }
    sort(ts.begin(), ts.end());
    for (pii p : ts) {
      int d = min(k, p.first);
      for (int i = p.second; i < p.second + d; ++i) s[i] = 'W';
      k -= d;
    }
    for (int i = 0; i < n; ++i) if (s[i] == 'W') {
      --i;
      while (i >= 0 && k) {
        s[i] = 'W';
        --k;
        --i;
      }
      break;
    }
    for (int i = 0; i < n; ++i) if (s[i] == 'L') {
      while (i < n && k) {
        s[i] = 'W';
        --k;
        ++i;
      }
      break;
    }
/*    for (int i = n - 2; i >= 0 && k; --i) if (s[i] == 'L' && s[i + 1] == 'W') {
      s[i] = 'W';
      --k;
    }
    for (int i = 0; i < n && k; ++i) if (s[i] == 'L') {
      s[i] = 'W';
      --k;
    }*/
    int res = 0;
    for (int i = n - 1; i >= 0; --i) if (s[i] == 'W') {
      ++res;
      if (i && s[i - 1] == 'W') ++res;
    }
    cout << res << '\n';
//    cerr << k << ' ' << s << endl;
  }
  return 0;
}