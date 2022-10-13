#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
typedef tree<
pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set;
const int MX = 5e5 + 5;

int main() {
  int n, m; cin >> n >> m;
  ll x[n];
  for(int i=0;i<n;i++) cin >> x[i];
  ll p[m];
  for(int i=0;i<m;i++) cin >> p[i];
  ll g = 0LL;
  for(int i=0;i<n-1;i++) g = __gcd(x[i+1]-x[i], g);
  pair<ll, ll> ans = {-1, -1};
  for(int i=0;i<m;i++) {
    if(g%p[i]==0) {
      ans = {x[0], i+1};
    }
  }
  if(ans.s==-1) {
    cout << "NO" << "\n";
  }
  else {
    cout << "YES" << "\n";
    cout << ans.f << " " << ans.s << "\n";
  }
}