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
    int A, B, n;
    cin >> A >> B >> n;
    vector<int> a(n), b(n);
    int mx = 0;
    for (auto &x : a) {
      cin >> x;
      mx = max(mx, x);
    }
    for (auto &x : b) {
      cin >> x;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += (b[i] + A - 1) / A * a[i];
    }
    sum -= mx;
    if (sum < B) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
}