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
string to_string(bool b) {return (b ? "true" : "false");}
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

const int maxn = 200'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

struct node {int u,v,w;};
set<int> ban[maxn+5];

template<const int maxn> struct Union_Set
{
    array<int,maxn+5> fa,sz;
    void init(int n) 
    {
        rep(i,1,n) fa[i]=i,sz[i]=1;
    }
    int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
	bool check(int x,int y) {return getfa(x)!=getfa(y);}
    bool merge(int x,int y)
    {
        int fx=getfa(x),fy=getfa(y);
        if(fx==fy) return 0;
        if(sz[fx]<sz[fy]) swap(fx,fy);
        fa[fy]=fx;
        sz[fx]+=sz[fy];
        return 1;
    }
};

Union_Set<maxn+5> us;

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    int xorsum = 0;
    vector<node> e(m);
    for(auto &[x,y,w]: e) 
    {
        scanf("%d%d%d",&x,&y,&w), xorsum ^= w;
        ban[x].insert(y);
        ban[y].insert(x);
    }
    us.init(n);
    set<int> grd; rep(i,1,n) grd.insert(i);
    int used = 0;
    while(sz(grd))
    {
        int st = *grd.begin(); grd.erase(grd.begin());
        queue<int> q; q.push(st);
        while(sz(q))
        {
            int now = q.front(); q.pop();
            for(auto it = grd.begin();it!=grd.end();)
            {
                if(ban[now].count(*it)==0)
                {
                    used++;
                    q.push(*it); us.merge(now,*it); grd.erase(it++);
                }
                else it++;
            }
        }
    }
    ll ans = 0;
    sort(all(e),[&](const node &a,const node &b){return a.w<b.w;});
    vector<bool> mark(m);
    rep(i,0,m-1)
    {
        auto [u,v,w] = e[i];
        if(us.merge(u,v)) mark[i] = 1, ans += w;
    }
    if(used == 1ll*n*(n-1)/2 - m) 
    {
        ans += xorsum;
        us.init(n);
        rep(i,0,m-1) if(mark[i]) us.merge(e[i].u,e[i].v);
        rep(i,0,m-1) if(mark[i]==0 && us.check(e[i].u,e[i].v)) 
        {
            if(e[i].w<xorsum) ans -= xorsum - e[i].w;
            break;
        }
    }
    printf("%lld\n",ans);
    return 0;
}