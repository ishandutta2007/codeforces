#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
typedef long double ld;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 1e6 + 5;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<int> a(n);
  for(auto &a : a) cin >> a, --a;
  vector<int> dp(n+1);
  vector<int> f(n);
  vector<int> st(n, n+1), en(n, 0);
  for(int i=0;i<n;i++) {
    st[a[i]] = min(st[a[i]], i);
    en[a[i]] = max(en[a[i]], i);
  }
  for(int i=n-1;i>=0;i--) {
    ++f[a[i]];
    dp[i] = dp[i+1];
    dp[i] = max(dp[i], f[a[i]]);
    if(st[a[i]] == i)
      dp[i] = max(dp[i], f[a[i]] + dp[en[a[i]]+1]);
  }
  cout << n - dp[0] << "\n";
}