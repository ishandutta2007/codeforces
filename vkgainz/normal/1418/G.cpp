#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 5e5+5;
using cd = complex<double>;
const double PI = acos(-1);
int sz = 1;
pair<int, int> seg[4*MX];
int lazy[4*MX];
pair<int, int> merge(pair<int, int> x, pair<int, int> y) {
  if(y.f == x.f) {
    return {x.f, x.s + y.s};
  }
  else if(y.f < x.f) return y;
  else return x;
}
void push(int x, int lx, int rx, int v) {
  seg[x].f += v;
  if(rx-lx!=1) {
    lazy[2*x+1] += v;
    lazy[2*x+2] += v;
  }
}
void prop(int x, int lx, int rx) {
  push(x, lx, rx, lazy[x]);
  lazy[x] = 0;
}
void build(int x=0, int lx=0, int rx=sz) {
  if(rx-lx==1) {
    seg[x] = {0, 1};
    return;
  }
  int m = (lx+rx)/2;
  build(2*x+1, lx, m), build(2*x+2, m, rx);
  seg[x] = merge(seg[2*x+1], seg[2*x+2]);
}
void upd(int l, int r, int v, int x=0, int lx=0, int rx=sz) {
  prop(x, lx, rx);
  if(lx>=r || rx<=l) return;
  if(lx>=l && rx<=r) {
    push(x, lx, rx, v);
    return;
  }
  int m = (lx+rx)/2;
  upd(l, r, v, 2*x+1, lx, m), upd(l, r, v, 2*x+2, m, rx);
  seg[x] = merge(seg[2*x+1], seg[2*x+2]);
}
pair<int, int> query(int l, int r, int x=0, int lx=0, int rx=sz) {
  prop(x, lx, rx);
  if(lx>=r || rx<=l) return {10000000, 0};
  if(lx>=l && rx<=r) return seg[x];
  int m = (lx+rx)/2;
  return merge(query(l, r, 2*x+1, lx, m), query(l, r, 2*x+2, m, rx));
}
int main() {
  int n; cin >> n;
  while(sz<n) sz*=2;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i], --a[i];
  vector<array<int, 4>> lst(n);
  for(int i=0;i<n;i++) {
    for(int j=0;j<4;j++) lst[i][j] = -1;
  }
  ll ans = 0LL;
  build();
  for(int i=0;i<n;i++) {
    //delete old ranges
    if(lst[a[i]][0] != -1)
      upd(lst[a[i]][2] + 1, lst[a[i]][0] + 1, -1);
    if(lst[a[i]][3] != -1)
      upd(0, lst[a[i]][3] + 1, -1);
    //upd lst
    for(int j=3;j>=1;j--) lst[a[i]][j] = lst[a[i]][j-1];
    lst[a[i]][0] = i;
    //add new ranges
    if(lst[a[i]][0] != -1)
      upd(lst[a[i]][2] + 1, lst[a[i]][0] + 1, 1);
    if(lst[a[i]][3] != -1)
      upd(0, lst[a[i]][3] + 1, 1);
    //query ans
    pair<int, int> curr = query(0, i+1);
    if(curr.f == 0) ans+=curr.s;
  }
  cout << ans << "\n";
}