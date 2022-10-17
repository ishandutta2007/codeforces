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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  string s;
  cin >> n >> s >> s;
  if (s == "week") {
    int cur = 5, ans = 0;
    for (int i = 0; i < 366; i++) {
      if (cur == n) {
        ans++;
      }
      if (cur == 7) {
        cur = 1;
      }
      else {
        cur++;
      }
    }
    cout << ans << '\n';
  } 
  else {
    if (n <= 29) {
      cout << 12 << '\n';
    }
    else if (n <= 30) {
      cout << 11 << '\n';
    }
    else {
      cout << 7 << '\n';
    }
  }
}