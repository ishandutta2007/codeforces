#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int l = 1, r = n + 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    int csum = 0, mx_len = 0;
    vector<int> kek = {0}, pos = {0};
    for (int i = 1; i <= n; i++) {
      if (a[i] >= mid) {
        csum++;
      }
      else {
        csum--;
      }
      if (kek.back() < csum) {
        int l = -1, r = SZ(kek) - 1;
        while (r - l > 1) {
          int md = (l + r) / 2;
          if (kek[md] < csum) {
            r = md;
          }
          else {
            l = md;
          }
        }
        mx_len = max(mx_len, i - pos[r]);
      }
      if (csum < kek.back()) {
        kek.pb(csum);
        pos.pb(i);
      }
    }
    if (mx_len >= k) {
      l = mid;
    }
    else {
      r = mid;
    }
  }
  cout << l << '\n';
}