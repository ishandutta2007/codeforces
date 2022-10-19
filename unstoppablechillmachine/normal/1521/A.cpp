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
    int A, B;
    cin >> A >> B;
    if (B == 1) {
      cout << "NO\n";
    }
    else {
      cout << "YES\n" << A << ' ' << A * (2 * B - 1) << ' ' << 2 * A * B << '\n';
    }
  }
}