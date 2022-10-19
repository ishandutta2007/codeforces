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

const int S = 2e5 + 10;
bitset<S> bt;
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  bt[0] = 1;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    bt |= (bt << a[i]);
    sum += a[i];  
  }
  if (sum % 2 == 0 && bt[sum / 2]) {
    for (;;) {
      int pos = -1;
      for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
          pos = i;
          break;
        }
      }
      if (pos != -1) {
        cout << 1 << '\n' << pos + 1 << '\n';
        exit(0);
      }
      for (int i = 0; i < n; i++) {
        a[i] /= 2;
      }
    }  
  }
  else {
    cout << 0 << '\n';
  }
}