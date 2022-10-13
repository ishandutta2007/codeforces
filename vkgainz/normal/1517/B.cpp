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

int main() {
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    vector<vector<int>> b(n, vector<int>(m));
    for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++) {
        cin >> b[i][j];
      }
    }
    vector<vector<int>> ans(n, vector<int>(m));
    vector<pair<int, pair<int, int>>> in;
    vector<multiset<int>> get(n);
    for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++) {
        get[i].insert(b[i][j]);
      }
    }
    for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++) {
        in.push_back({b[i][j], {i, j}});
      }
    }
    sort(in.begin(), in.end());
    for(int i=0;i<m;i++) {
      ans[in[i].s.f][i] = in[i].f;
      get[in[i].s.f].erase(get[in[i].s.f].lower_bound(in[i].f));
    }
    for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++) {
        if(ans[i][j]) continue;
        ans[i][j] = *get[i].begin();
        get[i].erase(get[i].begin());
      }
    }
    for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++) {
        cout << ans[i][j] << " ";
      }
      cout << "\n";
    }
  }
}