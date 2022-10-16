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

const int maxn = 100000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int a[maxn+5];
vi b[maxn+5];

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
        if(a[i]==a[ls]) id[i] = id[ls];
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
        if(qr<l || r<ql) return pair<T,int>{inf,-1};
        int mid=(l+r)>>1;
        pd(i);
        auto resl = ask(ls,l,mid,ql,qr);
        auto resr = ask(rs,mid+1,r,ql,qr);
        if(resl.FI<=resr.FI) return resl;
        else return resr;
    }
    #undef ls
    #undef rs
};
Segtree<int> seg;

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n,m; scanf("%d%d",&n,&m);
        rep(i,1,m) b[i].clear();
        rep(i,1,n) scanf("%d",&a[i]);
        rep(i,1,m)
        {
            int k; scanf("%d",&k);
            while(k--)
            {
                int x; scanf("%d",&x); b[i].pb(x);
            }
        }
        static int tmp[maxn+5];
        rep(i,1,n+1) tmp[i] = n-i+1;
        int N = n+1;
        seg.build(1,1,N,tmp);
        sort(a+1,a+n+1);
        auto getid = [&](ll s,int k) {
            int l = 1, r = n+1;
            while(l<r)
            {
                int mid = (l+r)>>1;
                if(1ll*a[mid]*k>=s) r = mid;
                else l = mid+1;
            }
            return l;
        };
        vi ans;
        vi id(m+1);
        rep(i,1,m)
        {
            ll sum = 0;
            for(auto x: b[i]) sum+=x;
            id[i] = getid(sum,sz(b[i]));
            seg.add(1,1,N,1,id[i],-1);
        }
        rep(i,1,m)
        {
            seg.add(1,1,N,1,id[i],1);
            ll sum = 0;
            for(auto x: b[i]) sum+=x;
            for(auto x: b[i])
            {
                int id = getid(sum-x,sz(b[i])-1);
                seg.add(1,1,N,1,id,-1);
                int res = seg.ask(1,1,N,1,N).FI>=0;
                ans.pb(res);
                seg.add(1,1,N,1,id,1);
            }
            seg.add(1,1,N,1,id[i],-1);
        }
        for(auto x: ans) printf("%d",x);
        puts("");
    }
    return 0;
}