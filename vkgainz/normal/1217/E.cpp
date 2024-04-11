#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
using ll = long long;
const int MX = 2e5+5;
vector<pair<int, int>> seg[2*MX];
int n, m;
const int INF = 2e9 + 5;
void combine(pair<int, int> &x, int y) {
  if(y<=x.f) {
    x = {y, x.f};
  }
  else if(y <=x.s) {
    x = {x.f, y};
  }
}
vector<pair<int, int>> merge(vector<pair<int, int>> &x, vector<pair<int, int>> &y) {
  vector<pair<int, int>> ret(x.size());
  for(int i=0;i<x.size();i++) {
    ret[i] = x[i];
    combine(ret[i], y[i].f), combine(ret[i], y[i].s);
  }
  return ret;
}
void rep(int i, int x) {
  int msk=0;
  int temp = x;
  for(int i=0;i<10;i++) {
    int a = temp%10;
    if(a>0) msk+=(1<<i);
    temp/=10;
  }
  vector<pair<int, int>> in(10);
  for(int i=0;i<10;i++) {
    if(msk&(1<<i)) in[i] = {x, INF};
    else in[i] = {INF, INF};
  }
  i+=n;
  seg[i] = in;
  while(i>1) {
    i/=2;
    seg[i] = merge(seg[2*i], seg[2*i+1]);
  }
}
int query(int l, int r) { //[l, r)
  l+=n, r+=n;
  vector<pair<int, int>> ret(10);
  for(int i=0;i<10;i++) ret[i] = {INF, INF};
  while(l<r) {
    if(l%2) {
      ret = merge(ret, seg[l++]);
    }
    if(r%2) {
      ret = merge(ret, seg[--r]);
    }
    l/=2, r/=2;
  }
  int mn = 2e9 + 5;
  for(int i=0;i<10;i++) {
    if(ret[i].f!=INF && ret[i].s!=INF) mn = min(mn, ret[i].f+ret[i].s);
  }
  return mn;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  vector<pair<int, int>> init(10);
  for(int i=0;i<10;i++) init[i] = {INF, INF};
  for(int i=0;i<2*MX;i++) {
    seg[i] = init;
  }
  for(int i=0;i<n;i++) {
    int x; cin >> x;
    rep(i, x);
  }
  while(m--) {
    int t; cin >> t;
    if(t==1) {
      int i, x; cin >> i >> x;
      --i;
      rep(i, x);
    }
    else {
      int l, r; cin >> l >> r;
      --l;
      int ans = query(l, r);
      if(ans == 2e9 + 5) cout << -1 << "\n";
      else cout << ans << "\n";
    }
  }
}