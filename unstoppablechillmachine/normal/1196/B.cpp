#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

signed main() {
  ios_base::sync_with_stdio(0);
  int q;
  cin >> q;
  while (q--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &it : a) {
      cin >> it;
    }
    int cur = 0, cnt = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      cur += a[i];
      if (cnt + 1 < k && cur % 2 == 1) {
        ans.pb(i + 1);
        cnt++;
        cur = 0;
      }
    }
    if (cnt == k - 1 && cur % 2 == 1) {
      ans.pb(n);
      cout << "YES\n";
      for (auto it : ans) {
        cout << it << ' ';
      }
      cout << '\n';
    }
    else {
      cout << "NO\n";
    }
  }  
}