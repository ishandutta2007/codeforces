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

const int maxn = 1000;
const int mod = 1000000007;
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
            if(h[sink]+dis[sink]>=0) break;
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
    // calculate distance on residual graph
    vector<C> cal_dis(int n,int st) 
    {
        static vector<C> dis; 
        dis.assign(n+1,MC);

        static priority_queue<pair<C,int> > q;
        dis[st]=0; q.push({0,st});
        
        while(q.size())
        {
            auto [d,now] = q.top(); q.pop();
            if(d!=-dis[now]) continue;
            for(auto i: to[now])
            {
                int v=e[i].v;
                //debug(now,v,e[i].c,e[i].);
                if(e[i].c>0 && chmin(dis[v],dis[now]+e[i].w+h[now]-h[v])) q.push({-dis[v],v});
            }
        }
        rep(i,1,n) dis[i] += h[i];
        return dis;
    };
}

int a[maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&a[i]);
    int N = n; int src = ++N, sink = ++N;
    rep(i,1,n) costflow::add(src,i,1,0);
    rep(i,1,n) costflow::add(i,sink,1,0);
    rep(i,1,m)
    {
        int x,y; scanf("%d%d",&x,&y);
        costflow::add(x,y,n,-(a[x]-a[y]));
    }
    costflow::work(N,src,sink);
    auto dis = costflow::cal_dis(N,src);
    rep(i,1,n) printf("%lld%c",-dis[i]+a[i]," \n"[i==n]);
    return 0;
}