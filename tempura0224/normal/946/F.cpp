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
  int n,x;cin>>n>>x;
  string s;
  cin>>s;
  ll left[101][101][101],right[101][101][101],mid[101][101][101],ans[101][101][101];
  rep(i,x+1)rep(j,n+1)rep(k,n+1)left[i][j][k]=right[i][j][k]=mid[i][j][k]=ans[i][j][k]=0;
  rep(i,n){
    if(s[i]=='0')left[0][i][i]=right[0][i][i]=mid[0][i][i]=ans[0][i][i]=1;
    else left[1][i][i]=right[1][i][i]=mid[1][i][i]=ans[1][i][i]=1;
    }
  ll p[x+1];
  p[0]=p[1]=2;
  rep(i,x-1)
    p[i+2]=(p[i+1]*p[i])%mod;
  rep(i,x-1){
    rep(j,n)REP(k,j,n){
      REP(h,j,k){
        left[i+2][j][k]=(left[i+2][j][k]+mid[i+1][j][h]*left[i][h+1][k])%mod;
        right[i+2][j][k]=(right[i+2][j][k]+right[i+1][j][h]*mid[i][h+1][k])%mod;
        mid[i+2][j][k]=(mid[i+2][j][k]+mid[i+1][j][h]*mid[i][h+1][k])%mod;
        ans[i+2][j][k]=(ans[i+2][j][k]+right[i+1][j][h]*left[i][h+1][k])%mod;
        }
      left[i+2][j][k]=(left[i+2][j][k]+left[i+1][j][k]*p[i]+left[i][j][k])%mod;
      right[i+2][j][k]=(right[i+2][j][k]+right[i+1][j][k]+right[i][j][k]*p[i+1])%mod;
      mid[i+2][j][k]=(mid[i+2][j][k]+mid[i+1][j][k]+mid[i][j][k])%mod;
      ans[i+2][j][k]=(ans[i+2][j][k]+ans[i+1][j][k]*p[i]+ans[i][j][k]*p[i+1])%mod;
      }
    }
  cout<<ans[x][0][n-1]<<endl;
  
  return 0;
        
                         
  }