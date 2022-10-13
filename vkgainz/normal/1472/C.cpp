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
const int MX = 3e5+5;

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
      cin >> a[i];
    vector<ll> ans(n);
    ll ret = 0;
    ans[n-1] = a[n-1];
    ret = max(ret, ans[n-1]);
    for(int i=n-2;i>=0;i--) {
      int nxt = i + a[i];
      if(nxt>=n) ans[i] = a[i];
      else ans[i] = a[i] + ans[nxt];
      ret = max(ret, ans[i]);
    }
    cout << ret << "\n";
  }
}