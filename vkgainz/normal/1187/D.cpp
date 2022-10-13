#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree <pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update>
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 3e5 + 5;

int seg[2*MX];
int n;
void build(vector<int> &a) {
  for(int i=n-1;i>=1;i--) {
    seg[i] = min(seg[2*i], seg[2*i+1]);
  }
}
void upd(int i, int v) {
  seg[i+=n] = v;
  while(i>1) {
    i/=2;
    seg[i] = min(seg[2*i], seg[2*i+1]);
  }
}
int query(int l, int r) {
  l+=n, r+=n;
  int ret = 1e9;
  while(l<r) {
    if(l%2) ret = min(ret, seg[l++]);
    if(r%2) ret = min(ret, seg[--r]);
    l/=2, r/=2;
  }
  return ret;
}
void solve() {
  cin >> n;
  vector<int> a(n), b(n);
  for(int i=0;i<n;i++) cin >> a[i], --a[i];
  for(int i=0;i<n;i++) cin >> b[i], --b[i];
  for(int i=0;i<n;i++) {
    seg[i+n] = a[i];
  }
  build(a);
  vector<int>  pos[n];
  for(int i=0;i<n;i++) {
    pos[a[i]].push_back(i);
  }
  for(int i=0;i<n;i++) {
    reverse(pos[i].begin(), pos[i].end());
  }
  bool work = true;
  for(int i=0;i<n && work;i++) {
    if(pos[b[i]].empty()) {
      work = false;
      continue;
    }
    int r = pos[b[i]].back();
    pos[b[i]].pop_back();
    //cout << i << " " << r << "\n";
    int a = query(0, r); //why 0?
    if(a <= b[i]) {
      work = false;
    }
    else {
      upd(r, 1e9);
    }
  }
  if(work) cout << "YES" << "\n";
  else cout << "NO" << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  while(t--) {
    solve();
  }
}