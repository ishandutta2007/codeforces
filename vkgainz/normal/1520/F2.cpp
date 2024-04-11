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
const int MX = 400005;
struct seg_tree {
  vector<int> seg;
  int sz;
  void init(int n) {
    sz = 1;
    while(sz < n) sz *= 2;
    seg.resize(2*sz);
  }
  void upd(int i, int x, int lx, int rx) {
    if(rx-lx==1) {
      seg[x] = 1;
      return;
    }
    int m = (lx+rx)/2;
    if(i < m) upd(i, 2*x+1, lx, m);
    else upd(i, 2*x+2, m, rx);
    seg[x] = seg[2*x+1] + seg[2*x+2];
  }
  void upd(int i) { upd(i, 0, 0, sz); }
  int query(int l, int r, int x, int lx, int rx) {
    if(rx<=l || lx>=r) return 0;
    if(lx>=l&& rx<=r) return seg[x];
    int m = (lx+rx)/2;
    return query(l,r,2*x+1,lx,m)+query(l,r,2*x+2,m,rx);
  }
  int query(int l, int r) { return query(l, r, 0, 0, sz); } //[l..r)
};
int main() {
  int n, t; cin >> n >> t;
  vector<int> b((n+31)/32);
  seg_tree in;
  in.init(n+1);
  for(int tc=1;tc<=t;tc++) {
    int k; cin >> k;
    if(tc == 1) {
      for(int i=0;i<n/32;i++) {
        cout << "? " << 1 << " " << 32*i+32 << "\n";
        cout.flush();
        cin >> b[i];
      }
      cout << "? " << 1 << " " << n << "\n";
      cout.flush();
      cin >> b.back();
    }
    int lo = 0, hi = b.size() - 1;
    for(int j=0;j<20;j++) {
      int mid = (lo+hi)/2;
      int en = 32*(mid+1);
      if(mid == b.size()-1) en = n;
      int numZero = en - (b[mid] + in.query(1, en+1));
      if(numZero < k) {
        lo = mid + 1;
      }
      else hi = mid;
    }
    //in block mid
    int st = 32*lo+1, en = 32*(lo+1);
    if(lo == b.size()-1) en = n;
    for(int i=0;i<5;i++) {
      int mid = (st + en)/2;
      int x;
      cout << "? " << 1 << " " << mid << "\n";
      cout.flush();
      cin >> x;
      int numZero = mid - x;
      if(numZero < k) {
        st = mid + 1;
      }
      else en = mid;
    }
    cout << "! " << st << "\n";
    cout.flush();
    in.upd(st);
  }
}