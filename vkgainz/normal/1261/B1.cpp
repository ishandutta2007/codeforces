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
int seg[4*MX];
int sz = 1;
void build(int x=0, int lx=0, int rx=sz) {
  if(rx-lx==1) seg[x] = 1;
  else {
    int m = (lx+rx)/2;
    build(2*x+1, lx, m), build(2*x+2, m, rx);
    seg[x] = seg[2*x+1] + seg[2*x+2];
  }
}
void upd(int i, int v, int x = 0, int lx = 0, int rx = sz) {
  if(rx-lx==1) {
    seg[x] += v;
    return;
  }
  int m = (lx+rx)/2;
  if(i<m) upd(i, v, 2*x+1, lx, m);
  else upd(i, v, 2*x+2, m, rx);
  seg[x] =seg[2*x+1]+seg[2*x+2];
}
int find_kth(int k, int x=0, int lx=0, int rx=sz) { //returns idx, k - 0 indexed
  if(rx-lx==1) return lx;
  int m = (lx+rx)/2;
  if(seg[2*x+1] <= k) {
    return find_kth(k - seg[2*x+1], 2*x+2, m, rx);
  }
  else {
    return find_kth(k, 2*x+1, lx, m);
  }
}
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  if(a.f == b.f)
    return a.s > b.s;
  return a.f < b.f;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  while(sz<n) sz*=2;
  vector<int> a(n);
  for(auto &a : a) cin >> a;
  vector<pair<int, int>> ord(n);
  for(int i=0;i<n;i++) ord[i] = {a[i], i};
  sort(ord.begin(), ord.end(), cmp);
  reverse(ord.begin(), ord.end());
  build();
  int m; cin >> m;
  vector<pair<int, int>> q[n+1];
  for(int i=0;i<m;i++) {
    int k, pos; cin >> k >> pos;
    q[k].push_back({pos, i});
  }
  vector<int> ans(m);
  for(int i=n;i>=1;i--) {
    //query
    for(auto &it : q[i]) {
      ans[it.s] = a[find_kth(it.f-1)];
    }
    //remove
    upd(ord.back().s, -1);
    ord.pop_back();
  }
  for(auto &a : ans) cout << a << "\n";
}