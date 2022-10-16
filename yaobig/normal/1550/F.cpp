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
template <typename A> string to_string(A v) 
{
    bool first = 1;
    string res = "{";
    for(const auto &x : v) 
    {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}
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

const int maxn = 200000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

struct Union_Set
{
    array<int,maxn+5> fa,sz;
    void init(int n) 
    {
        rep(i,1,n) fa[i]=i,sz[i]=1;
    }
    int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
	bool check(int x,int y) {return getfa(x)==getfa(y);}
    void merge(int x,int y)
    {
        int fx=getfa(x),fy=getfa(y);
        if(sz[fx]<sz[fy]) swap(fx,fy);
        fa[fy]=fx;
        sz[fx]+=sz[fy];
    }
}us;

int a[maxn+5];

const int MAXA = 1000000;
vector<pii> pool[MAXA+5],q[MAXA+5];
int ans[maxn+5];

int r[maxn+5];

int main()
{
    int n,Q,s,d; scanf("%d%d%d%d",&n,&Q,&s,&d);
    rep(i,1,n) scanf("%d",&a[i]);

    int ptr = 1;
    rep(i,1,n) 
    {
        while(ptr<=n && a[ptr]<a[i]+d) ptr++;
        r[i] = ptr;
    }
    r[n+1] = n+1;
    rep(i,1,n)
    {
        int L = i>1? max(r[i-1]-1,i+1) : 1;
        int R = min(r[i+1],n);
        rep(j,L,R) pool[abs(a[j]-a[i]-d)].pb({i,j});
    }
    rep(i,1,Q)
    {
        int dst,k; scanf("%d%d",&dst,&k);
        q[k].pb({dst,i});
    }
    us.init(n);
    rep(k,0,MAXA)
    {
        for(auto [u,v]: pool[k]) if(us.check(u,v)==0) us.merge(u,v);
        for(auto [dst,qid]: q[k]) ans[qid] = us.check(s,dst);
    }
    rep(i,1,Q) puts(ans[i]?"Yes":"No");
    return 0;
}