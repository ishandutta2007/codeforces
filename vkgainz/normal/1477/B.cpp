#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
typedef long long ll;
typedef long double ld;
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 2e5 + 5;
int seg[4 * MX], lazy[4 * MX];
int no_op = 2;
int sz = 1;
void prop(int x, int lx, int rx) {
  if(lazy[x] == no_op) return;
  seg[x] = lazy[x]*(rx-lx);
  if(rx-lx!=1) {
    lazy[2*x+1] = lazy[x];
    lazy[2*x+2] = lazy[x];
  }
  lazy[x] = no_op;
}
void build(string &b, int x=0, int lx=0, int rx=sz) {
  if(rx-lx==1) {
    if(lx<b.size()) {
      if(b[lx]=='1') seg[x] = 1;
      else seg[x] = 0;
    }
    else {
      seg[x] = 0;
    }
    return;
  }
  int m = (lx+rx)/2;
  build(b, 2*x+1, lx, m), build(b, 2*x+2, m, rx);
  seg[x] = seg[2*x+1]+seg[2*x+2];
}
void upd(int l, int r, int v, int x=0, int lx=0, int rx=sz) {
  prop(x, lx, rx);
  if(lx>=r || rx<=l) return;
  if(lx>=l && rx<=r) {
    seg[x] = v*(rx-lx);
    if(rx-lx!=1) {
      lazy[2*x+1] = v;
      lazy[2*x+2] = v;
    }
    return;
  }
  int m = (lx+rx)/2;
  upd(l, r, v, 2*x+1, lx, m), upd(l, r, v, 2*x+2, m, rx);
  seg[x] = seg[2*x+1]+seg[2*x+2];
}
int query(int l, int r, int x=0, int lx=0, int rx=sz) {
  prop(x, lx, rx);
  if(lx >= r || rx <= l) return 0;
  if(lx>=l && rx<=r) {
    return seg[x];
  }
  int m = (lx+rx)/2;
  return query(l, r, 2*x+1, lx, m)+query(l, r, 2*x+2, m, rx);
}
int get(int i, int x=0, int lx=0, int rx=sz) {
  prop(x, lx, rx);
  if(rx-lx==1) return seg[x];
  int m = (lx+rx)/2;
  if(i<m) return get(i, 2*x+1, lx, m);
  else return get(i, 2*x+2, m, rx);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  while(t--) {
    int n, q; cin >> n >> q;
    sz = 1;
    while(sz<n) sz*=2;
    for(int i=0;i<=2*sz;i++) {
      seg[i] = 0, lazy[i] = no_op;
    }
    string s, f; cin >> s >> f;
    build(f);
    vector<pair<int, int>> in(q);
    for(int i=0;i<q;i++) {
      cin >> in[i].f >> in[i].s;
      --in[i].f;
    }
    reverse(in.begin(), in.end());
    bool work = true;
    for(int i=0;i<q && work;i++) {
      int len = in[i].s-in[i].f;
      int sum = query(in[i].f, in[i].s);
      if(len%2==0 && sum==len/2) {
        work = false;
        break;
      }
      if(sum <= (len-1)/2) {
        upd(in[i].f, in[i].s, 0);
      }
      else {
        upd(in[i].f, in[i].s, 1);
      }
    }
    for(int i=0;i<n;i++) {
      int x = get(i);
      if(x != s[i]-'0') work = false;
    }
    if(work) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
}