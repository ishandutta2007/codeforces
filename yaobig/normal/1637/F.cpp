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

template<class T> struct Segtree
{
    #define ls i*2
    #define rs i*2+1
    array<T,maxn*4+5> a,lz;
    array<int,maxn*4+5> id;
    void push(int i,T x)
    {
        a[i]+=x;
        lz[i]+=x;
    }
    void pu(int i) 
    {
        a[i] = max(a[ls],a[rs]);
        if(a[i]==a[ls]) id[i] = id[ls]; // change here if you want the rightist index.
        else id[i] = id[rs];
    }
    void pd(int i)
    {
        if(lz[i])
        {
            push(ls,lz[i]);
            push(rs,lz[i]);
            lz[i]=0;
        }
    }
    void build(int i,int l,int r,T *vec)
    {
        lz[i]=0;
        if(l==r) 
        {
            a[i]=vec[l];
            id[i]=l;
        }
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid,vec);
            build(rs,mid+1,r,vec);
            pu(i);
        }
    }
    void add(int i,int l,int r,int ql,int qr,const T &x)
    {
        if(ql<=l && r<=qr)
        {
            push(i,x);
            return;
        }
        if(qr<l || r<ql) return;
        int mid=(l+r)>>1;
        pd(i);
        add(ls,l,mid,ql,qr,x);
        add(rs,mid+1,r,ql,qr,x);
        pu(i);
    }
    pair<T,int> ask(int i,int l,int r,int ql,int qr)
    {
        if(ql<=l && r<=qr) return pair<T,int>{a[i],id[i]};
        if(qr<l || r<ql) return pair<T,int>{-inf,-1};
        int mid=(l+r)>>1;
        pd(i);
        auto resl = ask(ls,l,mid,ql,qr);
        auto resr = ask(rs,mid+1,r,ql,qr);
        if(resl.FI>=resr.FI) return resl; // change here if you want the rightist index.
        else return resr;
    }
    #undef ls
    #undef rs
};

vi e[maxn+5];
int par[maxn+5],id[maxn+5];

int in[maxn+5],out[maxn+5],cnt;
void dfs(int now,int fa)
{
    par[now] = fa;
    in[now] = ++cnt; id[cnt] = now;
    for(auto v: e[now]) if(v!=fa) dfs(v,now);
    out[now] = cnt;
}

Segtree<int> seg;
int a[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    int rt = max_element(a+1,a+n+1) - a;
    dfs(rt,0);
    static int A[maxn+5];
    rep(i,1,n) A[in[i]] = a[i];
//rep(i,1,n) debug(i,A[i]);
    seg.build(1,1,n,A);
    ll ans = 0;
    vector<pii> vec;
    for(auto v: e[rt]) vec.pb(seg.ask(1,1,n,in[v],out[v]));
    sort(all(vec),greater<pii>());
    static int mark[maxn+5];
    auto solve = [&](int now) {
        int res = seg.ask(1,1,n,in[now],out[now]).FI;
        while(1)
        {
            //debug(now);
            auto [val,it] = seg.ask(1,1,n,in[now],out[now]);
            if(val<0) break;
            int v = id[it], tmp = v;
            while(mark[tmp]==0)
            {
                seg.add(1,1,n,in[tmp],in[tmp],-inf);
                mark[tmp] = 1;
                tmp = par[tmp];
            }
            now = v;
        }
        return res;
    };
    ans += a[rt]*2;
//debug(vec);
    solve(id[vec[0].SE]);
    if(sz(vec)>1) solve(id[vec[1].SE]);
    while(seg.ask(1,1,n,1,n).FI>0)
    {
        ans += solve(rt);
    }
    printf("%lld\n",ans);
    return 0;
}