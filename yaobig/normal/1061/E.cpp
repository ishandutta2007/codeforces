#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(A) A.begin(),A.end()
#define sz(A) (int)A.size()
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;

string to_string(const string& s) {return '"' + s + '"';}
string to_string(const char* s) {return to_string((string) s);}
template<typename A, typename B> string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}
template<typename A> string to_string(A v) 
{
    bool first = 1;
    string res = "{";
    for(const auto &x: v) 
    {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() {cerr << endl;} 
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) 
{
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifndef ONLINE_JUDGE
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) if(0) puts("No effect.")
#endif

using ll = long long;
//using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 1010;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

namespace costflow
{
    using F = int;
    using C = ll;
    const F MF = 0x3f3f3f3f;
    const C MC = 1ll<<60;
    struct E {int u,v; F c; C w;};
    //Clear when initializing.
    vector<E> e;
    vi to[maxn+5];
    void add(int u,int v,F c,C w)
    {
        to[u].pb(e.size()); e.pb(E{u,v,c,w});
        to[v].pb(e.size()); e.pb(E{v,u,0,-w});
    }
    vector<C> h;
    pair<C,F> work(int n,int src,int sink,F mx_flow = MF)
    {
        h.assign(n+1,0);
        vector<C> dis(n+1);
        vi pre(n+1);

        // ran Bellman-Ford first if necessary.
        rep(i,1,n) dis[i] = MC;
        dis[src] = 0;
        rep(rd,1,n) rep(now,1,n) for(auto i: to[now])
        {
            int v=e[i].v;
            if(e[i].c>0) chmin(dis[v],dis[now]+e[i].w);
        }
        rep(i,1,n) h[i] = dis[i];
    
        priority_queue<pair<C,int> > q;
        C cost=0; F flow = 0;
        while(mx_flow)
        {
            rep(i,1,n) dis[i] = MC;
            rep(i,1,n) pre[i] = -1;
        
            dis[src]=0; q.push({0,src});
        
            while(q.size())
            {
                auto [d,now] = q.top(); q.pop();
                if(d!=-dis[now]) continue;
                for(auto i: to[now])
                {
                    int v=e[i].v;
                    if(e[i].c>0 && chmin(dis[v],dis[now]+e[i].w+h[now]-h[v]))
                    {
                        q.push({-dis[v],v});
                        pre[v]=i;
                    }
                }
            }
            if(dis[sink]==MC) break;
            rep(i,1,n) h[i] += dis[i];
            F mf = mx_flow;
            for(int i=pre[sink];~i;i=pre[e[i].u]) chmin(mf,e[i].c);
            for(int i=pre[sink];~i;i=pre[e[i].u]) e[i].c-=mf, e[i^1].c+=mf;
            mx_flow -= mf;
            flow += mf;
            cost += mf*h[sink];
        }
        return {cost,flow};
    }
}

int a[maxn+5];
vi e[2][maxn+5];
int b[2][maxn+5];
set<pii> S;

void dfs1(int now,int fa)
{
    if(b[0][now]!=inf) S.insert({fa,now});
    costflow::add(fa,now,b[0][now],b[0][now]==inf?0:-inf);
    for(auto v: e[0][now]) if(v!=fa) dfs1(v,now);
}
void dfs2(int now,int fa)
{
    if(b[1][now]!=inf) S.insert({now,fa});
    costflow::add(now,fa,b[1][now],b[1][now]==inf?0:-inf);
    for(auto v: e[1][now]) if(v!=fa) dfs2(v,now);
}

int main()
{
    int n; scanf("%d",&n);
    int x,y; scanf("%d%d",&x,&y); y+=n;
    rep(i,1,n) scanf("%d",&a[i]);
    int N = n*2; int src = ++N, sink = ++N;
    rep(i,1,n) costflow::add(i,i+n,1,-a[i]);
    rep(o,0,1) rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y); 
        if(o==1) x+=n,y+=n;
        e[o][x].pb(y);
        e[o][y].pb(x);
    }
    rep(o,0,1)
    {
        int q; scanf("%d",&q);
        memset(b[o],0x3f,sizeof b[o]);
        while(q--)
        {
            int k,x; scanf("%d%d",&k,&x); if(o==1) k+=n;
            b[o][k] = x;
        }
    }
    dfs1(x,src);
    dfs2(y,sink);
    auto ans = -costflow::work(N,src,sink).FI;
    rep(o,0,1) rep(i,1,n*2) if(b[o][i]!=inf) ans -= 1ll*b[o][i]*inf;
    int ok = 1;
    for(auto [u,v,c,w]: costflow::e) if(S.count({u,v}) && c!=0) ok = 0;
    if(ok==0) puts("-1");
    else printf("%lld\n",ans);
    return 0;
}