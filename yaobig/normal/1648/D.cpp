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

const int maxn = 500'000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

struct node { ll dp,suf,ans; };
node operator +(const node&a,const node&b) 
{
    ll nans = max(a.ans,b.ans); chmax(nans, a.dp+b.suf);
    return node{max(a.dp,b.dp), max(a.suf,b.suf), nans};
}
const node zero{-1ll<<60,-1ll<<60,-1ll<<60};

struct Segtree
{
    #define ls i*2
    #define rs i*2+1
    array<node,maxn*4+5> a;
    void pu(int i) {a[i] = a[ls]+a[rs];}
    void build(int i,int l,int r,node vec[])
    {
        if(l==r) a[i] = vec[l];
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid,vec);
            build(rs,mid+1,r,vec);
            pu(i);
        }
    }
    void upd(int i,int l,int r,int ql,int qr,ll x)
    {
        if(ql<=l && r<=qr)
        {
            chmax(a[i].dp, x);
            a[i].ans = a[i].dp + a[i].suf;
            return;
        }
        if(qr<l || r<ql) return;
        int mid=(l+r)>>1;
        upd(ls,l,mid,ql,qr,x);
        upd(rs,mid+1,r,ql,qr,x);
        pu(i);
    }
    node ask(int i,int l,int r,int ql,int qr)
    {
        if(ql<=l && r<=qr) return a[i];
        if(qr<l || r<ql) return zero;
        int mid=(l+r)>>1;
        return ask(ls,l,mid,ql,qr) + ask(rs,mid+1,r,ql,qr);
    }
    #undef ls
    #undef rs
}seg;

int main()
{
    int n,q; scanf("%d%d",&n,&q);
    static ll a[3][maxn+5];
    rep(r,0,2) rep(i,1,n) scanf("%lld",&a[r][i]), a[r][i] += a[r][i-1];
    static node vec[maxn+5];
    rep(i,1,n) 
    {
        vec[i].dp = a[0][i]-a[1][i-1];
        vec[i].suf = a[2][n]-a[2][i-1]+a[1][i];
        vec[i].ans = vec[i].dp+vec[i].suf;
    }
    seg.build(1,1,n,vec);
    static vector<pii> qpool[maxn+5];
    while(q--)
    {
        int l,r,k; scanf("%d%d%d",&l,&r,&k);
        qpool[r].pb({l,k});
    }
    ll ans = -1ll<<60;
    rep(r,1,n) for(auto [l,k]: qpool[r])
    {
        node tmp = seg.ask(1,1,n,l,r);
        chmax(ans, tmp.ans-k);
        if(r<n) seg.upd(1,1,n,r+1,r+1,tmp.dp-k);
    }
    printf("%lld\n",ans);
    return 0;
}