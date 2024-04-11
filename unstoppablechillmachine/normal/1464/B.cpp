#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

const int N = 1e5 + 10;
int pref[N][2], suf[N][2];
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  string s;
  cin >> s;
  int x, y;
  cin >> x >> y;
  int n = SZ(s);
  for (int i = 1; i <= n; i++) {
    pref[i][0] = pref[i - 1][0];
    pref[i][1] = pref[i - 1][1];
    if (s[i - 1] != '?') {
      pref[i][s[i - 1] - '0']++;
    }
  }
  for (int i = n; i >= 1; i--) {
    suf[i][0] = suf[i + 1][0];
    suf[i][1] = suf[i + 1][1];
    if (s[i - 1] != '?') {
      suf[i][s[i - 1] - '0']++;
    }
  }
  int other = 0;
  vector<pair<int, int>> kek;
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == '?') {
      kek.pb({pref[i - 1][1] * y + suf[i + 1][1] * x, pref[i - 1][0] * x + suf[i + 1][0] * y});
    }
    else {
      if (s[i - 1] == '1') {
        other += x * pref[i - 1][0];
      }
      else {
        other += y * pref[i - 1][1];
      }
    }
  }
  int csum = 0;
  for (auto it : kek) {
    csum += it.F;
  }
  int ans = csum;
  for (int len = 1; len <= SZ(kek); len++) {
    csum -= kek[len - 1].F;
    csum += kek[len - 1].S;
    //csum -= (len - 1) * y;
    //csum += (SZ(kek) - len) * x;
    //cout << csum << '\n';
    ans = min(ans, csum + y * len * (SZ(kek) - len));
  }
  csum = 0;
  for (auto it : kek) {
    csum += it.S;
  }
  for (int len = 1; len <= SZ(kek); len++) {
    csum -= kek[len - 1].S;
    csum += kek[len - 1].F;
    //csum -= (len - 1) * x;
    //csum += (SZ(kek) - len) *  y;
    //cout << csum << '\n';
    ans = min(ans, csum + x * len * (SZ(kek) - len));
  }
  cout << ans + other << '\n';
}