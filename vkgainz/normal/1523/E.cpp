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
#define MAXN 200005
#define MAXE 400010
#define  INF (1<<29)

const int MX = 2e5 + 5;
vector<ll> fact, invfact;
ll MOD = 1e9 + 7;
ll inv(ll b, int p = MOD - 2) {
  if(p==0) return 1;
  ll x = inv(b, p/2);
  x = x*x%MOD;
  if(p%2) x=x*b%MOD;
  return x;
}
ll choose(int a, int b) {
  if(b > a) return 0LL;
  return fact[a]*invfact[a-b]%MOD*invfact[b]%MOD;
}
int main() {
  fact.resize(MX), invfact.resize(MX);
  fact[0] = 1;
  for(int i = 1; i < MX;i++)
    fact[i] = fact[i-1]*1LL*i%MOD;
  invfact[MX - 1] = inv(fact[MX - 1]);
  for(int i = MX - 2;i>=0;i--)
    invfact[i] = (i+1)*1LL*invfact[i+1]%MOD;
  int t; cin >> t;
  while(t--) {
    int n, k; cin >> n >> k;
    vector<ll> caught(n + 1);
    vector<ll> safe(n + 1);
    ll ans = 0LL;
    for(int i = 0; i <= n; i++) {
      if((k - 1)*(i - 1) > n) break;
      safe[i] = choose(n - (k - 1)*(i - 1), i);
      safe[i] *= fact[i];
      safe[i] %= MOD;
    }
    ll x = 1LL;
    for(int i = 1; i <= n; i++) {
      caught[i] = safe[i - 1]*1LL*(n - (i - 1)) % MOD - safe[i];
      caught[i] %= MOD;
      if(caught[i] < 0) caught[i] += MOD;
      x *= 1LL*(n - (i - 1));
      x %= MOD;
      ll add = (i*1LL*caught[i])%MOD;
      add *= inv(x)%MOD;
      ans += add;
      ans %= MOD;
    }
    if(ans < 0) ans += MOD;
    cout << ans << "\n";
  }
}