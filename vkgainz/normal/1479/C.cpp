#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second

typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
typedef tree<
pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set;
const int MX = 5e5 + 5;

int main() {
  int l, r; cin >> l >> r;
  vector<vector<pair<int,int>>> edges;
  //find num vertex
  //mamke 0..x, join all to last O_O
  int num = 0;
  int x = r-l;
  for(int i=1;i<=30;i++) {
    if((1<<(i-1)) - 1 <= x) {
      num = i;
    }
  }
  int m = 0;
  if((1<<(num-1)) - 1 == x) {
    edges.resize(num + 1, vector<pair<int,int>>());
    for(int i=0;i<num;i++) {
      edges[i].push_back({num, l});
      ++m;
    }
  }
  else {
    edges.resize(num + 2, vector<pair<int,int>>());
    for(int i=0;i<num+1;i++) {
      edges[i].push_back({num+1, l});
      ++m;
    }
  }
  for(int i=0;i<num;i++) {
    for(int j=0;j<i;j++) {
      edges[j].push_back({i, (1<<(i-1))});
      ++m;
    }
  }
  int left = x - ((1<<(num-1))-1);
  int hi = x;
  for(int i=1;i<num;i++) {
    if(left&(1<<(i-1))) {
      edges[i].push_back({num, hi - ((1<<i)-1)});
      ++m;
      hi -= (1<<(i-1));
    }
  }
  cout << "YES" << "\n";
  cout << edges.size() << " " << m << "\n";
  for(int i=0;i<edges.size();i++) {
    for(pair<int, int> j : edges[i]) {
      cout << i+1 << " " << j.f+1 << " " << j.s << "\n";
    }
  }
}