#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 5e5+5;
using cd = complex<double>;
const double PI = acos(-1);
int a[1501][1501];
int mx[1501][1501];
pair<int, int> w[2000000];
ll dp[1501][1501];
ll mod = 998244353;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  int a[n][n];
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cin >> a[i][j];
      w[a[i][j]] = {i, j};
    }
  }
  vector<int> ord;
  vector<int> pos(n);
  bool in[n];
  memset(in, 0, sizeof(in));
  for(int i=1;i<=n*(n-1)/2;i++) {
    if(!in[w[i].f]) {
      in[w[i].f] = true;
      pos[w[i].f] = ord.size();
      ord.push_back(w[i].f);
    }
    if(!in[w[i].s]) {
      in[w[i].s] = true;
      pos[w[i].s] = ord.size();
      ord.push_back(w[i].s);
    }
  }
  reverse(ord.begin(), ord.end());
  if(ord.size()==0) ord.push_back(0);
  //for(auto &a : ord) cout << a << "\n";
  //# of transition points must be O(n)...
  vector<int> transition[n + 1];
  for(int len=1;len<=n;len++) {
    for(int i=0;i<n;i++) {
      int j = i+len-1;
      if(j>=n) continue;
      if(len==1) mx[i][j] = a[ord[i]][ord[j]];
      else {
        mx[i][j] = a[ord[i]][ord[j]];
        if(i<n-1) mx[i][j] = max(mx[i][j], mx[i+1][j]);
        if(j>0) mx[i][j] = max(mx[i][j], mx[i][j-1]);
      }
    }
  }
  int mn[n][n], mn1[n][n], mn2[n][n];
  int mnH[n][n];
  //map to ord
  for(int i=0;i<n;i++) {
    int curr = ord[i];
    for(int j=0;j<i;j++) {
      mnH[j][i] = a[curr][ord[j]];
    }
    for(int j=1;j<=i;j++) mnH[j][i] = min(mnH[j][i], mnH[j-1][i]);
  }
  for(int l=0;l<n;l++) {
    for(int r=0;r<n;r++) {
      mn1[l][r] = 10000000;
      if(r>l) mn1[l][r] = min(mn1[l][r], mn1[l][r-1]);
      if(l) mn1[l][r] = min(mn1[l][r], mnH[l-1][r]);
    }
  }
  for(int i=n-1;i>=0;i--) {
    int curr = ord[i];
    for(int j=i+1;j<n;j++) {
      mnH[i][j] = a[curr][ord[j]];
    }
    for(int j=n-2;j>=i;j--) mnH[i][j] = min(mnH[i][j], mnH[i][j+1]);
  }
  for(int r=n-1;r>=0;r--) {
    for(int l=r;l>=0;l--) {
      mn2[l][r] = 10000000;
      if(l<r) mn2[l][r] = min(mn2[l][r], mn2[l+1][r]);
      if(r<n-1) mn2[l][r] = min(mn2[l][r], mnH[l][r+1]);

      mn[l][r] = min(mn1[l][r], mn2[l][r]);
    }
  }
  for(int i=n-1;i>=0;i--) {
    for(int j=i;j>=0;j--) {
      if(mx[j][i] < mn[j][i]) {
        transition[i+1].push_back(j+1);
      }
    }
  }
  for(int i=0;i<=n;i++) {
    for(int j=0;j<=n;j++) {
      dp[i][j] = 0;
      if(i==0) {
        if(j==0) dp[i][j] = 1;
        else dp[i][j] = 0;
      }
      else {
        for(int x : transition[i]) {
          if(j) {
            dp[i][j] += dp[x-1][j-1];
          }
          dp[i][j] %= mod;
        }
      }
    }
  }
  for(int i=1;i<=n;i++) {
    cout << (dp[n][i]+mod)%mod << " ";
  }
}