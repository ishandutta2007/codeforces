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
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 3e5 + 5;
#define MAXN 200005
#define MAXE 400010
#define  INF (1<<29)
ll MOD = 998244353;
ll inv(ll b, int p = MOD - 2) {
  if(p == 0) return 1LL;
  ll x = inv(b, p/2);
  x = x * x % MOD;
  if(p%2) x = x * b % MOD;
  return x;
}
int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> d(n, vector<int>(m));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> d[i][j];
    }
  }
  ll tot = 1LL;
  for(int i = 1; i <= n; i++) {
    tot *= 1LL*i;
  }
  tot %= MOD;
  ll ans = 0LL;
  for(int i = 0; i < m; i++) {
    vector<int> v;
    for(int j = 0; j < n; j++) {
      int dist = d[j][i];
      int earliest_time = n + 1 - dist;
      v.push_back(earliest_time + 1);
    }
    sort(v.begin(), v.end());
    vector<int> num(n + 1);
    for(auto &it : v) {
      if(it <= n)
        ++num[it];
    }
    ll work = 1LL;
    int satisfy = 0;
    for(int i = 1; i <= n; i++) {
      satisfy += num[i];
      work *= 1LL*(satisfy - (i - 1));
    }
    //work = number that don't have ==> number conquer = tot - work
    ans += tot - work;
    ans %= MOD;
  }
  ll ret = ans*1LL*inv(tot)%MOD;
  if(ret < 0) ret += MOD;
  cout << ret;
}