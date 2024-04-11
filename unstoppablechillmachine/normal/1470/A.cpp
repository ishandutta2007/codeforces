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
    int n, m;
    cin >> n >> m;
    vector<int> guys(n);
    for (auto &it : guys) {
      cin >> it;
    }
    sort(guys.rbegin(), guys.rend());
    vector<int> have(m);
    for (auto &it : have) {
      cin >> it;
    }
    int ptr = 0, ans = 0;
    for (int i = 0; i < n; i++) {  
      if (ptr < m && guys[i] - 1 >= ptr) {
        ans += have[ptr];
        ptr++;  
      }
      else {
        ans += have[guys[i] - 1];
      }
    }
    cout << ans << '\n';
  }
}