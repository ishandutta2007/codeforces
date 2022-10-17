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
  auto is_sq = [](int n) {
    int x = sqrtl(n);
    return (x * x == n);
  };

  while (T--) {
    int n;
    cin >> n;
    if ((n % 2 == 0 && is_sq(n / 2)) || (n % 4 == 0 && is_sq(n / 4))) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
}