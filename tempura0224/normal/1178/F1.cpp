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
const ll mod=998244353 ;
ll dp[555][555];
ll a[555];

ll rec(int l,int r){
    if(dp[l][r]!=-1)return dp[l][r];
    if(l==r||l+1==r)return dp[l][r]=1;
    int mi = inf, m = -1;
    REP(i,l,r){
        if(a[i]<mi){
            mi=a[i];
            m=i;
        }
    }
    ll vl =0, vr = 0;
    REP(i,l,m+1){
        vl+=rec(l,i)*rec(i,m)%mod;
    }
    REP(i,m+1,r+1){
        vr+=rec(m+1,i)*rec(i,r)%mod;
    }
    vl%=mod;
    vr%=mod;
    return dp[l][r]=vl*vr%mod;
}


int main(){
    int n,m;
    cin>>n>>m;
    rep(i,n)cin>>a[i];
    rep(i,n+1)rep(j,n+1)dp[i][j]=-1;
    cout<<rec(0,n)<<endl;
    return 0;
}