#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
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

const int MN = 1e5+5;
ll lo, hi, mid, cnt, N, K, i, x, arr[MN], ans[MN];
ll f(ll x){
    if(abs(x)>1e16) return (ll)(sqrt((ld)12)*sqrt((ld)-x+0.75)-3)/6;
    else return (ll)(sqrt(9-12*x)-3)/6;
}

int main(){
    scanf("%lld%lld",&N,&K);
    for(i=1;i<=N;i++)
        scanf("%lld",&arr[i]);
    lo=-6000000000, hi=6000000000;
    lo*=1e9, hi*=1e9;
    while(lo<hi){
        mid = (lo+hi)>>1;
        cnt = 0;
        for(i=1;i<=N;i++){
            if(mid+1-arr[i]>0) continue;
            cnt += min(arr[i],f(mid+1-arr[i]));
            if(cnt<0) cnt=K;
            if(cnt>=K) break;
        }
        if(cnt>=K) lo=mid+1;
        else hi=mid;
    }
    for(i=1;i<=N;i++){
        if(lo+1-arr[i]>0) continue;
        ll inc = min(arr[i],f(lo+1-arr[i]));
        ans[i] = inc;
        K -= inc;
    }
    lo--;
    for(i=N;i>=1&&K;i--){
        if(lo+1-arr[i]>0) continue;
        if(ans[i]<arr[i]&&arr[i]-3*(ans[i]+1)*(ans[i]+1)-3*(ans[i]+1)-1>=lo)
                ans[i]++, K--;
    }
    for(i=1;i<=N;i++)
        printf("%lld ",ans[i]);
    printf("\n");
    return 0;
}