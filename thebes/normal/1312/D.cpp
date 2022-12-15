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
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const int MN = 2e5+5, mod = 998244353;
int n, m, i, j, ans;
int qpow(int b,int exp){
    if(exp<=0) return 1;
    else if(exp&1) return 1LL*b*qpow(b,exp-1)%mod;
    else{int r=qpow(b,exp>>1); return 1LL*r*r%mod;}
}
int C(int n,int m){
    int res = 1;
    for(int i=1;i<=n;i++) res=1LL*res*i%mod;
    for(int i=1;i<=m;i++) res=1LL*res*qpow(i,mod-2)%mod;
    for(int i=1;i<=n-m;i++)
        res=1LL*res*qpow(i,mod-2)%mod;
    return res;
}

int main(){
    scanf("%d%d",&n,&m);
    if(n==2){
        printf("0\n");
        return 0;
    }
    int ways = C(m-1,n-2), bad = 0;
    for(i=1;i<m;i++){
        if(i==n-1){
            bad = 1;
        }
        ans = (ans+1LL*(ways-bad+mod)%mod*qpow(2,n-3)%mod)%mod;
        if(i>=n-1){
            bad = 1LL*bad*(i)%mod;
            bad = 1LL*bad*qpow(i-(n-2),mod-2)%mod;
        }
    }
    printf("%d\n",ans);
    return 0;
}