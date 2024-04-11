#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

namespace output{
    void __(short x){cout<<x;}
    void __(unsigned x){cout<<x;}
    void __(int x){cout<<x;}
    void __(long long x){cout<<x;}
    void __(unsigned long long x){cout<<x;}
    void __(double x){cout<<x;}
    void __(long double x){cout<<x;}
    void __(char x){cout<<x;}
    void __(const char*x){cout<<x;}
    void __(const string&x){cout<<x;}
    void __(bool x){cout<<(x?"true":"false");}
    template<class S,class T>
    void __(const pair<S,T>&x){__(DEBUG?"(":""),__(x.first),__(DEBUG?", ":" "),__(x.second),__(DEBUG?")":"");}
    template<class T>
    void __(const vector<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const set<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const multiset<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class S,class T>
    void __(const map<S,T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    void pr(){cout<<"\n";}
    template<class S,class... T>
    void pr(const S&a,const T&...b){__(a);if(sizeof...(b))__(' ');pr(b...);}
}

using namespace output;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,char> pic;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

#define F first
#define S second

const int MN = 2020, MM = 2e5+5, mod = 1e9+7, LG = 25;
int n, m, k, s, fac[MM]={1}, inv[MM]={1}, dp[MN][LG], ps[MN][LG], i, j, l, st, a;
pii pnt[MN];

int qpow(int b,int exp){
    if(exp<=0) return 1;
    else if(exp&1) return 1LL*b*qpow(b,exp-1)%mod;
    else{int r=qpow(b,exp>>1); return 1LL*r*r%mod;}
}

inline int C(int a,int b){
    return 1LL*fac[pnt[b].F+pnt[b].S-pnt[a].F-pnt[a].S]*inv[pnt[b].F-pnt[a].F]%mod*inv[pnt[b].S-pnt[a].S]%mod;
}

int main(){
    for(i=1;i<MM;i++){
        fac[i]=1LL*fac[i-1]*i%mod;
        inv[i]=1LL*inv[i-1]*qpow(i,mod-2)%mod;
    }
    scanf("%d%d%d%d",&n,&m,&k,&s);
    for(i=1;i<=k;i++){
        scanf("%d%d",&pnt[i].first,&pnt[i].second);
    }
    sort(pnt+1,pnt+k+1,[](pii i,pii j){return i.F+i.S<j.F+j.S;});
    if(pnt[k]!=make_pair(n,m)) pnt[++k]={n,m};
    else a++;
    if(pnt[1]!=make_pair(1,1)) pnt[0]={1,1}, st=0;
    else st=1, a++;
    for(i=st+1;i<=k;i++){
        for(j=0;j<LG;j++){
            int ok = C(st,i);
            for(l=st+1;l<i;l++){
                if(pnt[l].F<=pnt[i].F&&pnt[l].S<=pnt[i].S){
                    ok=(ok-1LL*C(l,i)*dp[l][j])%mod;
                    while(ok<0) ok+=mod;
                }
            }
            ps[i][j]=ok;
            if(j) dp[i][j]=ps[i][j]-ps[i][j-1];
            else dp[i][j]=ps[i][j];
            if(dp[i][j]<0) dp[i][j]+=mod;
        }
    }
    int res = C(st,k)-ps[k][LG-1]+mod;
    if(res>=mod) res-=mod;
    int tot = C(st,k), exp = res;
    while(a--) s-=(s/2);
    for(j=0;j<LG;j++){
        exp=(exp+1LL*s*dp[k][j])%mod;
        s-=(s/2);
    }
    printf("%d\n",1LL*exp*qpow(tot,mod-2)%mod);
    return 0;
}