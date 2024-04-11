#include <bits/stdc++.h>
using namespace std;

namespace debug{
    void __(short x){cout<<x;}
    void __(int x){cout<<x;}
    void __(long long x){cout<<x;}
    void __(unsigned long long x){cout<<x;}
    void __(double x){cout<<x;}
    void __(long double x){cout<<x;}
    void __(char x){cout<<x;}
    void __(const char*x){cout<<x;}
    void __(const string&x){cout<<x;}
    void __(bool x){cout<<(x?"true":"false");}
    template<class P1,class P2>
    void __(const pair<P1,P2>&x){__("("),__(x.first),__(", "),__(x.second),__(")");}
    template<class T>
    void __(const vector<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    void screm(){__("\n");}
    template<class T1,class... T2>
    void screm(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" | "),screm(t2...);else __("\n");}
    void pr(){__("\n");}
    template<class T1,class... T2>
    void pr(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" "),pr(t2...);else __("\n");}

}

using namespace debug;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(x);i>=(y);i--)

const ll MN = 1e6+6, mod = 1e9+7;
ll dp[MN], cnt[MN], n, i, j, s[MN], x, sm;
vi adj[MN];

void go(ll n){
    for(auto v : adj[n]){
        go(v);
        s[n] += s[v];
    }
}

int main(){
    for(scanf("%lld",&n),i=1;i<=n;i++) scanf("%lld",&s[i]);
    for(i=1;i<n;i++){
        scanf("%lld",&x);
        adj[x].pb(i+1);
    }
    go(1);
    sm = s[1];
    for(i=1;i<=n;i++){
        x = sm/__gcd(sm,s[i]);
        for(j=x;j<=n;j+=x) cnt[j]++;
    }
    for(i=n;i>=1;i--){
        if(sm%i!=0||cnt[i]<i) continue;
        for(j=2*i;j<=n;j+=i){
            dp[i]+=dp[j];
            if(dp[i]>=mod) dp[i]-=mod;
        }
        dp[i]++;
        if(dp[i]>=mod) dp[i]-=mod;
    }
    printf("%lld\n",dp[1]);
    return 0;
}