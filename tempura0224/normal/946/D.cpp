#include <iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<map>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<ll,ll> pint;
const int inf   = 510101010;
const int mod=1e9+7;
const ll longinf=1LL<<60;

int main() {
  int n,m,k;
  cin>>n>>m>>k;
  string s[n];
  vector<int> v[n];
  rep(i,n){
    cin>>s[i];
    rep(j,m)
      if(s[i][j]=='1')v[i].push_back(j);
    }
  int t[n][505];
  rep(i,n){
    rep(j,505)t[i][j]=inf;
    int sz=v[i].size();
    rep(j,sz){
      rep(h,j+1){
        t[i][j]=min(t[i][j],v[i][h+sz-j-1]-v[i][h]+1);
        }
      }
    REP(j,sz,k+1)t[i][j]=0;
    }
  int dp[505][505];
  rep(i,k+1)dp[0][i]=0;
  rep(i,n){
    rep(j,k+1){
      dp[i+1][j]=inf;
      rep(h,j+1){
        dp[i+1][j]=min(dp[i+1][j],dp[i][h]+t[i][j-h]);
        }
      }
    }
  cout<<dp[n][k]<<endl;
  return 0;
  }