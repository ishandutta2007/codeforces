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

const int maxn = 805;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

namespace costflow
{
    using F = int;
    using C = db;
    const F MF = 0x3f3f3f3f;
    const C MC = 1e50;
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
    
        priority_queue<pair<C,int> > q;
        C cost = 0; 
        F flow = 0;
        while(mx_flow)
        {
            rep(i,1,n) dis[i] = MC;
            rep(i,1,n) pre[i] = -1;
        
            dis[src] = 0; q.push({0,src});
        
            while(q.size())
            {
                auto [d,now] = q.top(); q.pop();
                if(-d!=dis[now]) continue;
                for(auto i: to[now])
                {
                    int v=e[i].v;
                    db cost = dis[now]+e[i].w+h[now]-h[v];
                    if(e[i].c>0 && dis[v]>cost+1e-10)
                    {
                        dis[v] = cost;
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

db sqr(db x) {return x*x;}

int main()
{
    int n; scanf("%d",&n);
    static int x[maxn+5],y[maxn+5];
    rep(i,1,n) scanf("%d%d",&x[i],&y[i]);
    int N = n*2;
    int src = ++N, sink = ++N;
    using costflow::add;
    rep(i,1,n) add(src,i,1,0);
    rep(i,1,n) add(i+n,sink,2,0);
    rep(i,1,n) rep(j,1,n) if(y[i]<y[j]) add(i,j+n,1,sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j])));
    auto [cost,flow] = costflow::work(N,src,sink);
    if(flow!=n-1) puts("-1");
    else printf("%.15f\n",cost);
    return 0;
}