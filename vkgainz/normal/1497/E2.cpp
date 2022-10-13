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
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  vector<int> smolprimes;
  for(int i=2;i<3200;i++) {
    bool w= true;
    for(int j=2;j<i;j++) {
      if(i%j==0) w = false;
    }
    if(w) smolprimes.push_back(i);
  }
  while(t--) {
    int n; cin >> n;
    int k; cin >> k;
    vector<int> a(n);
    for(auto &a : a) cin >> a;
    for(int i=0;i<n;i++) {
      for(int j : smolprimes) {
        while(a[i]%(j*j) == 0) a[i]/=(j*j);
      }
    }
    multiset<int> in;
    map<int, int> prev;
    //check if this is right
    vector<vector<int>> lst(n+1, vector<int>(k+2));
    for(int i=0;i<=k;i++)
      in.insert(0);
    for(int i=1;i<=n;i++) {
      if(prev.find(a[i-1]) != prev.end()) {
        //insert
        if(prev[a[i-1]] > *in.begin()) {
          in.erase(in.begin());
          in.insert(prev[a[i-1]]);
        }
      }
      prev[a[i-1]] = i;
      lst[i][0] = i;
      auto it = in.begin();
      for(int j=1;j<=k+1;j++) {
        lst[i][k+2-j] = (*it);
        ++it;
      }
    }
    vector<vector<int>> dp(n+1, vector<int>(k+1));
    //1 indexed dp
    for(int i=0;i<=n;i++) {
      for(int j=0;j<=k;j++) {
        dp[i][j] = 10000000;
        if(i == 0) {
          dp[i][j] = 0;
          continue;
        }
        for(int x=0;x<=j;x++)
          dp[i][j] = min(dp[i][j], dp[lst[i][x+1]][j-x] + 1);
      }
    }
    cout << dp[n][k] << "\n";
  }
}