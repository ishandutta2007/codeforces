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

ll h, m, k, ans, h1, h2, m1, m2, ms, mh, mmm;

int main(){
    scanf("%lld%lld%lld%lld%lld%lld%lld",&h,&m,&k,&h1,&m1,&h2,&m2);
    ll sw = m-1;
    while(sw){
        if(sw%10!=0) ms++;
        sw/=10;
    }
    sw = h-1;
    while(sw){
        if(sw%10!=0) mh++;
        sw/=10;
    }
    int ch = max(0LL,k-ms-1);
    ll mn=1, hr=1;
    for(int i=0;i<k-1;i++) mn*=10;
    for(int i=0;i<ch;i++) hr*=10;
    if(h1==h2&&m1<=m2){
        ans += (m2/mn);
        if(m1>1) ans -= (m1/mn);
        printf("%lld\n",ans);
        return 0;
    }
    if(m1) ans += ((m-1)/mn)-(m1/mn);
    ll rr = h1;
    ans -= (h1/hr);
    int flg=0;
    if(m1){
        h1++; m1=0;
        if(h1==h){
            h1=0;
            if(ms+mh>=k) ans++;
        }
        else if((h1/hr)!=(rr/hr)) ans++,flg=1;
    }
    if(m2) ans += (m2/mn), m2=0;
    ll kek = (m-1)/mn;
    if(h1>h2){
        ans += ((h-1)/hr)+(h2/hr)-flg;
        ll delta = (h-h1)+(h2);
        ans += delta*kek;
        if(ms+mh>=k) ans++;
    }
    else{
        ans += (rr/hr)-(h1/hr)+(h2/hr)+kek*(h2-h1);
    }
    printf("%lld\n",ans);
    return 0;
}