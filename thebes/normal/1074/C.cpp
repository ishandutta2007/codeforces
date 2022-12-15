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
int n, i, j, x, y, ans, go, hm;
vector<pii> pnt, a[4], tmp; set<int> X, Y;
int dis(pii i,pii j){return abs(i.F-j.F)+abs(i.S-j.S);}
inline bool cp(pii i,pii j,pii o){return 1LL*(i.F-o.F)*(j.S-o.S)-1LL*(i.S-o.S)*(j.F-o.F)<0LL;}

void rec(int d){
    if(d==4){
        if(tmp.size()>go) return;
        int dist=0;
        for(int i=0;i<tmp.size();i++)
            dist+=dis(tmp[i],tmp[(i+1)%tmp.size()]);
        for(int i=0;i<tmp.size();i++){
            if(!cp(tmp[(i+1)%tmp.size()],tmp[(i+2)%tmp.size()],tmp[i])) return;
        }
        ans=max(ans,dist);
    }
    else{
        for(int i=0;i<hm;i++){
            tmp.pb(a[d][i]);
            rec(d+1);
            tmp.pop_back();
        }
        rec(d+1);
    }
}

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        pnt.pb({x,y});
        X.insert(x);
        Y.insert(y);
    }
    hm=min(n,3);
    sort(pnt.begin(),pnt.end(),[](pii i,pii j){return i.S>j.S;});
    for(i=0;i<hm;i++)
        a[0].pb(pnt[i]);
    sort(pnt.begin(),pnt.end(),[](pii i,pii j){return i.F>j.F;});
    for(i=0;i<hm;i++)
        a[1].pb(pnt[i]);
    sort(pnt.begin(),pnt.end(),[](pii i,pii j){return i.S<j.S;});
    for(i=0;i<hm;i++)
        a[2].pb(pnt[i]);
    sort(pnt.begin(),pnt.end(),[](pii i,pii j){return i.F<j.F;});
    for(i=0;i<hm;i++)
        a[3].pb(pnt[i]);
    for(auto h : pnt){
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                for(auto v : a[i]){
                    for(auto u : a[j]){
                        ans=max(ans,dis(v,u)+dis(v,h)+dis(u,h));
                    }
                }
            }
        }
    }
    printf("%d ",ans);
    if(n>3){
        go=4; ans=0;
        rec(0);
        for(i=4;i<=n;i++)
            printf("%d ",ans);
    }
    printf("\n");
    return 0;
}