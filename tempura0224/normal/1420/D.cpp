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
void mod_build(int n=1234567){
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
    int n;
    cin>>n;
    int k;
    cin>>k;
    mod_build();
    vector<int> l(n),r(n);
    map<int,int> mp;
    rep(i,n){
        cin>>l[i]>>r[i];
        mp[l[i]]++;mp[r[i]]++;
    }
    int idx=1;
    for(auto& e:mp)e.second = idx++;
    rep(i,n){
        l[i]=mp[l[i]];
        r[i]=mp[r[i]];
    }
    ll ans = 0;
    vector<int> cnt(2*n+2);
    rep(i,n){
        cnt[l[i]]++;cnt[r[i]+1]--;
    }
    rep(i,2*n+1)cnt[i+1]+=cnt[i];
    rep(i,2*n+2)ans+=comb(cnt[i],k);
    vector<int> cntl(2*n+2),cntr(2*n+2);
    int s = 0;
    rep(i,n){
        if(l[i]==r[i])continue;
        cntl[l[i]]++;
        cntr[r[i]]++;
        s++;
    }
    rep(i,2*n+1)cntr[i+1]+=cntr[i];
    for(int i=2*n+1;i>0;i--)cntl[i-1]+=cntl[i];
    REP(i,1,2*n){
        int cnt = s - cntl[i+1] - cntr[i];
        ans += mod-comb(cnt,k);
    }
    cout<<ans%mod<<endl;
    return 0;
}