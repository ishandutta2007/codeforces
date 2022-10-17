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
  //x, y -> 
  //x, y - x ->
  //y, y - x ->
  //y, -x ->
  //y, -x - y ->
  //-x, -x - y ->
  //-x, -y

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
    }
    cout << 3 * n << '\n';
    for (int i = 1; i + 1 <= n; i += 2) {
      cout << 2 << ' ' << i << ' ' << i + 1 << '\n';
      cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
      cout << 2 << ' ' << i << ' ' << i + 1 << '\n';
      cout << 2 << ' ' << i << ' ' << i + 1 << '\n';
      cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
      cout << 2 << ' ' << i << ' ' << i + 1 << '\n';
    }
  }
}