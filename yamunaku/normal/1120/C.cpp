#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  cin >> n;
  int a,b;
  cin >> a >> b;
  string s;
  cin >> s;

  // z-algorithm 
  vector<vector<int>> z(n,vector<int>(n));
  for(int x=0;x<n;x++){
    z[x][0] = n-x;
    int i = 1, j = 0;
    while (i < n-x) {
      while (i+j < n-x && s[x+j] == s[x+i+j]) ++j;
      z[x][i] = j;
      if (j == 0) { ++i; continue;}
      int k = 1;
      while (i+k < n-x && k+z[x][k] < j) z[x][i+k] = z[x][k], ++k;
      i += k; j -= k;
    }
  }
  vector<vector<int>> cost(n,vector<int>(n,IINF));
  int d;
  for(int i=0;i<n;i++){
    d=0;
    for(int j=0;j<i;j++){
      d=max(d,min(i-j,z[j][i-j]));
    }
    // cout << d << " ";
    for(int j=0;j<d;j++){
      cost[i][i+j]=b;
    }
  }
  // cout << endl;
  for(int i=0;i<n;i++){
    cost[i][i]=min(cost[i][i],a);
  }
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<n;j++){
  //     cout << cost[i][j] << " ";
  //   }
  //   cout<< endl;
  // }
  vector<int> dp(n+1,IINF);
  dp[0]=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
      dp[i+1]=min(dp[i+1],dp[j]+cost[j][i]);
    }
    // cout << dp[i+1] << endl;
  }
  cout << dp[n] << endl;
  return 0;
}