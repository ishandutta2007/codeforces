#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
using ll = long long;
const int MX = 3e5+5;

int seg[2*MX];
int seg2[2*MX];
int n;
vector<int> a(MX);
void build() {
  for(int i=n-1;i>=1;i--) {
    int x = a[seg[2*i]], y = a[seg[2*i+1]];
    if(x>=y) seg[i] = seg[2*i];
    else seg[i] = seg[2*i+1];
  }
}
void upd(int i,int v) {
  i+=n+1;
  seg2[i] = v;
  while(i>1) {
    i/=2;
    seg2[i] = min(seg2[2*i], seg2[2*i+1]);
  }
}
int query2(int l, int r) {
  l+=n+1, r+=n+1;
  int ret = 1e9;
  while(l<r) {
    if(l%2) ret = min(ret, seg2[l++]);
    if(r%2) ret = min(ret, seg2[--r]);
    l/=2, r/=2;
  }
  return ret;
}
int query(int l, int r) {
  int ret = MX-1;
  l+=n, r+=n;
  while(l<r) {
    if(l%2) {
      if(a[ret] < a[seg[l]]) {
        ret = seg[l];
      }
      ++l;
    }
    if(r%2) {
      --r;
      if(a[ret] < a[seg[r]]) {
        ret = seg[r];
      }
    }
    l/=2, r/=2;
  }
  return ret;
}
vector<int> inquery[MX];
//should be nlogn...?
void solve(int l, int r) { //[l, r]
  if(l>r) return;
  if(l == r) {
    inquery[r].push_back(l);
    return;
  }
  int x = query(l, r+1);
  int eleft = query(l, x), eright = query(x+1, r+1);
  if(a[eleft] != a[x]) eleft = l;
  if(a[eright] != a[x]) eright = r;
  //optimize below
  if(x - eleft < eright - x) {
    for(int i=x;i>=eleft;i--) {
      if(i+a[x]-1>=x && i+a[x]-1 <=r) {
        inquery[i+a[x]-1].push_back(i);
      }
    }
  }
  else {
    for(int i=x;i<=eright;i++) {
      if(i-a[x]+1 <= x && i-a[x]+1 >=l) {
        inquery[i].push_back(i-a[x]+1);
      }
    }
  }
  solve(l, x-1), solve(x+1, r);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for(int i=0;i<n;i++) cin >> a[i];
  a[MX-1] = -1e9;
  for(int i=0;i<n;i++) seg[i+n] = i;
  build();
  solve(0, n-1);
  for(int i=0;i<=n;i++) {
    upd(i, -1e9);
  }
  int ans = 0;
  for(int i=0;i<n;i++) {
    upd(a[i], i);
    for(auto &it : inquery[i]) {
      int mn = query2(1, i-it+2);
      if(mn==it) ++ans;
    }
  }
  cout << ans << "\n";
}