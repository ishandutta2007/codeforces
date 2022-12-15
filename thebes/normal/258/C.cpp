#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

namespace debug{
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
    template<class P1,class P2>
    void __(const pair<P1,P2>&x){__("("),__(x.first),__(", "),__(x.second),__(")");}
    template<class T>
    void __(const vector<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    template<class T>
    void __(const set<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    template<class T>
    void __(const multiset<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    template<class T,class T2>
    void __(const map<T,T2>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(make_pair(v.first,v.second)),_ffs=1;__("}");}
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
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const int MN = 1e5+5, mod = 1e9+7;
int n, k, i, j, x, y, m, ans, lo, hi, lst;
vi arr, a, b;
int qpow(int b,int exp){
    if(exp<=0) return 1;
    else if(exp&1) return 1LL*b*qpow(b,exp-1)%mod;
    else{int r=qpow(b,exp>>1); return 1LL*r*r%mod;}
}

int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&x), arr.pb(x);
    sort(arr.begin(),arr.end());
    for(j=1;j<=100000;j++){
        a.clear(); b.clear();
        for(i=1;i*i<=j;i++){
            if(j%i==0){
                a.pb(i);
                if(i*i!=j) b.insert(b.begin(),j/i);
            }
        }
        for(auto v : b) a.pb(v);
        lst = -1;
        int f=1, g=1;
        a.pb(1e6);
        for(i=0;i+1<a.size();i++){
            lo = lst+1, hi = n;
            while(lo<hi){
                m = (lo+hi)/2;
                if(arr[m]<a[i+1]) lo=m+1;
                else hi=m;
            }
            lo--;
            f=1LL*f*qpow(i+1,lo-lst)%mod;
            lst = lo;
        }
        a.pop_back();
        a.pop_back();
        a.pb(1e6);
        lst = -1;
        for(i=0;i+1<a.size();i++){
            lo = lst+1, hi = n;
            while(lo<hi){
                m = (lo+hi)/2;
                if(arr[m]<a[i+1]) lo=m+1;
                else hi=m;
            }
            lo--;
            g=1LL*g*qpow(i+1,lo-lst)%mod;
            lst = lo;
        }

        if(a.size()==1) g=0;
        ans = (1LL*ans+f-g+mod)%mod;
    }
    printf("%d\n",ans);
    return 0;
}