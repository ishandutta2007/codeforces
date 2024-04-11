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
vector<vector<int>> adj, adjT;
vector<bool> used;
vector<int> order;
vector<bool> component;
vector<int> in;
int num;
void dfs1(int v) {
  used[v] = true;
  for(int next : adj[v]) {
    if(!used[next])
      dfs1(next);
  }
  order.push_back(v);
}
void dfs2(int v) {
  used[v] = true;
  component[v] = true;
  ++num;
  for(int next : adjT[v]) {
    if(!used[next])
      dfs2(next);
  }
}
void dfs3(int v) {
  used[v] = true;
  in.push_back(v);
  for(int next : adj[v]) {
    if(!used[next]) {
      dfs3(next);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    adj.clear(), adjT.clear(), used.clear();
    order.clear(), component.clear();
    adj.resize(n), adjT.resize(n);
    for(int i=0;i<m;i++) {
      int u, v; cin >> u >> v;
      --u, --v;
      adj[u].push_back(v);
      adjT[v].push_back(u);
    }
    used.resize(n);
    used.assign(n, false);
    for(int i=0;i<n;i++) {
      if(!used[i]) {
        dfs1(i);
      }
    }
    used.assign(n, false);
    component.resize(n);
    component.assign(n, false);
    num = 0;
    dfs2(order[n-1]);
    if(num == n) {
      cout << "No" << "\n";
    }
    else {
      cout << "Yes" << "\n";
      in.clear();
      used.assign(n, false);
      dfs3(order[n-1]);
      int root;
      if(in.size() == n) {
        //find a vertex not in component and in in
        for(auto &a : in) {
          if(!component[a]) {
            root = a;
            break;
          }
        }
      }
      else {
        root = order[n-1];
      }
      in.clear();
      used.assign(n, false);
      dfs3(root);
      vector<bool> jury(n);
      for(auto &a : in) jury[a] = true;
      cout << in.size() << " " << n - in.size() << "\n";
      for(int i=0;i<n;i++) {
        if(jury[i]) cout << i+1 << " ";
      }
      cout << "\n";
      for(int i=0;i<n;i++) {
        if(!jury[i]) cout << i+1 << " ";
      }
      cout << "\n";
    }
  }
}