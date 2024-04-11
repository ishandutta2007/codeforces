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
template <typename A, typename B> 
string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}

void debug_out() {cerr << endl;} 
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) 
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
using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 1<<20;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

typedef int flow_t;
typedef long long cost_t;
const flow_t MF = 0x3f3f3f3f;
const cost_t MC = 1ll<<60;

struct E {int u,v; flow_t c; cost_t w;};
//Clear when initializing.
vector<E> e;
vi to[16010+5];

int src,sink;
 
void add(int u,int v,flow_t c,cost_t w)
{
    to[u].pb(e.size()); e.pb(E{u,v,c,w});
    to[v].pb(e.size()); e.pb(E{v,u,0,-w});
}

pair<cost_t,flow_t> costflow(int n,flow_t k)
{
    vector<cost_t> dis(n+1),h(n+1);
    vi pre(n+1);
    vector<bool> mark(n+1);

    priority_queue<pair<cost_t,int> > q;
    cost_t cost=0; flow_t flow=0;
    while(k)
    {
        rep(i,1,n) dis[i]=MC;
        rep(i,1,n) pre[i]=-1;
        rep(i,1,n) mark[i]=0;
        
        dis[src]=0; q.push({0,src});
        
        while(q.size())
        {
            int now=q.top().SE; q.pop();
            if(mark[now]) continue;
            mark[now]=1;
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
        rep(i,1,n) h[i]+=dis[i];
        flow_t mf=k;
        for(int i=pre[sink];~i;i=pre[e[i].u]) mf=min(mf,e[i].c);
        for(int i=pre[sink];~i;i=pre[e[i].u]) e[i].c-=mf,e[i^1].c+=mf;
        flow+=mf;
        cost+=mf*h[sink];
        k-=mf;
    }
    return {cost,flow};
}

int a[maxn+5],deg[maxn+5],ord[maxn+5];
pii edge[maxn*20+5];

int main()
{
    int n,k; scanf("%d%d",&n,&k); int N=1<<n;
    rep(i,0,N-1) scanf("%d",&a[i]);
    int m=0;
    rep(i,0,N-1) if(__builtin_popcount(i)&1)
    {
        rep(j,0,n-1) edge[++m]={i,i^(1<<j)};
    }
    int K=(2*n-1)*k+1;
    nth_element(edge+1,edge+K,edge+m+1,[](pii &x,pii &y) {return a[x.FI]+a[x.SE]>a[y.FI]+a[y.SE];});
    int M=0; src=++M; sink=++M;
    rep(i,1,K) 
    {
        auto [x,y]=edge[i]; //debug(x, y);
        deg[x]++; deg[y]++;
    }
    rep(i,0,N-1) if(deg[i])
    {
        ord[i]=++M;
        if(__builtin_popcount(i)&1) add(src,M,1,1000000-a[i]);
        else add(M,sink,1,1000000-a[i]);
    }
    rep(i,1,K)
    {
        auto [x,y]=edge[i];
        add(ord[x],ord[y],1,0);
    }
    auto [ans,flow]=costflow(M,k);
    printf("%lld\n",flow*2000000-ans);
    return 0;
}