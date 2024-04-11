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
    vector<int> a(n);
    for (auto& x : a) {
      cin >> x;
    }
    if (is_sorted(all(a))) {
      cout << 0 << '\n';
    } else if (a[0] == 1 || a.back() == n) {
      cout << 1 << '\n';
    } else {
      if (a[0] == n && a.back() == 1) {
        cout << 3 << '\n';
      }
      else {
        cout << 2 << '\n';
      }
    }
  }
}