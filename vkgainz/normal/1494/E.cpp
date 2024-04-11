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
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 1e5 + 5;

int main() {
  int n, m; cin >> n >> m;
  ll numTwoCycle = 0LL; //for odd queries
  set<pair<int, int>> in;
  map<int, int> get[n];
  int numEq = 0;
  while(m--) {
    char c; cin >> c;
    if(c == '+') {
      int u, v; cin >> u >> v;
      --u, --v;
      char x; cin >> x;
      in.insert({u, v});
      get[u][v] = x-'a';
      if(in.count({v, u})) ++numTwoCycle;
      if(in.count({v, u}) && get[v][u] == x-'a') {
        ++numEq;
      }
    }
    else if(c == '-') {
      int u, v; cin >> u >> v;
      --u, --v;
      if(in.count({v, u})) --numTwoCycle;
      if(in.count({v, u}) && get[v][u] == get[u][v]) {
        --numEq;
      }
      get[u][v] = -1;
      in.erase({u, v});
    }
    else {
      int k; cin >> k;
      if(k%2 == 0) {
        if(numEq) cout << "YES" << "\n";
        else cout << "NO" << "\n";
      }
      else {
        if(numTwoCycle) cout << "YES" << "\n";
        else cout << "NO" << "\n";
      }
    }
  }
}