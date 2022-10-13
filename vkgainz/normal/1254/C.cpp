#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 2e5 + 5;
ll query(int t, int i, int j, int k) {
  cout << t << " " << i+1 << " " << j+1 << " " << k+1 << "\n";
  cout.flush();
  ll x; cin >> x;
  return x;
}
vector<ll> area;
int main() {
  int n; cin >> n;
  int nxt = 1;
  for(int i=2;i<n;i++) {
    ll x = query(2, 0, nxt, i);
    if(x == -1) continue;
    else nxt = i;
  }
  area.resize(n);
  int mx = 0;
  ll mxArea = 0LL;
  for(int i=1;i<n;i++) {
    if(i == nxt) continue;
    area[i] = query(1, 0, i, nxt);
    if(area[i] > mxArea) {
      mx = i, mxArea = area[i];
    }
  }
  vector<pair<ll, int>> left, right;
  for(int i=1;i<n;i++) {
    if(i == nxt || i == mx) continue;
    ll x = query(2, 0, i, mx);
    if(x == -1) right.push_back({area[i], i});
    else left.push_back({area[i], i});
  }
  sort(left.begin(), left.end());
  sort(right.begin(), right.end(), greater<pair<ll, int>>());
  vector<int> ans;
  ans.push_back(0);
  for(auto &it : left) ans.push_back(it.s);
  ans.push_back(mx);
  for(auto &it : right) ans.push_back(it.s);
  ans.push_back(nxt);
  cout << 0 << " ";
  for(auto &it : ans) cout << it+1 << "\n";
}