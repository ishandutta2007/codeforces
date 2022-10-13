#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 2e5 + 5;
const int BLOCK_SZ = 300; 
struct seg_tree {
  vector<ll> seg;
  int sz;
  void init(int n) {
    sz = 1;
    while(sz < n)
      sz *= 2;
    seg.resize(2*sz);
    fill(seg.begin(), seg.end(), 1e18);
  }
  void upd(int i, ll v, int x, int lx, int rx) {
    if(rx - lx == 1) {
      seg[x] = v;
      return;
    }
    int m = (lx + rx)/2;
    if(i < m) upd(i, v, 2*x+1, lx, m);
    else upd(i, v, 2*x+2, m, rx);
    seg[x] = min(seg[2*x+1], seg[2*x+2]);
  }
  void upd(int i, ll v) { upd(i, v, 0, 0, sz); }
  ll query(int l, int r, int x, int lx, int rx) {
    if(lx >= r || rx <= l) return 1e18;
    if(lx >= l && rx <= r) return seg[x];
    int m = (lx + rx)/2;
    return min(query(l, r, 2*x+1, lx, m), query(l, r, 2*x+2, m, rx));
  }
  ll query(int l, int r) { return query(l, r, 0, 0, sz); }
};
int main() {
  int n; cin >> n;
  vector<pair<int, int>> in(n);
  for(auto &a : in) cin >> a.f >> a.s;
  sort(in.begin(), in.end());
  vector<ll> dp(n);
  dp[n-1] = 0;
  seg_tree eq, diff;
  eq.init(n), diff.init(n);
  diff.upd(n - 1, dp[n-1] + in[n-1].f);
  eq.upd(n - 1, dp[n-1]);
  for(int i=n-2;i>=0;i--) {
    int r = 0;
    int lo = 0, hi = n - 1;
    for(int j=0;j<20;j++) {
      int mid = (lo + hi + 1) / 2;
      if(in[mid].f > in[i].f + in[i].s) 
        hi = mid - 1;
      else
        lo = mid;
    }
    r = lo;
    dp[i] = min(eq.query(i + 1, r + 1), diff.query(r + 1, n) - in[i].f - in[i].s);
    eq.upd(i, dp[i]), diff.upd(i, dp[i] + in[i].f);
  }
  ll ans = dp[0];
  for(int i=0;i<n;i++) ans += in[i].s;
  cout << ans << "\n";
}