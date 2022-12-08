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

ll powmod(ll n,ll k){
    ll ret=1;
    while(k){
        if(k&1)ret = ret * n %mod;
        n = n * n % mod;
        k/=2;
    }
    return ret;
}

ll dp[55][55][55][55][2];
ll psum, nsum;
int a[55], w[55];
int n, m;
ll rec(int k,int cur, int pd, int nd, int flag){
    if(dp[k][cur][pd][nd][flag]!=-1)return dp[k][cur][pd][nd][flag];
    if(k==m)return cur;
    ll ret=0;
    if(flag){
        ret += rec(k+1,cur, pd, nd+1, flag) * (nsum-nd) %mod * powmod(psum+nsum+pd-nd,mod - 2) %mod ;
        ret += rec(k+1,cur+1, pd+1, nd, flag) * (cur) %mod * powmod(psum+nsum+pd-nd,mod - 2) % mod ;
        ret += rec(k+1,cur, pd+1, nd, flag) * (psum+pd-cur) %mod * powmod(psum+nsum+pd-nd,mod - 2)%mod;
    }
    else  {
        ret += rec(k+1,cur, pd+1, nd, flag) * (psum+pd) %mod * powmod(psum+nsum+pd-nd,mod - 2) % mod ;
        if(cur)ret += rec(k+1,cur-1, pd, nd+1, flag) * (cur) %mod * powmod(psum+nsum+pd-nd,mod - 2) % mod ;
        if(nsum>cur)ret += rec(k+1,cur, pd, nd+1, flag) * (nsum-nd-cur) %mod * powmod(psum+nsum+pd-nd,mod - 2) % mod;
    }
    return dp[k][cur][pd][nd][flag] = ret % mod;
}

int main(){
    cin>>n>>m;
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>w[i];
    rep(i,55)rep(j,55)rep(k,55)rep(x,55)rep(y,2)dp[i][j][k][x][y]=-1;
    rep(i,n){
        if(a[i])psum+=w[i];
        else nsum+=w[i];
    }
    rep(i,n){
        cout<<rec(0,w[i],0,0,a[i])<<endl;
    }
    return 0;
}