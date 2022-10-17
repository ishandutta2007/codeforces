#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;


#ifdef LOCAL
#include "pretty_debug.h"
#else
#define debug(...) //ignore
#endif

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vi a(n);
  rep(i,0,n) cin>>a[i];

  vi pref(n+1);
  rep(i,0,n) pref[i+1] = pref[i] + a[i];
  auto sum = [&](int l, int r) { return pref[r] - pref[l]; };

  map<int,int> last_zero;
  last_zero[0] = 0;

  vi ks(n+1); // ks[i+1] = min k such that reach 0 after a[i]

  rep(i,0,n) {
    ll l = 0, r = 2e9;
    while(l + 1 < r) {
      ll q = (l+r) / 2;

      int t = prev(last_zero.upper_bound(q))->second;
      ll cookies = sum(t, i+1);
      ll eat = q * (i+1-t);

      if(eat >= cookies) r = q;
      else l = q;
    }
    ks[i+1] = r;
    last_zero[ks[i+1]] = i+1;
    auto it = last_zero.lower_bound(ks[i+1]);
    while(next(it) != end(last_zero)) last_zero.erase(next(it));
  }
  debug(ks);
  ks[n] = 0;

  ll cur_k = 1e18;
  int ans = 1;
  set<int> active;
  rep(i,0,n+1) active.insert(i);

  vector<pair<ll,int>> ks_sort;
  rep(i,0,n+1) ks_sort.emplace_back(ks[i], i);
  sort(all(ks_sort));
  reverse(all(ks_sort));

  map<ll,int> ans_of;
  ans_of[cur_k] = ans;

  for(auto [k, i]: ks_sort) {
    if(k == 0) break;
    cur_k = k-1;
    active.erase(i);
    auto it = active.lower_bound(i);
    assert(it != end(active));
    assert(it != begin(active));
    ans = max(ans, abs(*it - *prev(it)));
    ans_of[cur_k] = ans;
  }

  ans_of[0] = n;

  debug(ans_of);

  rep(i,0,m) {
    ll k;
    cin>>k;
    auto it = ans_of.lower_bound(k);
    assert(it != end(ans_of));
    cout << it->second-1 << " ";
  }
  cout << endl;
}