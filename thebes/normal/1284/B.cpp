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

const int MN = 1e5+5;
ll n, i, j, x, mn, mx, ok[MN], ans, bit[2*MN], kk;
pll a[MN]; map<ll,ll> mp;
void upd(ll p){for(;p<=2*n;p+=p&-p)bit[p]++;}
ll qu(ll p){ll r=0;for(;p;p-=p&-p)r+=bit[p]; return r;}

int main(){
    scanf("%lld",&n);
    fox(i,1,n){
        ll m; scanf("%lld",&m);
        mn = 1<<30; mx = 0;
        fox(j,1,m){
            scanf("%lld",&x);
            if(x>mn) ok[i]=1;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        a[i]={mn,mx};
        mp[a[i].first]=mp[a[i].second]=0;
    }
    i=0;
    for(auto it = mp.begin(); it != mp.end();it++) it->second=++i;
    fox(i,1,n){
        if(ok[i]) kk++,ans += 2*n+1-2*kk;
        else{
            upd(mp[a[i].first]);
            ans += qu(mp[a[i].second]-1);
        }
    }
    memset(bit,0,sizeof(bit));
    foxr(i,1,n){
        if(ok[i]) continue;
        ans += qu(mp[a[i].second]-1);
        upd(mp[a[i].first]);
    }
    printf("%lld\n",ans);
    return 0;
}