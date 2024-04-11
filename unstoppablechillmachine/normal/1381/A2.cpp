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
    vector<char> a(n), b(n);
    for (auto &it : a) {
      cin >> it;
    }
    for (auto &it : b) {
      cin >> it;
    }
    vector<int> ans;
    int rev = 0;
    int l = 0, r = n - 1, ptr = n - 1;
    while (r > l) {
      if (rev) {
        if ((a[l] ^ rev) != b[ptr]) {
          if (a[r] == a[l]) {
            ans.pb(ptr + 1);
          }
          else {
            ans.pb(1);
            ans.pb(ptr + 1);
          }
          rev ^= 1;
          r--;
        }
        else {
          l++;
        }
      }
      else {
        if ((a[r] ^ rev) != b[ptr]) {
          if (a[l] == a[r]) {
            ans.pb(ptr + 1);
          }
          else {
            ans.pb(1);
            ans.pb(ptr + 1);
          }
          rev ^= 1;
          l++;
        }
        else {
          r--;
        }
      }
      ptr--;
    }
    if ((a[l] ^ rev) != b[0]) {
      ans.pb(1);
    } 
    cout << SZ(ans) << ' ';
    for (auto it : ans) {
      cout << it << ' ';
    }
    cout << '\n';
  }  
}