#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
using ll = long long;
const int MX = 2e5+5;
int dp[3200][81][81];
int get(int a, int b, int c) {
  if(a<0 || b<0 || c<0) return 1e9;
  if(c>b) return 1e9;
  return dp[a][b][c];
}
int main() {
  int n; cin >> n;
  int a[n];
  for(int i=0;i<n;i++) cin >> a[i];
  int num = 0;
  vector<int> pos;
  for(int i=0;i<n;i++) num+=a[i];
  for(int i=0;i<n;i++) {
    if(a[i]==1) pos.push_back(i+1);
  }
  for(int x=0;x<=n*(n-1)/2;x++) {
    for(int y=1;y<=n;y++) {
      for(int z=0;z<=num;z++) {
        dp[x][y][z] = 1e9;
        if(z==0) {
          dp[x][y][z] = y*y;
          continue;
        }
        for(int put=1;put<=y;put++) {
          int dist = abs(put - pos[z - 1]);
          dp[x][y][z] = min(dp[x][y][z], get(x-dist, put - 1, z - 1) + (y - put)*(y - put));
        }
      }
    }
  }
  for(int i=0;i<=n*(n-1)/2;i++) {
    cout << ((n - num)*(n - num) - dp[i][n][num])/2 << "\n";
  }
}