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
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    sort(all(a));
    if (a.back() <= d || a[0] + a[1] <= d) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
}