#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int dist[16][16],dist2[16][16];
int n,m,dp[16][16][1<<16];

int rec(int x,int y,int mask){
    if(dp[x][y][mask]!=-1)return dp[x][y][mask];
    int ret=0;
    int res=mask^(1<<y);
    if(res==0)return dp[x][y][mask]=dist2[x][y];
    rep(i,n){
        if((1<<i)&res)ret=max(ret,min(dist[y][i],rec(x,i,res)));
    }
    return dp[x][y][mask]=ret;
}
int main(){
    cin>>n>>m;
    int a[n][m];
    rep(i,n)rep(j,m)cin>>a[i][j];
    rep(i,n)rep(j,n)dist[i][j]=dist2[i][j]=inf;
    rep(i,n)rep(j,n)rep(k,m)dist[i][j]=min(dist[i][j],abs(a[i][k]-a[j][k]));
    rep(i,n)rep(j,n)rep(k,m-1)dist2[i][j]=min(dist2[i][j],abs(a[i][k+1]-a[j][k]));
    int ret=0;
    int mask=1<<n;
    rep(i,n)rep(j,n)rep(k,mask)dp[i][j][k]=-1;
    rep(i,n)ret=max(ret,rec(i,i,mask-1));
    cout<<ret<<endl;
    return 0;
}