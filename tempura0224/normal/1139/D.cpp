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
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

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
ll pow(ll n,ll k){
    ll ret=1;
    while(k){
        if(k&1)ret=ret*n%mod;
        n=n*n%mod;
        k>>=1;
    }
    return ret;
}
int main(){
    int m;
    cin>>m;
    mod_build();
    vector<int> meb(101010,-1),isprime(101010,1);
    meb[0]=meb[1]=0;
    isprime[0]=isprime[1]=0;
    rep(i,m+1){
        if(!isprime[i])continue;
        for(int j=2;j*i<=m;j++){
            isprime[i*j]=false;
        }
        for(int j=1;j*i<=m;j++){
            meb[i*j]*=-1;
            if(j%i==0)meb[i*j]=0;
        }
    }
    ll ans=1;
    REP(i,2,m+1){
        int k=m/i;
        ll res=k*inv[m-k]%mod;
        if(meb[i]==1)ans+=res;
        else if(meb[i]==-1)ans+=mod-res;
    }
    cout<<ans%mod<<endl;
    return 0;
}