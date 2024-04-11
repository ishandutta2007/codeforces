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

const int MN = 2e5+5;
int n, t, k, i, j, a[MN], mn, mx, nxt=1;
vi id[MN]; vector<pii> ans;

int main(){
    for(scanf("%d%d%d",&n,&t,&k),i=1;i<=t;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=t;i++){
        mn += max(0,a[i]-a[i+1]);
        mx += a[i];
        if(i!=t) mx--;
    }
    if(mn<=k&&k<=mx){
        id[0].pb(1); k -= mn; a[0] = 1;
        for(i=1;i<=t;i++){
            int meh = min(k,min(a[i],a[i-1])-1);
            int fl = min(a[i-1],a[i])-meh;
            k -= meh;
            for(j=0;j<fl;j++){
                ans.pb({id[i-1][j],++nxt});
                id[i].pb(nxt);
            }
            for(;j<a[i];j++){
                ans.pb({id[i-1][0],++nxt});
                id[i].pb(nxt);
            }
        }
        printf("%d\n",n);
        for(auto v : ans) printf("%d %d\n",v.first,v.second);
    }
    else printf("-1\n");
    return 0;
}