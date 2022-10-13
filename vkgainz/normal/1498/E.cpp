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
const int MX = 1e6 + 5;
bool query(int x, int y) {
  cout << "? " << x+1 << " " << y+1 << "\n";
  cout.flush();
  string ret;
  cin >> ret;
  if(ret=="Yes") return true;
  return false;
}
int main() {
  int n; cin >> n;
  vector<int> k(n);
  for(auto &a : k) cin >> a;
  vector<pair<int, pair<int, int>>> in;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      if(k[i] >= k[j] && i != j) {
        in.push_back({k[i] - k[j], {i, j}});
      }
    }
  }
  sort(in.begin(), in.end());
  reverse(in.begin(), in.end());
  bool found =false;
  for(auto &it : in) {
    bool b = query(it.s.f, it.s.s);
    if(b) {
      found = true;
      cout << "! " << it.s.f+1 << " " << it.s.s+1 << "\n";
      cout.flush();
      return 0;
    }
  }
  cout << "! " << 0 << " " << 0 << "\n";
  cout.flush();
}