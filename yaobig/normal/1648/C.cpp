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

const int maxn = 200'000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

inline void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}

// Range add & range query.
template<class T,const int maxn> struct Segtree
{
    #define ls i*2
    #define rs i*2+1
    array<T,maxn*4+5> a,lz;
    void push(int i,T x)
    {
        a[i] = 1ll*a[i]*x%mod;
        lz[i] = 1ll*lz[i]*x%mod;
    }
    void pu(int i) {a[i]=(a[ls]+a[rs])%mod;}
    void pd(int i,int l,int r)
    {
        if(lz[i])
        {
            push(ls,lz[i]);
            push(rs,lz[i]);
            lz[i]=1;
        }
    }
    void build(int i,int l,int r,T vec[])
    {
        lz[i] = 1;
        if(l==r) a[i] = vec[l];
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid,vec);
            build(rs,mid+1,r,vec);
            pu(i);
        }
    }
    void upd(int i,int l,int r,int ql,int qr,T x)
    {
        if(ql<=l && r<=qr)
        {
            a[i] = x;
            return;
        }
        if(qr<l || r<ql) return;
        int mid=(l+r)>>1;
        pd(i,l,r);
        upd(ls,l,mid,ql,qr,x);
        upd(rs,mid+1,r,ql,qr,x);
        pu(i);
    }
    void mul(int i,int l,int r,int ql,int qr,T x)
    {
        if(ql<=l && r<=qr)
        {
            push(i,x);
            return;
        }
        if(qr<l || r<ql) return;
        int mid=(l+r)>>1;
        pd(i,l,r);
        mul(ls,l,mid,ql,qr,x);
        mul(rs,mid+1,r,ql,qr,x);
        pu(i);
    }
    T ask(int i,int l,int r,int ql,int qr)
    {
        if(ql<=l && r<=qr) return a[i];
        if(qr<l || r<ql) return 0;
        int mid=(l+r)>>1;
        pd(i,l,r);
        return (ask(ls,l,mid,ql,qr)+ask(rs,mid+1,r,ql,qr))%mod;
    }
    #undef ls
    #undef rs
};
// Example: type int, range [1,maxn].
Segtree<int,maxn> seg;

int fac[maxn+5],ifac[maxn+5],inv[maxn+5];

int a[maxn+5],b[maxn+5],cnt[maxn+5];

int main()
{
    inv[1] = fac[0] = ifac[0] = 1;
    rep(i,2,maxn) inv[i] = 1ll*inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,maxn) fac[i] = 1ll*fac[i-1]*i%mod;
    rep(i,1,maxn) ifac[i] = 1ll*ifac[i-1]*inv[i]%mod;

    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&a[i]), cnt[a[i]]++;
    rep(i,1,m) scanf("%d",&b[i]);
    int tot = fac[n];
    rep(i,1,maxn) tot = 1ll*tot*ifac[cnt[i]]%mod;
    static int vec[maxn+5];
    rep(i,1,maxn) if(cnt[i])
    {
        int tmp = tot;
        tmp = 1ll*tmp*inv[n]%mod*cnt[i]%mod;
        vec[i] = tmp;
    }
    seg.build(1,1,maxn,vec);
    int ans = 0;
    rep(i,1,m)
    {
        if(i>n) {chadd(ans, 1); break;}
        int x = b[i];
        if(x>1) chadd(ans, seg.ask(1,1,maxn,1,x-1));
        if(cnt[x]==0) break;
        int tmp = seg.ask(1,1,maxn,x,x);
        int N = n-i;
        seg.mul(1,1,maxn,1,maxn,1ll*inv[N]*cnt[x]%mod);
        cnt[x]--;
        tmp = cnt[x]==0 ? 0: 1ll*tmp*inv[N]%mod*cnt[x]%mod;
        seg.upd(1,1,maxn,x,x,tmp);
    }
    printf("%d\n",ans);
    return 0;
}