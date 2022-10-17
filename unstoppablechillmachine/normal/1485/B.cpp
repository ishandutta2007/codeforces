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
 
const int N = 1e5 + 10;
int a[N], pref[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, q, k;
  cin >> n >> q >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i < n; i++) {
    pref[i] = pref[i - 1] + (a[i + 1] - a[i - 1] - 2);
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << k - 1 << '\n';
      continue;
    }
    int cnt = pref[r - 1] - pref[l];
    //cerr << "KEK " << cnt << '\n';
    cnt += a[l + 1] - 2;
    cnt += (k - a[r - 1] - 1);
    cout << cnt << '\n';
  }
}