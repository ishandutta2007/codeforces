#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree <pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update>
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 2e5 + 5;

int main() {
  int n, x; cin >> n >> x;
  int a[n];
  for(int i=0;i<n;i++) cin >> a[i];
  ll left[n+1], right[n+2];
  left[0] = 0LL;
  for(int i=1;i<=n;i++) {
    left[i] = max(0LL, 1LL*a[i-1]);
    left[i] = max(left[i], a[i-1]+left[i-1]);
  }
  right[n+1] = 0LL;
  for(int i=n;i>=0;i--) {
    right[i] = max(0LL, 1LL*a[i-1]);
    right[i] = max(right[i], a[i-1]+right[i+1]);
  }
  ll p[n];
  p[0] = 0LL;
  for(int i=1;i<=n;i++) {
    p[i] = p[i-1]+a[i-1];
  }
  ll mx = 0LL;
  ll ans = 0LL;
  for(int r=1;r<=n;r++) {
    //(p[r] - p[l])*x+left[l]+right[r+1] ==> (p[r]*x+right[r+1]) +max(left[l] - p[l]*x) for l<=r
    mx = max(mx, left[r] - p[r]*1LL*x);
    ans = max(ans, mx + p[r]*1LL*x+right[r+1]);
  }
  cout << ans << "\n";
}