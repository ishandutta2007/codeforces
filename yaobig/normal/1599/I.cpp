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

const int maxn = 750000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

struct LCT
{    
    #define ls(x) son[x][0]
    #define rs(x) son[x][1]
    int fa[maxn+5],son[maxn+5][2];
    int val[maxn+5],sum[maxn+5],lz[maxn+5];
    int isedge[maxn+5],sum_is[maxn+5];
    bool rev[maxn+5];
    void init(int n,int m)
    {
        rep(i,1,n) fa[i]=son[i][0]=son[i][1]=0;
        rep(i,1,n) rev[i]=0,lz[i]=-1;
        rep(i,1,n) val[i]=sum[i]=0;
        rep(i,1,n) isedge[i]=sum_is[i]=i>m;
    }
    void pushup(int x)
    {
        sum_is[x] = isedge[x] | sum_is[ls(x)] | sum_is[rs(x)];
        sum[x] = val[x] | sum[ls(x)] | sum[rs(x)];
    }
    void push_rev(int x)
    {
        if(!x) return;
        rev[x] ^= 1;
        swap(ls(x),rs(x));
    }
    void push_lz(int x,int y)
    {
        if(!x) return;
        lz[x] = y;
        if(isedge[x]) val[x] = y;
        if(sum_is[x]) sum[x] = y;
    }
    bool isrt(int x)
    {
        return ls(fa[x])!=x && rs(fa[x])!=x;
    }
    void pushdown(int x)
    {   // every time before we touch a child of a node, we need to pushdown.
        if(rev[x])
        {
            push_rev(ls(x));
            push_rev(rs(x));
            rev[x] = 0;
        } 
        if(lz[x]!=-1)
        {
            push_lz(ls(x),lz[x]);
            push_lz(rs(x),lz[x]);
            lz[x] = -1;
        }
    }
    void rot(int x)
    {
        int y=fa[x],z=fa[y];
        int l=rs(y)==x,r=l^1;
        if(!isrt(y)) son[z][rs(z)==y]=x;
        fa[son[x][r]]=y;
        fa[y]=x; fa[x]=z;
        son[y][l]=son[x][r]; son[x][r]=y;
        pushup(y);
    }
    stack<int> sta;
    void splay(int x)
    {
        sta.push(x);
        for(int i=x;!isrt(i);i=fa[i]) sta.push(fa[i]);
        while(sz(sta)) pushdown(sta.top()), sta.pop();
        while(!isrt(x))
        {
            int y=fa[x],z=fa[y];
            if(!isrt(y))
            {
                if((ls(y)==x) ^ (ls(z)==y)) rot(x);
                else rot(y);
            }
            rot(x);
        }
        pushup(x);
    }
    void access(int x)
    {   // Say y is the current root of the component (the rooted tree),
        // then we make the path y - ... - x a preferred path.
        // - Note: it's possible that neither x or y is the root of the splay after this 'access'.
        for(int l=0;x;l=x,x=fa[x])
        {
            splay(x); // move x to the root of the cuurent splay.
            rs(x)=l; // make l be the preferred child of x.
            pushup(x); // update info.
        }
    }
    int findrt(int x)
    {   // return the root of the component.
        access(x); splay(x);
        while(ls(x)) pushdown(x), x=ls(x);
        return x;
    }
    void reroot(int x)
    {   // Make x be the root in the component. 
        // x also becomes the root of the splay.
        access(x); splay(x); push_rev(x);
    }
    void link(int x,int y)
    {   // link x to y, i.e. make x be a (non-preferred) child of y.
        reroot(x); fa[x]=y;
    }
    void cut(int x,int y)
    {   // Say x - ... - u - y, then we cut (u,y) and return u.
        reroot(x); access(y); splay(y);
        int l=ls(y);
        ls(y)=fa[l]=0;
        pushup(y);
    }
    void demo(int n)
    {
        rep(i,1,n) debug(i, fa[i], ls(i), rs(i), val[i], isedge[i], sum[i], sum_is[i]);
    }
}lct;

pii ed[maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    lct.init(n+m,n);
    int j = 1;
    ll ans = 0;
    rep(i,1,m)
    {
        int u,v; scanf("%d%d",&u,&v); ed[i] = {u,v};
        //lct.demo(n+m);
        while(lct.findrt(u)==lct.findrt(v))
        {
            debug(i, lct.findrt(u), lct.findrt(v));
            lct.reroot(u); lct.access(v); lct.splay(v);
            debug(lct.sum[v]);
            if(lct.sum[v] == 0) break;
            auto [x,y] = ed[j];
            int e = j+n;
            lct.reroot(x); lct.access(y);
            lct.splay(e);
            int j2 = lct.val[e];
            lct.demo(n+m);
            if(j2) 
            {
                auto [a,b] = ed[j2];
                lct.reroot(a); lct.access(b); lct.splay(b);
                lct.push_lz(b,0);
            }
            lct.cut(e,x);
            lct.cut(e,y);
            if(j2)
            {
                int f = j2+n;
                lct.link(f,ed[j2].FI);
                lct.link(f,ed[j2].SE);
            }
            j++;
        }
        debug(i,j);
        if(lct.findrt(u)==lct.findrt(v))
        {
            lct.reroot(u); lct.access(v); lct.splay(v);
            lct.push_lz(v,i);
        }
        else
        {
            lct.link(i+n, u);
            lct.link(i+n, v);
        }
        ans += i-j+1;
    }
    printf("%lld\n",ans);
    return 0;
}