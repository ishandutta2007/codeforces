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
    for (auto &it : a) {
      cin >> it;
    }
    sort(all(a));
    for (int i = 0; i < 2 * n; i++) {
      if (i % 2 == 0) {
        cout << a[i / 2] << ' ';
      }
      else {
        cout << a[n + i / 2] << ' ';
      }
    }
    cout << '\n';
  }
}