#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second
 
const int N = 1e6 + 10;
int a[N], b[N];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, need;
  cin >> n >> need;
  if (need < n * (n + 1) / 2) {
    cout << -1 << '\n';
    exit(0);
  }
  for (int i = 1; i <= n; i++) {
    a[i] = b[i] = i;
  }
  int l = 1, r = n;
  need -= n * (n + 1) / 2;
  while (l < r) {
    if (need <= r - l) {
      swap(b[l], b[l + need]);
      break;
    }
    else {
      swap(b[l], b[r]);
      need -= r - l;
      l++, r--;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += max(a[i], b[i]);
  }
  cout << ans << '\n';
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
  for (int i = 1; i <= n; i++) {
    cout << b[i] << ' ';
  }
  cout << '\n';
}