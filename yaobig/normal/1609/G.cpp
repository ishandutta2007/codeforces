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
template <typename A, typename B> string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}
template <typename A> string to_string(A v) 
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
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 100000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

template<class T> struct BIT
{
    int n;
    T a[maxn+5];
    void init(int _n)
    {
        n=_n;
        rep(i,1,n) a[i]=0;
    }
    void add(int i,T x) {for(;i<=n;i+=i&-i) a[i]+=x;}
    T ask(int i)
    {
        T ans=0;
        for(;i;i-=i&-i) ans+=a[i];
        return ans;
    }
    int find(T x) // find the first pos such that ask(pos) >= x.
    {
        int pos=0;
        per(i,0,__lg(n))
        {
            if((pos | (1<<i)) <= n && a[pos | (1<<i)] < x) 
            {
                pos |= 1<<i;
                x -= a[pos];
            }
        }
        return pos+1;
    }
};
BIT<ll> bit;
// Range add & range query.
template<class T> struct Segtree
{
    #define ls i*2
    #define rs i*2+1
    array<T,maxn*4+5> a,lz;
    void push(int i,int l,int r,T x)
    {
        a[i]+=x*(r-l+1);
        lz[i]+=x;
    }
    void pu(int i) {a[i]=a[ls]+a[rs];}
    void pd(int i,int l,int r)
    {
        if(lz[i])
        {
            int mid=(l+r)>>1;
            push(ls,l,mid,lz[i]);
            push(rs,mid+1,r,lz[i]);
            lz[i]=0;
        }
    }
    void build(int i,int l,int r,T *b)
    {
        lz[i]=0;
        if(l==r) a[i]=b[l];
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid,b);
            build(rs,mid+1,r,b);
            pu(i);
        }
    }
    void add(int i,int l,int r,int ql,int qr,const T &x)
    {
        if(ql<=l && r<=qr)
        {
            push(i,l,r,x);
            return;
        }
        if(qr<l || r<ql) return;
        int mid=(l+r)>>1;
        pd(i,l,r);
        add(ls,l,mid,ql,qr,x);
        add(rs,mid+1,r,ql,qr,x);
        pu(i);
    }
    T ask(int i,int l,int r,int ql,int qr)
    {
        if(ql<=l && r<=qr) return a[i];
        if(qr<l || r<ql) return 0;
        int mid=(l+r)>>1;
        pd(i,l,r);
        return ask(ls,l,mid,ql,qr)+ask(rs,mid+1,r,ql,qr);
    }
    #undef ls
    #undef rs
};
Segtree<ll> segt;

ll a[maxn+5],b[maxn+5];

int main()
{
    int n,m,q; scanf("%d%d%d",&n,&m,&q);
    rep(i,1,n) scanf("%lld",&a[i]);
    rep(i,1,m) scanf("%lld",&b[i]);
    per(i,2,n) a[i] -= a[i-1];
    per(i,2,m) b[i] -= b[i-1];
    ll sum = 0;
    rep(i,2,m) sum += b[i] * (m-i+1);
    bit.init(m);
    bit.add(1, b[1]);
    rep(i,2,m) bit.add(i, b[i]-b[i-1]);
    segt.build(1,1,m,b);
    while(q--)
    {
        int op,k,d; scanf("%d%d%d",&op,&k,&d);
        if(op==1)
        {
            rep(i,n-k+1,n) a[i] += d;
        }
        else
        {
            int pos = m-k+1;
            bit.add(pos,d);
            segt.add(1,1,m,pos,m,d);
            if(k==m) k--;
            sum += 1ll*(k+1)*k/2*d;
        }
        ll ans = sum + (a[1]+bit.ask(1))*(n+m-1);
        per(i,2,n)
        {
            int pos = bit.find(a[i]);
            if(pos==1) pos = 2;
            if(pos>2) ans += segt.ask(1,1,m,2,pos-1);
            ans += a[i]*(m-pos+1+1+n-i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}