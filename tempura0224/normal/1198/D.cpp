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
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


int dp[55][55][55][55];

int h[55][55], w[55][55];
int rec(int lx,int ly,int rx, int ry){
    if(dp[lx][ly][rx][ry]!=-1)return dp[lx][ly][rx][ry];
    if(lx==rx||ly==ry)return 0;
    int ret = max(rx-lx, ry-ly);
    REP(i,lx,rx){
        if(h[i][ry]-h[i][ly]==0)ret=min(ret,rec(lx,ly,i,ry)+rec(i+1,ly,rx,ry));
    }
    REP(i,ly,ry){
        if(w[rx][i]-w[lx][i]==0)ret=min(ret,rec(lx,ly,rx,i)+rec(lx,i+1,rx,ry));
    }
    return dp[lx][ly][rx][ry]=ret;
}

int main(){
    int n;
    cin>>n;
    string s[n];
    rep(i,n)cin>>s[i];
    rep(i,n)rep(j,n){
        w[i+1][j]=h[i][j+1]=(s[i][j]=='#');
    }
    rep(i,n+1)rep(j,n+1){
        h[i][j+1]+=h[i][j];
        w[i+1][j]+=w[i][j];
    }
    rep(i,n+1)rep(j,n+1)rep(k,n+1)rep(l,n+1)dp[i][j][k][l]=-1;
    cout<<rec(0,0,n,n)<<endl;
    return 0;
}