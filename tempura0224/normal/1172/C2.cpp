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

ll dp[3030][3030];
ll powmod(ll n,ll k){
    k%=mod-1;
    if(k<0)k+=mod-1;
    ll ret=1;
    while(k){
        if(k&1)ret=ret*n%mod;
        n=n*n%mod;
        k>>=1;
    }
    return ret;
}
int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    ll w[n];
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>w[i];
    ll psum = 0, nsum = 0;

    ll p[10000];
    rep(i,n){
        if(a[i])psum+=w[i];
        else nsum+=w[i];
    }
    rep(i,2*m+1)p[i]= powmod(psum+nsum+(i-m), mod-2);
    dp[0][0] = 1;
    rep(i,m+1)rep(j,m+1){
        if(i+j>m+1)continue;
        dp[i][j]%=mod;
        ll cp = psum + i ;
        ll cn = nsum - j ;
        if(cn<0||cp+cn<=0)continue;
        ll diff = i - j;
        if(diff < -m||diff>m)continue;
        dp[i+1][j] += cp * p[diff+m] %mod * dp[i][j] %mod;
        dp[i][j+1] += cn * p[diff+m] %mod * dp[i][j] %mod;
    }
    ll P = 0, N = 0;
    rep(i,m+1){
        P += (psum + i) * dp[i][m-i] % mod;
        if(i<nsum)N += (nsum - i) * dp[m-i][i] % mod; 
    }
    P%=mod;
    N%=mod;
    ll pi = powmod (psum, mod -2);
    ll ni = powmod (nsum, mod -2);
    rep(i,n){
        ll ans;
        if(a[i])ans = P * w[i] %mod * pi % mod;
        else ans = N * w[i] %mod * ni % mod;
        printf("%lld\n",ans);
    }

    return 0;
}