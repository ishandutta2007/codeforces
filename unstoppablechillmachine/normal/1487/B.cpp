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
    int n, k;
    cin >> n >> k;
    k--;
    if (n % 2 == 0) {
      cout << k % n + 1 << '\n';
    }
    else {
      cout << ((k / (n / 2)) * (n / 2 + 1) + k % (n / 2)) % n + 1 << '\n';
    }
  }
}