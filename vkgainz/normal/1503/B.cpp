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
int read() {
  int x; cin >> x;
  return x;
}
void print(int b, int i, int j) {
  cout << b << " " << (i+1) << " " << (j+1) << "\n";
  cout.flush();
}
int a[100][100];
int main() {
  int n; cin >> n;
  int numOne = 0;
  vector<pair<int, int>> odd, even;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) { 
      if((i+j)%2==0) odd.push_back({i, j});
      else even.push_back({i, j});
    }
  }
  //one oof odd.emptuy, even.empty will happen
  for(int i=0;i<n*n;i++) {
    int currCol = read();
    if(currCol == 1) ++numOne;
    if(currCol != 1) {
      if(odd.empty()) {
        a[even.back().f][even.back().s] = 5 - currCol;
        print(5 - currCol, even.back().f, even.back().s);
        even.pop_back();
      }
      else {
        a[odd.back().f][odd.back().s] = 1;
        print(1, odd.back().f, odd.back().s);
        odd.pop_back();
      }
    }
    else {
      if(even.empty()) {
        a[odd.back().f][odd.back().s] = 3;
        print(3, odd.back().f, odd.back().s);
        odd.pop_back();
      }
      else {
        a[even.back().f][even.back().s] = 2;
        print(2, even.back().f, even.back().s);
        even.pop_back();
      }
    }
  }
}