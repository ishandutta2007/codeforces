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

struct node {int a11,a22,a33,a12,a23,a13;};
node operator +(const node &X,const node &Y)
{
    node Z{};
    Z.a11 = X.a11 + Y.a11;
    Z.a22 = X.a22 + Y.a22;
    Z.a33 = X.a33 + Y.a33;
    Z.a12 = min(X.a11+Y.a12, X.a12+Y.a22);
    Z.a23 = min(X.a22+Y.a23, X.a23+Y.a33);
    Z.a13 = min(X.a11+Y.a13, X.a12+Y.a23);
    chmin(Z.a13, X.a13+Y.a33);
    return Z;
}
node newnode(char c)
{
    node res{};
    if(c=='a') res.a11 = 1;
    if(c=='b') res.a22 = 1;
    if(c=='c') res.a33 = 1;
    return res;
}

char s[maxn+5];
struct Segtree
{
    #define ls i*2
    #define rs i*2+1
    array<node,maxn*4+5> a;
    void pu(int i) {a[i]=a[ls]+a[rs];}
    void build(int i,int l,int r)
    {
        if(l==r) a[i]=newnode(s[l]);
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid);
            build(rs,mid+1,r);
            pu(i);
        }
    }
    void upd(int i,int l,int r,int ql,int qr)
    {
        if(ql<=l && r<=qr)
        {
            a[i] = newnode(s[ql]);
            return;
        }
        if(qr<l || r<ql) return;
        int mid=(l+r)>>1;
        upd(ls,l,mid,ql,qr);
        upd(rs,mid+1,r,ql,qr);
        pu(i);
    }
    #undef ls
    #undef rs
}segt;


int main()
{
    int n,q; scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    segt.build(1,1,n);
    while(q--)
    {
        int x; char t[5]; scanf("%d%s",&x,t);
        s[x] = t[0];
        segt.upd(1,1,n,x,x);
        int ans = segt.a[1].a13;
        printf("%d\n",ans);
    }
    return 0;
}