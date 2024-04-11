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
    multiset<int> st;
    set<int> stu;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      st.insert(a[i]);
      stu.insert(a[i]);
    }
    vector<int> ans(n + 1);
    if (SZ(stu) == n) {
      ans[1] = 1;
    }
    int l = 1, r = n;
    for (int len = n; len >= 1; len--) {
      if (*st.begin() != n - len + 1) {
        break;
      }
      ans[len] = 1;
      if (a[l] == n - len + 1) {
        l++;
      }
      else if (a[r] == n - len + 1) {
        r--;
      }
      else {
        break;
      }
      st.erase(st.find(n - len + 1));
      if (st.count(n - len + 1)) {
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i];
    }
    cout << '\n';
  }
}