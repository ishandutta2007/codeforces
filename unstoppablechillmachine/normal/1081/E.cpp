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
  cin >> n;
  vector<int> a(n / 2);
  for (int i = 0; i < n / 2; i++) {
    cin >> a[i];
  }
  int cur = 0;  
  vector<int> ans;
  for (int i = 0; i < n / 2; i++) {
    int mn = 1e18;
    for (int j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        int rz = j, sum = a[i] / j;
        if ((sum - rz) & 1) {
          continue;
        }
        int A = (sum - rz) / 2;
        if (A * A > cur) {
          mn = min(mn, A * A);
        }
      }
    }
    //cout << cur << ' ' << i << ' ' << mn << '\n';
    if (mn == 1e18) {
      cout << "No\n";
      exit(0);
    }
    ans.pb(mn - cur);
    ans.pb(a[i]);
    cur = mn + a[i];
  }
  cout << "Yes\n";
  for (auto it : ans) {
    cout << it << ' ';
  }
}