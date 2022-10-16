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

const int maxn = 200000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

struct Union_Set
{
    array<int,maxn+5> fa,sz,mark;
    int timer;
    void init(int n) 
    {
        timer = 1;
        rep(i,1,n) mark[i] = 0;
    }
    void clear() { timer++; }
    int getfa(int x) 
    {
        if(mark[x]!=timer) mark[x] = timer, fa[x] = x, sz[x] = 1;
        return fa[x]==x?x:fa[x]=getfa(fa[x]);
    }
	bool check(int x,int y) {return getfa(x)==getfa(y);}
    bool merge(int x,int y)
    {
        int fx=getfa(x),fy=getfa(y);
        if(fx==fy) return 0;
        if(sz[fx]<sz[fy]) swap(fx,fy);
        fa[fy]=fx;
        sz[fx]+=sz[fy];
        return 1;
    }
}us;

vi pool[maxn+5];
vi e[maxn+5];
int a[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n)
    {
        int x; scanf("%d",&x); pool[x].pb(i); a[i] = x;
    }
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    us.init(n);

    static ll f[maxn+5];
    rep(x,1,maxn) 
    {
        us.clear();
        for(int y=x; y<=maxn; y+=x) for(auto u: pool[y]) for(auto v: e[u]) if(a[v]%x==0) us.merge(u,v);
        for(int y=x; y<=maxn; y+=x) for(auto u: pool[y])
        {
            f[x]++;
            if(us.getfa(u)==u) f[x] += 1ll*us.sz[u]*(us.sz[u]-1)/2;
        }
    }
    static int np[maxn+5];
    vi P;
    rep(i,2,maxn) if(np[i]==0)
    {
        P.pb(i);
        for(int j=i*2; j<=maxn; j+=i) np[j] = 1;
    }
    // Do FZT:
    for(auto p: P) rep(i,1,maxn/p) f[i] -= f[i*p];
    rep(i,1,maxn) if(f[i]) printf("%d %lld\n",i,f[i]);
    return 0;
}