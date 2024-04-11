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
//using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 200000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

struct Segtree
{
    #define ls i*2
    #define rs i*2+1
    array<int,maxn*4+5> a,len,lz1,lz2;
    void push(int i,int x,int y)
    {
        a[i] = (1ll*a[i]*x+1ll*y*len[i])%mod;
        lz1[i] = 1ll*lz1[i]*x%mod;
        lz2[i] = (1ll*lz2[i]*x+y)%mod;
    }
    void pu(int i) {a[i] = (a[ls]+a[rs])%mod;}
    void pd(int i)
    {
        push(ls,lz1[i],lz2[i]);
        push(rs,lz1[i],lz2[i]);
        lz1[i]=1; lz2[i] = 0;
    }
    void build(int i,int l,int r,vi &vec)
    {
        lz1[i]=1; lz2[i] = 0;
        if(l==r) a[i] = 0, len[i] = (vec[l]-vec[l-1])%mod;
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid,vec);
            build(rs,mid+1,r,vec);
            pu(i);
            len[i] = (len[ls] + len[rs])%mod;
        }
    }
    void add(int i,int l,int r,int ql,int qr,const int &x,const int &y)
    {
        if(ql<=l && r<=qr)
        {
            push(i,x,y);
            return;
        }
        if(qr<l || r<ql) return;
        int mid=(l+r)>>1;
        pd(i);
        add(ls,l,mid,ql,qr,x,y);
        add(rs,mid+1,r,ql,qr,x,y);
        pu(i);
    }
    #undef ls
    #undef rs
}seg;

int a[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    vi vec; vec.pb(0);
    rep(i,1,n) vec.pb(a[i]);
    sort(all(vec)); vec.erase(unique(all(vec)),vec.end());
    int N = sz(vec)-1;
    seg.build(1,1,N,vec);
    int sum = 1;
    rep(i,1,n)
    {
        int id = lower_bound(all(vec),a[i])-vec.begin();
        seg.add(1,1,N,1,id,mod-1,sum);
        if(id<N) seg.add(1,1,N,id+1,N,0,0);
        sum = seg.a[1];
    }
    printf("%d\n",sum);
    return 0;
}