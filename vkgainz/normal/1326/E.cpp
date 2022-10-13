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
const int MX = 1e5 + 5;
vector<int> seg, lazy;
vector<int> bomb;
int sz = 1;
void prop(int x, int lx, int rx) {
  seg[x] += lazy[x];
  if(rx-lx!=1) {
    lazy[2*x+1] += lazy[x];
    lazy[2*x+2] += lazy[x];
  }
  lazy[x] = 0;
}
void upd(int l, int r, int v, int x=0, int lx=0, int rx=sz) {
  prop(x, lx, rx);
  if(lx>=r || rx<=l) return;
  if(lx>=l && rx<=r) {
    seg[x] += v;
    if(rx-lx!=1) {
      lazy[2*x+1] += v;
      lazy[2*x+2] += v;
    }
    return;
  }
  int m = (lx+rx)/2;
  upd(l, r, v, 2*x+1, lx, m), upd(l, r, v, 2*x+2, m, rx);
  seg[x] = max(seg[2*x+1], seg[2*x+2]);
}
int query(int l, int r, int x=0, int lx=0, int rx=sz) {
  prop(x, lx, rx);
  if(lx>=r || rx<=l) return -1000000;
  if(lx>=l && rx<=r) {
    return seg[x]; 
  }
  int m = (lx+rx)/2;
  return max(query(l, r, 2*x+1, lx, m), query(l, r, 2*x+2, m, rx));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n; cin >> n;
  while(sz<n) sz*=2;
  seg.resize(2*sz);
  lazy.resize(2*sz);
  bomb.resize(2*sz);
  vector<int> p(n);
  vector<int> q(n);
  vector<int> inv(n);
  for(auto &a : p) cin >> a, --a;
  for(auto &a : q) cin >> a, --a;
  for(int i=0;i<n;i++) {
    inv[p[i]] = i;
  }
  int ans = n-1;
  upd(0, inv[ans] + 1, 1);
  cout << ans+1 << " ";
  for(int i=0;i<n-1;i++) {
    upd(0, q[i] + 1, -1);
    while(ans >= 0) {
      if(query(0, n) <= 0) {
        --ans;
        if(ans>=0)
          upd(0, inv[ans] + 1, 1);
      }
      else break;
    }
    cout << ans+1 << " ";
  }
}