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

const ll MN = 2e5+5;
ll n, s, i, t[MN], k[MN], st, ed; pll hull[MN];
pll arr[MN]; deque<pll> ok; map<pll,ll> id;

ld intersect(pll &x,pll &y){
    return (ld)(x.second-y.second)/(ld)(y.first-x.first);
}

bool bad(pll &x,pll &y,pll &z){
    return intersect(x,y)>intersect(y,z);
}

ll eval(pll &x,ll t){
    return x.second+x.first*t;
}

int main(){
    for(scanf("%lld%lld",&n,&s),i=1;i<=n;i++){
        scanf("%lld%lld",&arr[i].first,&arr[i].second);
    }
    sort(arr+1,arr+n+1,[](pll i,pll j){return i.first==j.first?i.second<j.second:i.first<j.first;});
    for(i=1;i<=n;i++){
        while(ok.size()){
            if(ok.back().first==arr[i].first) break;
            else if(ok.back().second>=arr[i].second) ok.pop_back();
            else break;
        }
        if(ok.empty()||ok.back().first<arr[i].first) ok.pb(arr[i]);
    }
    ll m = ok.size(); ed=-1; pll pre(-1,-1);
    for(i=1;i<=m;i++){
        pll cur=ok.front(); ok.pop_front();
        assert(cur.first>pre.first&&cur.second>pre.second);
        pre=cur;
        if(cur.second>s) break;
        id[cur]=i;
        if(cur.second==0){
            t[i]=0; k[i]=0;
        }
        else{
            while(ed-st+1>=2){
                pll x=hull[st], y=hull[st+1];
                ll t1=ceil((cur.second-x.second)/(ld)x.first);
                ll t2=ceil((cur.second-y.second)/(ld)y.first);
                if(t1==t2){
                    if(eval(x,t1)<eval(y,t1)) st++;
                    else break;
                }
                else if(t2<t1) st++;
                else break;
            }
            pll x=hull[st];
            ll tt=ceil((cur.second-x.second)/(ld)x.first);
            ll acc=eval(x,tt);
            t[i]=tt; k[i]=acc-cur.second;
        }
        pll ln={cur.first,k[i]-t[i]*cur.first};
        while(ed-st+1>=2){
            pll x=hull[ed-1], y=hull[ed];
            if(bad(x,y,ln)) ed--;
            else break;
        }
        hull[++ed]=ln;
    }
    while(ed-st+1>=2){
        pll x=hull[st], y=hull[st+1];
        ll t1=ceil((s-x.second)/(ld)x.first);
        ll t2=ceil((s-y.second)/(ld)y.first);
        if(t1==t2){
            if(eval(x,t1)<eval(y,t1)) st++;
            else break;
        }
        else if(t2<t1) st++;
        else break;
    }
    pll x=hull[st];
    ll tt=ceil((s-x.second)/(ld)x.first);
    printf("%lld\n",tt);
    return 0;
}