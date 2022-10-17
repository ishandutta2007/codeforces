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
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] != b[i]) {
        ans.pb(i + 1);
        ans.pb(1);
        ans.pb(i + 1);
      }
    }
    cout << SZ(ans) << ' ';
    for (auto it : ans) {
      cout << it << ' ';
    }
    cout << '\n';
  }  
}