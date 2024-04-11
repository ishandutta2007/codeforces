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

template<class T,int LG> struct LB
{   // LG should not exceed the length of T in bits. Say LG can be at most 32 if you use T = u32.
    // last[i] = the last time the i-th basis shows appears in the sequence.
    T a[LG];
    int last[LG];
    T& operator [](const int &i) const {return (T&)a[i];}
    LB()
    {
        memset(a,0,sizeof a);
        memset(last,0,sizeof last);
    }
    void ins(T x,int ti=0)
    {
        per(i,0,LG-1) if(x>>i&1)
        {
            if(a[i]==0) {a[i]=x; last[i]=ti; return;}
            else if(ti>last[i]) swap(a[i],x), swap(last[i],ti);
            x^=a[i];
        }
    }
    T ask_min(T x,int ti=0)
    {   // ask the minimum value we can get if we add vectors from linear base (since time $ti$) to $x$.
        per(i,0,LG-1) if(last[i]>=ti) chmin(x,x^a[i]); // change to chmax to ask maximum value we can get.
        return x;
    }
};

template<class T> struct Undoable_Union_Set
{
    // Make sure the address where you store values will not change in the future.
    array<T,maxn+5> fa,sz,val;// val[x] = xor sum of edges' weights on path from x to fa[x]. 
    vector<pair<T*,T>> sta;
    void init(int n) 
    {
        rep(i,1,n) fa[i]=i,sz[i]=1;
        sta.clear();
    }
    pair<int,T> getfa(int x) 
    {
        T res = 0;
        while(x!=fa[x])
        {
            res ^= val[x];
            x = fa[x];
        }
        return {x,res};
    }
    void safechg(T &x,T y) { sta.pb({&x,x}); x = y; }
    T merge(int x,int y,T w)
    {
        auto [fx,valx] = getfa(x);
        auto [fy,valy] = getfa(y);
        if(fx==fy) return w^valx^valy; // return the weight of the new cycle.
        if(sz[fx]<sz[fy]) swap(fx,fy);
        safechg(fa[fy],fx);
        safechg(sz[fx],sz[fx]+sz[fy]);
        val[fy] = w^valx^valy;
        return 0;
    }
    void undo(int top)
    {
        while(sz(sta)>top) *sta.back().FI = sta.back().SE, sta.pop_back();
    }
};
Undoable_Union_Set<int> us;

using Base = LB<int,30>;
struct Edge {int x,y,w;};

pii q[maxn+5];

struct Segtree
{
    #define ls i*2
    #define rs i*2+1
    array<vector<Edge>,maxn*4+5> E;
    void add(int i,int l,int r,int ql,int qr,Edge e)
    {
        if(ql<=l && r<=qr)
        {
            E[i].pb(e);
            return;
        }
        if(qr<l || r<ql) return;
        int mid=(l+r)>>1;
        add(ls,l,mid,ql,qr,e);
        add(rs,mid+1,r,ql,qr,e);
    }
    void dfs(int i,int l,int r,Base b)
    {
        int top = sz(us.sta);
        for(auto [x,y,w]: E[i]) 
        {
            int res = us.merge(x,y,w);
            if(res) b.ins(res);
        }
        if(l==r)
        {
            auto [x,y] = q[l];
            if(x!=0)
            {
                auto [fx,valx] = us.getfa(x);
                auto [fy,valy] = us.getfa(y);
                assert(fx==fy);
                int ans = b.ask_min(valx^valy);
                printf("%d\n",ans);
            }
        }
        else
        {
            int mid=(l+r)>>1;
            dfs(ls,l,mid,b);
            dfs(rs,mid+1,r,b);
        }
        us.undo(top);
    }
    #undef ls
    #undef rs
}seg;

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    map<pii,pii> M;
    rep(i,1,m)
    {
        int x,y,w; scanf("%d%d%d",&x,&y,&w);
        M[{x,y}] = {w,1};
    }
    int Q; scanf("%d",&Q);
    rep(qid,1,Q)
    {
        int op,x,y; scanf("%d%d%d",&op,&x,&y);
        if(op==1)
        {
            int w; scanf("%d",&w);
            M[{x,y}] = {w,qid};
        }
        else if(op==2)
        {
            auto [w,old] = M[{x,y}];
            if(qid>old) seg.add(1,1,Q,old,qid-1,Edge{x,y,w});
            M.erase({x,y});
        }
        else q[qid] = {x,y};
    }
    for(auto [f,s]: M) seg.add(1,1,Q,s.SE,Q,Edge{f.FI,f.SE,s.FI});
    us.init(n);
    seg.dfs(1,1,Q,Base{});
    return 0;
}