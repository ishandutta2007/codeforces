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

const int maxn = 1000000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

struct node
{
    int a[2][2];
};
node operator +(const node &a,const node &b) 
{
    node res{};
    res.a[0][0] = a.a[0][0]+b.a[0][0];
    res.a[0][1] = max(a.a[0][1]+b.a[1][1],a.a[0][0]+b.a[0][1]);
    res.a[1][0] = max(a.a[1][0]+b.a[0][0],a.a[1][1]+b.a[1][0]);
    res.a[1][1] = a.a[1][1]+b.a[1][1];
    return res;
}
void inv(node &a)
{
    swap(a.a[0][0],a.a[1][1]);
    swap(a.a[0][1],a.a[1][0]);
}

// Range add & range query.
struct Segtree
{
    #define ls i*2
    #define rs i*2+1
    array<node,maxn*4+5> a;
    array<int,maxn*4+5> lz;
    void push(int i,int l,int r)
    {
        inv(a[i]);
        lz[i] ^= 1;
    }
    void pu(int i) {a[i] = a[ls]+a[rs];}
    void pd(int i,int l,int r)
    {
        if(lz[i])
        {
            int mid=(l+r)>>1;
            push(ls,l,mid);
            push(rs,mid+1,r);
            lz[i]=0;
        }
    }
    void build(int i,int l,int r,char *s)
    {
        lz[i]=0;
        if(l==r) a[i] = s[l]=='4' ? node{1,1,1,0} : node{0,1,1,1};
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid,s);
            build(rs,mid+1,r,s);
            pu(i);
        }
    }
    void upd(int i,int l,int r,int ql,int qr)
    {
        if(ql<=l && r<=qr)
        {
            push(i,l,r);
            return;
        }
        if(qr<l || r<ql) return;
        int mid=(l+r)>>1;
        pd(i,l,r);
        upd(ls,l,mid,ql,qr);
        upd(rs,mid+1,r,ql,qr);
        pu(i);
    }
    #undef ls
    #undef rs
}seg;


int main()
{
    int n,m; scanf("%d%d",&n,&m);
    static char s[maxn+5]; scanf("%s",s+1);
    seg.build(1,1,n,s);
    rep(i,1,m)
    {
        static char op[10]; scanf("%s",op);
        if(op[0]=='s')
        {
            int l,r; scanf("%d%d",&l,&r);
            seg.upd(1,1,n,l,r);
        }
        else printf("%d\n",seg.a[1].a[0][1]);
    }
    return 0;
}