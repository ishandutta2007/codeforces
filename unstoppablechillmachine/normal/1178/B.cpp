#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

const int INF = 1e9 + 10;

signed main() {
  ios_base::sync_with_stdio(0);
  string s;
  cin >> s;
  vector<int> pref(SZ(s)), suf(SZ(s));
  pref[0] = 0;
  int cnt = (s[0] == 'v' ? 1 : 0);
  for (int i = 1; i < SZ(s); i++) {
    pref[i] = pref[i - 1];
    if (s[i] == 'v') {
      cnt++;
      pref[i] += (cnt > 1);
    }
    else {
      cnt = 0;
    }
  }
  suf[SZ(s) - 1] = 0;
  cnt = (s.back() == 'v' ? 1 : 0);
  for (int i = SZ(s) - 2; i >= 0; i--) {
    suf[i] = suf[i + 1];
    if (s[i] == 'v') {
      cnt++;
      suf[i] += (cnt > 1);
    }
    else {
      cnt = 0;
    }
  }
  int ans = 0;
  for (int i = 0; i < SZ(s); i++) {
    if (s[i] == 'o' && i > 0 && i + 1 < SZ(s)) {
      ans += pref[i - 1] * suf[i + 1];
    }
  }
  cout << ans << '\n';
}