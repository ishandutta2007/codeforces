#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
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

const ll MM = 300000008;
bitset<MM> p;
ll l, r, i, j, ans;

int main(){
    scanf("%lld%lld",&l,&r);
    p[1]=1;
    for(i=2;i*i<MM;i++){
        if(p[i]) continue;
        for(j=i*i;j<MM;j+=i) p[j]=1;
    }
    if(l<=2&&2<=r) ans++;
    i=(l/4)*4+1;
    if(i<l) i+=4;
    for(;i<=r;i+=4) ans+=!p[i];
    printf("%lld\n",ans);
    return 0;
}