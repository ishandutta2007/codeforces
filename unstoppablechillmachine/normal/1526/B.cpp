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
 
const int MX = 1e5 + 10;
bool can[MX];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  can[0] = 1;
  for (int i = 1; i <= 1e5; i++) {
    for (int cur = 11; cur <= i; cur = cur * 10 + 1) {
      if (can[i - cur]) {
        can[i] = true;
      }
    }
  }
  while (T--) {
    int n;
    cin >> n;
    if (n >= 1e5) {
      cout << "YES\n";
    }
    else {
      cout << (can[n] ? "YES\n" : "NO\n");
    }
  }
}