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
const int MX = 1e5 + 5;
vector<pair<int, int>> edges;
int main() {
  int n; cin >> n;
  vector<pair<int, int>> d(n);
  vector<int> v(2*n); //dist of i from the end
  fill(v.begin(), v.end(), -1);
  for(int i=0;i<n;i++) {
    cin >> d[i].f;
    d[i].s = 2*i;
  }
  //f = distance, s = index
  sort(d.begin(), d.end());
  for(int i=0;i<d.size()-1;i++) {
    edges.push_back({d[i].s, d[i+1].s});
  }
  for(int i=0;i<n;i++) {
    v[n-i-1] = d[i].s;
  }
  //edge betewen d[0]-d[1].s,...d[n-2].s-d[n-1].s
  int num = 0;
  while(!d.empty()) {
    int x = d.back().f, y = d.back().s; //put 2*y+1
    d.pop_back();
    x += num;
    ++num;
    int a = v[x-1];
    edges.push_back({a, y+1});
    if(v[x] == -1)
      v[x] = y+1;
  }
  for(auto &a : edges) {
    cout << a.f+1 << " " << a.s+1 << "\n";
  }
}