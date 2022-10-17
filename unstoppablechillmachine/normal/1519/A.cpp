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
    int a, b, d;
    cin >> a >> b >> d;
    if (a < b) {
      swap(a, b);
    }
    if ((d + 1) * b >= a) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
}