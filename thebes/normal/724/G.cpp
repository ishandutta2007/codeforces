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

const int MN = 1e5+5, MM = 60; const ll mod = 1e9+7;
ll n, m, i, j, k, x, y, w, vs[MN], dep[MN], cmp[MN], basis[MM], z[MM], o[MM], c[MM+2][MM+2], cnt[MM][2], ans;
struct edge{ll x, y, w;}; vector<edge> ed;
vector<pll> adj[MN]; vl tree[MN];

void dfs(ll n,ll p){
    vs[n] = 1;
    for(auto v : adj[n]){
        if(vs[v.F]){
            if(n<v.F) ed.pb({n,v.F,v.S});
            continue;
        }
        dep[v.F] = dep[n]^v.S;
        tree[n].pb(v.F);
        dfs(v.F, n);
    }
}

void dfs2(int n){
    for(j=0;j<MM;j++){
        if((1LL<<j)&dep[n]){
            ans=(ans+((1LL<<j)%mod)*(cnt[j][0]*z[j]%mod+cnt[j][1]*o[j]%mod)%mod)%mod;
            cnt[j][1]++;
        }
        else{
            ans=(ans+((1LL<<j)%mod)*(cnt[j][0]*o[j]%mod+cnt[j][1]*z[j]%mod)%mod)%mod;
            cnt[j][0]++;
        }
    }
    for(auto v : tree[n])
        dfs2(v);
}

int main(){
    for(scanf("%lld%lld",&n,&m),i=1;i<=m;i++){
        scanf("%lld%lld%lld",&x,&y,&w);
        adj[x].pb({y,w});
        adj[y].pb({x,w});
    }
    c[0][0]=1;
    for(i=1;i<MM+1;i++){
        c[i][0]=c[i][i]=1;
        for(j=1;j<i;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    for(i=1;i<=n;i++){
        if(vs[i]) continue;
        ed.clear();
        dfs(i, 0);
        memset(basis,0,sizeof(basis));
        for(auto v : ed){
            ll val = dep[v.x]^dep[v.y]^v.w;
            for(j=MM-1;j>=0;j--){
                if((1LL<<j)&val){
                    if(basis[j]) val^=basis[j];
                    else{
                        basis[j]=val;
                        break;
                    }
                }
            }
        }
        memset(z,0,sizeof(z));
        memset(o,0,sizeof(o));
        for(j=0;j<MM;j++){
            ll a=0, b=0;
            for(k=0;k<MM;k++){
                if(basis[k]){
                    if(basis[k]&(1LL<<j)) a++;
                    else b++;
                }
            }
            for(k=0;k<=a;k+=2)
                z[j]=(z[j]+((1LL<<b)%mod)*c[a][k]%mod)%mod;
            for(k=1;k<=a;k+=2)
                o[j]=(o[j]+((1LL<<b)%mod)*c[a][k]%mod)%mod;
        }
        memset(cnt,0,sizeof(cnt));
        dfs2(i);
    }
    printf("%lld\n",ans);
    return 0;
}