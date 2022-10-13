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

vector<ll> fact, invfact;
ll MOD = 998244353;
ll inverse(ll b, int p = MOD - 2) {
  if(p == 0) return 1LL;
  ll x = inverse(b, p/2);
  x = x * x % MOD;
  if(p%2) x = x * b % MOD;
  return x;
}

ll choose(int a, int b) {
  if(b > a) return 0LL;
  return fact[a]*1LL*invfact[b]%MOD*1LL*invfact[a-b]%MOD;
}

int main() {
  fact.resize(200001), invfact.resize(200001);
  fact[0] = 1LL;
  for(int i = 1; i <= 200001; i++)
    fact[i] = fact[i - 1]*1LL*i % MOD;
  invfact[200000] = inverse(fact[200000]);
  for(int i = 199999; i >= 0; i--) {
    invfact[i] = (i+1)*1LL*invfact[i + 1] % MOD;
  }

  int n, k; cin >> n >> k;
  vector<int> a(n);
  for(auto &a : a) cin >> a;
  vector<int> pos(n + 1);
  for(int i = 0; i < n; i++)
    pos[a[i]] = i;
  pos[n] = -1;

  int l = 1;
  for(int i = 1; i < n; i++) {
    if(pos[a[i] + 1] < pos[a[i - 1] + 1])
      ++l;
  }
  

  ll ans = 0LL;
  for(int i = l; i <= k; i++) {
    ans += choose(n - l, i - l) * 1LL * choose(k, i);
    ans %= MOD;
  }
  
  if(ans < 0) ans += MOD;
  cout << ans << "\n";
}