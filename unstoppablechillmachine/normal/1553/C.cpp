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
 
int get_bit(int mask, int x) {
  return (mask >> x) & 1;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = SZ(s);
    int ans = 10;
    for (int mask = 0; mask < (1 << n); mask++) {
      bool good = true;
      for (int i = 0; i < n; i++) {
        if (s[i] != '?' && s[i] - '0' != get_bit(mask, i)) {
          good = false;
          break;
        }
      }
      if (!good) {
        continue; 
      }
      int sum1 = 0, sum2 = 0, ost1 = 5, ost2 = 5;
      for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
          if (get_bit(mask, i) == 1) {
            sum1++;
          } 
          ost1--;
        } else {
          if (get_bit(mask, i) == 1) {
            sum2++;
          } 
          ost2--;
        }
        if (sum1 + ost1 < sum2 || sum2 + ost2 < sum1) {
          //cout << mask << ' ' << sum1 << ' ' << ost1 << ' ' << sum2 << ' ' << ost2 << '\n';
          ans = min(ans, i + 1);
          break;
        }
      }
    }
    cout << ans << '\n';
  }
}