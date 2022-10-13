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
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 2e5 + 5;

int main() {
  int n; cin >> n;
  vector<ll> fact(n+1);
  fact[0] = 1LL;
  ll mod = 998244353;
  for(int i=1;i<=n;i++) {
    fact[i] = fact[i-1]*i%mod;
  }
  vector<int> fa(n+1), fb(n+1);
  vector<pair<int, int>> in(n);
  for(int i=0;i<n;i++) {
    cin >> in[i].f >> in[i].s;
    ++fa[in[i].f], ++fb[in[i].s];
  }
  ll ans = fact[n];
  ll p = 1LL;
  for(int i=0;i<=n;i++) {
    p = p * fact[fa[i]];
    p %= mod;
  }
  ans -= p;
  ans %= mod;
  p = 1LL;
  for(int i=0;i<=n;i++) {
    p = p * fact[fb[i]];
    p %= mod;
  }
  ans -= p;
  ans %= mod;
  p = 1LL;
  sort(in.begin(), in.end());
  bool work = true;
  for(int i=1;i<n;i++) {
    work = work && (in[i].s >= in[i-1].s);
  }
  map<pair<int, int>, int> freq;
  for(int i=0;i<n;i++) {
    ++freq[make_pair(in[i].f, in[i].s)];
  }
  p = work;
  for(auto &a : freq) {
    p = p * fact[a.s];
    p %= mod;
  }
  ans += p;
  ans %= mod;
  if(ans < 0) ans += mod;
  cout << ans << "\n";
}