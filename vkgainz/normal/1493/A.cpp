#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
const int MX = 1e5+5;
int dp[101][101][101];
int main() {
  int T; cin >> T;
  while(T--) {
    int n, k; cin >> n >> k;
    int sum = 0;
    vector<int> ans;
    for(int i=(k+1)/2;i<=n;i++) {
      if(i==k) continue;
      ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for(auto &a : ans) cout << a << " ";
    cout << "\n";
  }
}