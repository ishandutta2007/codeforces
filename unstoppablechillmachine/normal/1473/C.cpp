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
    int lst = 2 * k - n;
    for (int i = 1; i < lst; i++) {
      cout << i << ' ';
    }
    for (int i = k; i >= lst; i--) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}