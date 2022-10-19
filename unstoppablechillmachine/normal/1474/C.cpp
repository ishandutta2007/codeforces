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
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
      cin >> a[i];
    }
    sort(all(a));
    bool fnd = false;
    for (int i = 0; i < 2 * n - 1; i++) {
      multiset<int> st;
      for (int j = 0; j < 2 * n - 1; j++) {
        if (i != j) {
          st.insert(a[j]);
        }
      }
      vector<pair<int, int>> pars;
      bool ok = true;
      int lst = a.back();
      for (int j = 0; j < n - 1; j++) {
        int A = *st.rbegin();
        st.erase(--st.end());
        if (st.find(lst - A) == st.end()) {
          ok = false;
          break;
        }
        pars.pb({A, lst - A});
        st.erase(st.find({lst - A}));
        lst = A;
      }
      if (!ok) {
        continue;
      }  
      int x = a[i] + a.back();
      pars.insert(pars.begin(), {a[i], a.back()});
      cout << "YES\n";
      cout << x << '\n';
      for (auto it : pars) {
        cout << it.F << ' ' << it.S << '\n';
      }  
      fnd = true;
      break;
    } 
    if (!fnd) {
      cout << "NO\n";
      continue;
    }
  }
}