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

const int MN = 5e5+5, mod = 1e9+7;
int N, M, i, x, y, f, nxt, dis[MN], vis[MN];
vector<pii> adj[MN];
vi s[MN], hm[10];

int main(){
    scanf("%d%d",&N,&M);
    nxt = N;
    fox(i,1,M){
        scanf("%d%d",&x,&y);
        int t = i, l = y, p;
        while(t>=10){
            adj[++nxt].pb({l,t%10});
            l = nxt; t /= 10;
        }
        adj[x].pb({l,t%10});
        t = i, l = x; p = nxt;
        while(t>=10){
            adj[p].pb({l,t%10});
            l = p--; t /= 10;
        }
        adj[y].pb({l,t%10});
    }
    s[0].pb(1); vis[1]=1;
    memset(dis,0x3f,sizeof(dis)); dis[1]=0;
    fox(i,0,f){
        fox(j,0,9) hm[j].clear();
        for(auto v : s[i]){
            for(auto w : adj[v]){
                if(!vis[w.first]) dis[w.first]=min(dis[w.first],w.second);
            }
        }
        for(auto v : s[i]){
            for(auto w : adj[v]){
                if(!vis[w.first]){
                    vis[w.first] = 1;
                    hm[dis[w.first]].pb(w.first);
                    dis[w.first]=(10LL*dis[v]+dis[w.first])%mod;
                }
            }
        }
        fox(j,0,9){
            if(hm[j].size()) s[++f]=hm[j];
        }
    }
    fox(i,2,N) printf("%d\n",dis[i]);
    return 0;
}