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

const int maxn = 1'000'000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

// Range Add & Range Minimum (with the leftist index).
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
        a[i] = min(a[ls],a[rs]);
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
    void build(int i,int l,int r,vector<T> &vec)
    {
        lz[i]=0;
        if(l==r) 
        {
            a[i] = -vec[l-1];
            id[i] = l;
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
        if(qr<l || r<ql) return pair<T,int>{1ll<<60,-1};
        int mid=(l+r)>>1;
        pd(i);
        auto resl = ask(ls,l,mid,ql,qr);
        auto resr = ask(rs,mid+1,r,ql,qr);
        if(resl.FI<=resr.FI) return resl; // change here if you want the rightist index.
        else return resr;
    }
    #undef ls
    #undef rs
};
Segtree<ll> seg;

int x[maxn+5],y[maxn+5],c[maxn+5];
vi pool[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d%d%d",&x[i],&y[i],&c[i]);
    vector<ll> vec;
    rep(i,1,n) vec.pb(x[i]), vec.pb(y[i]);
    sort(all(vec)); vec.erase(unique(all(vec)),vec.end());
    auto getid = [&](ll pos) {return lower_bound(all(vec),pos) - vec.begin() + 1;};
    rep(i,1,n)
    {
        x[i] = getid(x[i]);
        y[i] = getid(y[i]);
        pool[max(x[i],y[i])].pb(i);
    }
    ll ans = 0; pii best = {inf,inf};
    int N = sz(vec);
    seg.build(1,1,N,vec);
    ll sum = 0;
    rep(i,1,N)
    {
        for(auto id: pool[i])
        {
            sum += c[id];
            int pos = min(x[id],y[id]);
            seg.add(1,1,N,pos+1,N,c[id]);
        }
        auto [mn,pos] = seg.ask(1,1,N,1,i);
        if(chmax(ans,sum-vec[i-1]-mn)) best = {vec[pos-1],vec[i-1]};
    }
    printf("%lld\n",ans);
    printf("%d %d %d %d\n",best.FI,best.FI,best.SE,best.SE);
    return 0;
}