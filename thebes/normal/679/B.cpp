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
    template<class T1,class... T2>
    void print(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" "),print(t2...);else __("\n");}
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
map<ll,pll> mp;
pll go(ll n){
    if(!n) return {0,0};
    if(n==1) return {1,1};
    if(mp.count(n)) return mp[n];
    ll x = floor(pow(n,1/3.0));
    if(x*x*x==n) return mp[n]=go(n-1);
    else{
        pll a=go(x*x*x-1), b=go(n-x*x*x);
        b.first++; b.second+=x*x*x;
        return mp[n]=(a.first>b.first?a:b);
    }
}

int main(){
    ll n; scanf("%lld",&n); pll r=go(n);
    printf("%lld %lld\n",r.first,r.second);
    return 0;
}