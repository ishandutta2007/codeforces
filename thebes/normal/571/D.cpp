#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

namespace output{
    void pr(short x){cout<<x;}
    void pr(unsigned x){cout<<x;}
    void pr(int x){cout<<x;}
    void pr(long long x){cout<<x;}
    void pr(unsigned long long x){cout<<x;}
    void pr(double x){cout<<x;}
    void pr(long double x){cout<<x;}
    void pr(char x){cout<<x;}
    void pr(const char*x){cout<<x;}
    void pr(const string&x){cout<<x;}
    void pr(bool x){cout<<(x?"true":"false");}
    template<class S,class T>
    void pr(const pair<S,T>&x){pr(DEBUG?"(":""),pr(x.first),pr(DEBUG?", ":" "),pr(x.second),pr(DEBUG?")":"");}
    template<class T>
    void pr(const vector<T>&x){pr(DEBUG?"{":"");bool _=0;for(const auto&v:x)pr(_?DEBUG?", ":" ":""),pr(v),_=1;pr(DEBUG?"}":"");}
    template<class T>
    void pr(const set<T>&x){pr(DEBUG?"{":"");bool _=0;for(const auto&v:x)pr(_?DEBUG?", ":" ":""),pr(v),_=1;pr(DEBUG?"}":"");}
    template<class T>
    void pr(const multiset<T>&x){pr(DEBUG?"{":"");bool _=0;for(const auto&v:x)pr(_?DEBUG?", ":" ":""),pr(v),_=1;pr(DEBUG?"}":"");}
    template<class S,class T>
    void pr(const map<S,T>&x){pr(DEBUG?"{":"");bool _=0;for(const auto&v:x)pr(_?DEBUG?", ":" ":""),pr(v),_=1;pr(DEBUG?"}":"");}
    template<class S,class... T>
    void pr(const S&a,const T&...b){pr(a);if(sizeof...(b))pr(" "),pr(b...);else pr('\n');}
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

const int MN = 5e5+5;
ll n, m, i, ds[MN][2], sz[MN], t[MN][2], h[MN][2], lst[MN][2], x, y;
map<ll,ll> psa[MN]; char ch;
ll fnd(ll n,ll p){return ds[n][p]==n?n:fnd(ds[n][p],p);}
ll ttt(ll n,ll p){return ds[n][0]==n?(lst[n][0]>=p?lst[n][0]:0):max(lst[n][0]>=p?lst[n][0]:0,ttt(ds[n][0],max(t[n][0],p)));}
ll qu(ll n,ll p){
    if(ds[n][1]==n){
        if(psa[n].empty()) return 0LL;
        auto it = psa[n].lower_bound(p);
        auto ed = psa[n].end(); ed--;
        if(it==psa[n].begin()) return ed->second;
        else{it--; return ed->second-it->second;}
    }
    else{
        if(psa[n].empty()) return qu(ds[n][1],max(t[n][1],p));
        auto it = psa[n].lower_bound(p);
        auto ed = psa[n].end(); ed--;
        if(it==psa[n].begin()) return ed->second+qu(ds[n][1],max(t[n][1],p));
        else{it--; return ed->second-it->second+qu(ds[n][1],max(t[n][1],p));}
    }
}

int main(){
    scanf("%lld%lld",&n,&m);
    for(i=1;i<=n;i++){
        sz[i]=1;
        ds[i][0]=ds[i][1]=i;
    }
    for(i=1;i<=m;i++){
        scanf(" %c%lld",&ch,&x);
        if(ch=='U'){
            scanf("%lld",&y);
            x=fnd(x,1),y=fnd(y,1);
            if(h[x][1]<h[y][1]) swap(x,y);
            if(h[x][1]==h[y][1]) h[x][1]++;
            sz[x]+=sz[y];
            ds[y][1]=x;
            t[y][1]=i;
        }
        else if(ch=='M'){
            scanf("%lld",&y);
            x=fnd(x,0),y=fnd(y,0);
            if(h[x][0]<h[y][0]) swap(x,y);
            if(h[x][0]==h[y][0]) h[x][0]++;
            ds[y][0]=x;
            t[y][0]=i;
        }
        else if(ch=='Q'){
            ll tt = ttt(x,0);
            printf("%lld\n",qu(x,tt));
        }
        else if(ch=='Z'){
            x = fnd(x,0);
            lst[x][0]=i;
        }
        else if(ch=='A'){
            x = fnd(x,1);
            ll lst=0;
            if(psa[x].size()){auto it=psa[x].end();it--;lst=it->second;}
            psa[x][i]=lst+sz[x];
        }
    }
    return 0;
}