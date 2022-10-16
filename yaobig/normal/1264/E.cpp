#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(A) A.begin(),A.end()
#define sz(A) (int)A.size()
template<class T> inline bool chmax(T &a, T b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) {if(b<a) {a=b; return 1;} return 0;}
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

const int maxn = 2'000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

namespace costflow
{
    using F = int;
    using C = int;
    const F MF = inf;
    const C MC = inf;
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
    {   // Vertices: 1 ... n.
        h.assign(n+1,0);
        vector<C> dis(n+1);
        vi pre(n+1);
    
        priority_queue<pair<C,int> > q;
        C cost = 0; F flow = 0;
        while(mx_flow)
        {
            rep(i,1,n) dis[i] = MC;
            rep(i,1,n) pre[i] = -1;
            static vi mark; mark.assign(n+1,0);
        
            dis[src] = 0; q.push({0,src});
        
            while(q.size())
            {
                auto [d,now] = q.top(); q.pop();
                // Using mark[] is safer than compare -d and dis[now] when the cost is float type.
                if(mark[now]) continue;
                mark[now] = 1;
                for(auto i: to[now])
                {
                    int v=e[i].v;
                    if(e[i].c>0 && chmin(dis[v],dis[now]+e[i].w+h[now]-h[v]))
                    {
                        q.push({-dis[v],v});
                        pre[v] = i;
                    }
                }
            }
            if(pre[sink]==-1) break;
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

int ans[55][55],outd[maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,m)
    {
        int x,y; scanf("%d%d",&x,&y);
        ans[x][y] = 1;
        outd[x]++;
    }
    using costflow::add;
    int N = n, src = ++N, sink = ++N;
    static int id[55][55];
    rep(i,1,n) rep(j,i+1,n) if(ans[i][j]==0 && ans[j][i]==0)
    {
        id[i][j] = ++N;
        add(src,id[i][j],1,0);
        add(id[i][j],i,1,0);
        add(id[i][j],j,1,0);
    }
    rep(i,1,n) rep(c,outd[i],n-1) add(i,sink,1,c*2+1);
    costflow::work(N,src,sink);
    using costflow::e;
    using costflow::to;
    rep(i,1,n) rep(j,i+1,n) if(id[i][j])
    {
        int x = id[i][j];
        for(auto id: to[x]) 
        {
            int y = e[id].v;
            if(y>=1 && y<=n && e[id].c==0) ans[y][y^i^j] = 1;
        }
    }
    rep(i,1,n) rep(j,1,n) printf("%d%s",ans[i][j],j==n ? "\n":"");
    return 0;
}