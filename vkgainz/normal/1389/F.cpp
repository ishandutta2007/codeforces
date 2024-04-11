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
typedef gp_hash_table<int, int, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
struct seg_num {
  vector<int> seg;
  int sz;
  void init(int n) {
    sz = 1;
    while(sz < n) sz *= 2;
    seg.resize(2*sz, 0);
  }
  void upd(int i, int x, int lx, int rx) {
    if(rx-lx==1) {
      seg[x]++;
      return;
    }
    int m = (lx+rx)/2;
    if(i<m) upd(i, 2*x+1, lx, m);
    else upd(i, 2*x+2, m, rx);
    seg[x] = seg[2*x+1] + seg[2*x+2];
  }
  void upd(int i) { upd(i, 0, 0, sz); }
  int query(int l, int r, int x, int lx, int rx) {
    if(lx>=r||rx<=l) return 0;
    if(lx>=l&&rx<=r) return seg[x];
    int m = (lx+rx)/2;
    return query(l,r,2*x+1,lx,m)+query(l,r,2*x+2,m,rx);
  }
  int query(int l, int r) { return query(l, r, 0, 0, sz); }
};
struct seg_mx {
  vector<int> seg;
  vector<int> lazy;
  int sz;
  void init(int n) {
    sz = 1;
    while(sz < n) sz *= 2;
    seg.resize(2*sz, 0);
    lazy.resize(2*sz, 0);
  }
  void push(int x, int lx, int rx, int v) {
    seg[x] -= v;
    if(rx-lx!=1) {
      lazy[2*x+1] += v;
      lazy[2*x+2] += v;
    }
  }
  void prop(int x, int lx, int rx) {
    push(x, lx, rx, lazy[x]);
    lazy[x] = 0;
    return;
  }
  void upd(int l, int r, int v, int x, int lx, int rx) {
    prop(x, lx, rx);
    if(lx>=r||rx<=l) return;
    if(lx>=l && rx<=r) {
      push(x, lx, rx, v);
      return;
    }
    int m = (lx+rx)/2;
    upd(l, r, v, 2*x+1, lx, m), upd(l, r, v, 2*x+2, m, rx);
    seg[x] = max(seg[2*x+1], seg[2*x+2]);
  }
  void upd(int l, int r, int v) { upd(l, r, v, 0, 0, sz); }
  int query(int l, int r, int x, int lx, int rx) {
    prop(x, lx, rx);
    if(lx>=r||rx<=l) return -1000000000;
    if(lx>=l&&rx<=r) return seg[x];
    int m = (lx+rx)/2;
    return max(query(l,r,2*x+1,lx,m), query(l,r,2*x+2,m,rx));
  }
  int query(int l, int r) { return query(l, r, 0, 0, sz); }
};
struct seg {
  int l, r, t;
};
bool cmp(seg &a, seg &b) {
  return a.r < b.r;
}
void compress(vector<seg> &v) {
  map<int, int> m;
  for(auto &it : v)
    m[it.l] = 1, m[it.r] = 1;
  int x = 1;
  for(auto it : m)
    m[it.f] = x++;
  for(int i=0;i<v.size();i++)
    v[i] = {m[v[i].l], m[v[i].r], v[i].t};
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<seg> in(n);
  for(int i=0;i<n;i++)
    cin >> in[i].l >> in[i].r >> in[i].t;
  compress(in);
  sort(in.begin(), in.end(), cmp);
  int ans = 0;
  seg_num blue, red;
  seg_mx all, allRed, allBlue;
  blue.init(2*n+1), red.init(2*n+1);
  all.init(2*n+1), allRed.init(2*n+1), allBlue.init(2*n+1);
  for(int i=0;i<n;i++) {
    int currDp = 0;
    //max (in[x..r] + max dp[j] j < x, x <= l)
    //max (num[r+1] - num[x] + max dp[j] j < x)
    //store max dp[j] j < x - num[x] in x spot
    int l = in[i].l, r = in[i].r, t = in[i].t;
    //cout << l << " " << r << " " << t << "\n";
    if(t == 1) {
      blue.upd(l);
      allBlue.upd(l+1, 2*n+1, 1);
      int v = all.query(0, l) - blue.query(0, l);
      int c = allBlue.query(l, l+1);
      if(v > c)
        allBlue.upd(l, l+1, c - v);
      currDp = allBlue.query(0, l+1) + blue.query(0, r+1);
    }
    else {
      red.upd(l);
      allRed.upd(l+1, 2*n+1, 1);
      int v = all.query(0, l) - red.query(0, l);
      int c = allRed.query(l, l+1);
      if(v > c) {
        allRed.upd(l, l+1, c - v);
      }
      currDp = allRed.query(0, l+1) + red.query(0, r+1);
    }
    ans = max(ans, currDp);
    int v = all.query(r, r+1);
    if(currDp > v)
      all.upd(r, r+1, v - currDp);
  }
  cout << ans << "\n";
}