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
int head[100000], sz[100000];
int find(int x) {
  if(x == head[x]) return x;
  return head[x] = find(head[x]);
}
int curr;
int parent[1000000];
vector<int> salary(100000);
void merge(int x, int y, int w) {
  int a = find(x), b = find(y);
  if(a == b) return;
  if(salary[head[a]] == w) {
    parent[head[b]] = head[a];
    head[b] = head[a];
    return;
  }
  else if(salary[head[b]] == w) {
    parent[head[a]] = head[b];
    head[a] = head[b];
    return;
  }
  //greater
  parent[head[a]] = curr;
  parent[head[b]] = curr;
  head[a] = curr;
  head[b] = curr;
  salary[curr] = w;
  ++curr;
}
int main() {
  int n; cin >> n;
  vector<pair<int, pair<int, int>>> in;
  int a[n][n];
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cin >> a[i][j];
      if(i < j) in.push_back({a[i][j], {i, j}});
      if(i == j) salary[i] = a[i][j];
    }
  }
  for(int i=0;i<100000;i++) {
    head[i] = i, sz[i] = 1;
  }
  sort(in.begin(), in.end());
  curr =  n;
  for(auto &it : in) {
    merge(it.s.f, it.s.s, it.f);
  }
  cout << curr << "\n";
  for(int i=0;i<curr;i++) {
    cout << salary[i] << " ";
  }
  cout << "\n";
  cout << curr << "\n";
  for(int i=0;i<curr-1;i++) {
    cout << i+1 << " " << parent[i]+1 << "\n";
  }
}