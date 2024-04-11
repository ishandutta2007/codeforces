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
const int MX = 2e5+5;

int main() {
  int n; cin >> n;
  ll t; cin >> t;
  vector<ll> a(n+1);
  a[0] = 0LL;
  for(int i=1;i<=n;i++) {
    cin >> a[i];
    a[i] += a[i-1];
  }
  ordered_set o;
  ll ans = 0;
  for(int i=0;i<=n;i++) {
    pair<ll, int> need = {a[i]-t, i};
    int x = o.order_of_key(need);
    ans+=o.size()-x;
    o.insert({a[i], i});
  }
  cout << ans;
}