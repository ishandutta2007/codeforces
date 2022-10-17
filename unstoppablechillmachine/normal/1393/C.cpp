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
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    vector<int> pr(n + 2);
    for (int i = 1; i <= n; i++) {
      pr[cnt[i]]++;
    }
    for (int i = n - 1; i >= 1; i--) {
      pr[i] += pr[i + 1];
    }
    int l = 1, r = n;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      int can = 0;
      bool ok = true;
      for (int i = 1; i <= n; i++) {
        if (pr[i] == 0) {
          break;
        }
        if (pr[i] >= mid) {
          can += pr[i] - mid;
        }
        else if (pr[i + 1] != 0) {
          if (mid - pr[i] > can) {
            ok = false;
            break;
          }
          can -= mid - pr[i];
        }
      }
      if (ok) {
        l = mid;
      }
      else {
        r = mid;
      }
    }
    cout << l - 1 << '\n';
  }  
}