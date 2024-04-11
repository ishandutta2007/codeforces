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
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x]++; 
    }
    vector<int> kek;
    for (auto it : cnt) {
      kek.pb(it.S);
    }
    sort(all(kek));
    int cp = 0;
    int ans = 1e18;
    for (int i = 0; i < SZ(kek); i++) {
      ans = min(ans, cp + (n - cp) - kek[i] * (SZ(kek) - i));
      cp += kek[i];
    }
    cout << ans << '\n';
  }
}