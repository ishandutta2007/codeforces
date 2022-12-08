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


vector<ll> inv,fact,invfact;
void mod_build(int n=101010){
    fact.resize(n+1);
    inv.resize(n+1);
    invfact.resize(n+1);
    fact[0]=inv[0]=invfact[0]=1;
    inv[1]=1;
    rep(i,n){
        fact[i+1]=fact[i]*(i+1)%mod;
        if(i>0)inv[i+1]=mod-inv[mod%(i+1)]*(mod/(i+1))%mod;
        invfact[i+1]=invfact[i]*inv[i+1]%mod;
    }
}
ll perm(int n,int k){
    if(n<0||k<0||k>n)return 0;
    return fact[n]*invfact[n-k]%mod;
}
ll comb(int n,int k){
    if(n<0||k<0||k>n)return 0;
    return (fact[n]*invfact[n-k]%mod)*invfact[k]%mod;
}
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
    cout<<powmod(2,n+m)<<endl;
    return 0;
}