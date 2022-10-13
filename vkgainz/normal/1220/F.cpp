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
vector<int> seg;
vector<int> lazy;
int sz = 1;
void prop(int x, int lx, int rx) {
  seg[x] += lazy[x];
  if(rx-lx!=1) {
    lazy[2*x+1] += lazy[x];
    lazy[2*x+2] += lazy[x];
  }
  lazy[x] = 0;
}
void upd(int l, int r, int x=0, int lx=0, int rx=sz) { //[l, r) + 1
  if(lx>=r || rx<=l) return;
  if(lx>=l && rx<=r) {
    ++seg[x];
    if(rx-lx != 1) {
      lazy[2*x+1]++;
      lazy[2*x+2]++;
    }
    return;
  }
  int m = (lx+rx)/2;
  upd(l, r, 2*x+1, lx, m), upd(l, r, 2*x+2, m, rx);
  seg[x] = max(seg[2*x+1], seg[2*x+2]);
}
void updidx(int i, int v, int x=0, int lx=0, int rx=sz) {
  prop(x, lx, rx);
  if(rx-lx==1) {
    seg[x] = v;
    return;
  }
  int m = (lx+rx)/2;
  if(i<m) updidx(i, v, 2*x+1, lx, m);
  else updidx(i, v, 2*x+2, m, rx);
  seg[x] = max(seg[2*x+1], seg[2*x+2]);
}
int get(int i, int x=0, int lx=0, int rx=sz) { //get depth at i
  prop(x, lx, rx);
  if(rx-lx==1) return seg[x];
  int m = (lx+rx)/2;
  if(i<m) return get(i, 2*x+1, lx, m);
  else return get(i, 2*x+2, m, rx);
}
int query() {
  return seg[0];
}
//check that shifting done properly!
void shift(vector<int> &x, int k) {
  vector<int> y(x.size());
  for(int i=0;i<x.size();i++) {
    y[i] = x[(i+k)%x.size()];
  }
  x = y;
}
int main() {
  int n; cin >> n;
  while(sz<n) sz*=2;
  seg.resize(2*sz, 0);
  lazy.resize(2*sz, 0);
  vector<int> a(n);
  for(auto &a : a) cin >> a, --a;
  vector<int> r(n);
  vector<int> s(n);
  vector<int> stack;
  int mnIdx = 0;
  for(int i=0;i<n;i++) {
    if(!a[i]) mnIdx = i;
  }
  shift(a, mnIdx); //add mnIdx to answer?
  r[0] = 1;
  updidx(0, 1);
  stack.push_back(0);
  //shift back by minIdx
  for(int i=1;i<n;i++) {
    while(stack.size() && a[i] < a[stack.back()])
      stack.pop_back();
    int nearestIdx = stack.back();
    updidx(i, get(nearestIdx) + 1);
    upd(nearestIdx + 1, i);
    r[i] = query();
    stack.push_back(i);
  }
  stack.clear();
  //[0], [0, n-1], [0, n-2],... ==> s[i] = [n-i, n]
  fill(seg.begin(), seg.end(), 0);
  fill(lazy.begin(), lazy.end(), 0);
  s[0] = 1;
  updidx(0, 1);
  stack.push_back(n);
  //make sure insertions and stuff are done right
  for(int i=1;i<n;i++) {
    //put in n-i
    while(stack.size() && a[n-i] < a[(stack.back())%n])
      stack.pop_back();
    int nearestIdx = stack.back();
    if(nearestIdx == n) {
      updidx(n-i, 2);
      upd(n-i+1, n);
      s[i] = query();
      stack.push_back(n-i);
      continue;
    }
    updidx(n-i, get(nearestIdx) + 1);
    upd(n-i+1, nearestIdx);
    s[i] = query();
    stack.push_back(n-i);
  }
  pair<int, int> ans = {n + 1, 0};
  for(int shift=0;shift<n;shift++) {
    int a = r[n-shift-1];
    int b = s[shift];
    int curr = max(a, b);
    if(curr < ans.f) {
      ans = {curr, shift};
    }
  }
  cout << ans.f << " " << (n+mnIdx-ans.s)%n << "\n";
}