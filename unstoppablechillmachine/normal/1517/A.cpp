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
    if (n % 2050 != 0) {
      cout << -1 << '\n';
      continue;
    }
    n /= 2050;
    int answer = 0;
    while (n > 0) {
      answer += n % 10;
      n /= 10;
    }
    cout << answer << '\n';
  }  
}