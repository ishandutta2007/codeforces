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

const int MN = 3e5+5;
ll n, m, t, r, i, x, ans[MN]; char ch;
vector<pll> ini, res; pic a[MN];

int main(){
    scanf("%lld%lld%lld",&n,&m,&t);
    r=t; t%=m;
    pll orig(-1,-1), fs(-1,-1);
    for(i=1;i<=n;i++){
        scanf("%lld %c",&x,&ch);
        a[i]={x,ch};
        if(ch=='L'){
            ll pos=(x-1-t)%m;
            if(pos<0) pos+=m;
            res.pb({pos+1,0});
            if(orig.F==-1) orig={pos+1,0};
        }
        else{
            ll pos=(x-1+t)%m;
            res.pb({pos+1,1});
            if(orig.F==-1) orig={pos+1,1};
        }
        ini.pb({x,i});
        if(fs.F==-1) fs={x,i};
    }
    sort(ini.begin(),ini.end(),[](pll i,pll j){return i.F<j.F;});
    sort(res.begin(),res.end(),[](pll i,pll j){return i.F==j.F?i.S<j.S:i.F<j.F;});
    int ot=0, ot2=0;
    for(;ot<ini.size()&&ini[ot]!=fs;ot++){}
    for(;ot2<res.size()&&res[ot2]!=orig;ot2++){}
    pic idk=a[ini[ot].S];
    ll sh=0;
    for(i=1;i<=n;i++){
        if(a[i].S!=idk.S){
            ll dis;
            if(idk.S=='R') dis=a[i].F-idk.F;
            else dis=idk.F-a[i].F;
            if(dis<0) dis+=m;
            if(dis<=2*r){
                sh++;
                sh+=(2*r-dis)/m;
                sh%=n;
            }
        }
    }
    if(idk.S=='R'){
        ot2=(ot2-sh)%n;
        if(ot2<0) ot2+=n;
    }
    else{
        ot2=(ot2+sh)%n;
    }
    for(i=0;i<n;i++)
        ans[ini[(ot+i)%n].S]=res[(ot2+i)%n].F;
    for(i=1;i<=n;i++)
        printf("%lld ",ans[i]);
    pr();
    return 0;
}