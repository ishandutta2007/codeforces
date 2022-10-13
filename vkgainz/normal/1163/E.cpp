#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
using ll = long long;
const int MX = 2e5+5;
vector<int> basis;
vector<int> idx;
int sz;
void insert(int msk, int &x, int d) {
  for(int i=0;i<x;i++) {
    if((msk&(1<<i)) == 0) continue;
    if(!basis[i]) {
      basis[i] = msk;
      idx[i] = d;
      ++sz;
      return;
    }
    msk^=basis[i];
  }
}
bool work(int x, vector<int> &s) {
  //generate basis
  basis.resize(x);
  fill(basis.begin(), basis.end(), 0);
  idx.resize(x);
  fill(idx.begin(), idx.end(), 0);
  sz = 0;
  for(int i=0;i<s.size();i++) {
    if(s[i] >= (1<<x)) continue;
    insert(s[i], x, i);
  }
  return sz == x;
}
vector<int> make(int x) {
  vector<int> ans;
  if(x == 0) {
    ans.push_back(0);
    return ans;
  }
  vector<int> put=  make(x - 1);
  reverse(put.begin(), put.end());
  ans.insert(ans.end(), put.begin(), put.end());
  for(int i=0;i<ans.size();i++) {
    ans[i]+=(1<<(x-1));
  }
  reverse(put.begin(), put.end());
  ans.insert(ans.end(), put.begin(), put.end());
  return ans;
}
int main() {
  int n; cin >> n;
  vector<int> s(n);
  for(int i=0;i<n;i++) cin >> s[i];
  int ans = 0;
  for(int i=0;i<20;i++) {
    if(work(i, s)) ans = i;
  }
  work(ans, s);
  vector<int> v = make(ans);
  cout << ans << "\n";
  for(int i=0;i<v.size();i++) {
    int x = 0;
    for(int j=0;j<ans;j++) {
      if(v[i]&(1<<j)) x^=s[idx[j]];
    }
    cout << x << " ";
  }
  cout << "\n";
}