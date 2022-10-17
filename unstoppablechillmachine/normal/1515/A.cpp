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
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (auto &it : w) {
      cin >> it;
    }
    sort(all(w));
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += w[i];
      if (sum == x) {
        reverse(w.begin() + i, w.end());
      }
    }
    if (sum == x) {
      cout << "NO\n";
    }
    else {
      cout << "YES\n";
      for (auto it : w) {
        cout << it << ' ';
      }
      cout << '\n';
    }
  }
}