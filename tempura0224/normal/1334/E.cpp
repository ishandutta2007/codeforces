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
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=998244353 ;

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
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    mod_build(1234567);
    ll n;
    cin>>n;
    vector<bool> isprime(32000000,1);
    isprime[0]=isprime[1]=0;
    vector<ll> prime;
    REP(i,2,32000000){
        if(!isprime[i])continue;
        if(n%i==0){
            prime.push_back(i);
            while(n%i==0)n/=i;
        }
        for(int j=2*i;j<32000000;j+=i)isprime[j]=false;
    }
    if(n>1)prime.push_back(n);
    int q;
    cin>>q;
    int m=prime.size();
    while(q--){
        ll s,t;
        cin>>s>>t;
        ll ans = 1;
        int suml = 0, sumr=0;
        rep(i,m){
            int l=0,r=0;
            while(s%prime[i]==0){
                s/=prime[i];
                l++;
            }
            while(t%prime[i]==0){
                t/=prime[i];
                r++;
            }
            if(l>r){
                ans *= comb(suml+l-r,l-r);
                suml += l-r;
            }
            else {
                ans *= comb(sumr+r-l,r-l);
                sumr += r-l;
            }
            ans%=mod;
        }
        cout<<ans<<'\n';
    }
    return 0;
}