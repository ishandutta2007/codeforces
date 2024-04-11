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

const int maxn = 300000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

struct Segtree
{
    #define ls i*2
    #define rs i*2+1
    array<pii,maxn*4+5> a;
    pii best(const pii &a,const pii &b)
    {
        return {min(a.FI,b.FI),max(a.SE,b.SE)};
    }
    void pu(int i) {a[i]=best(a[ls],a[rs]);}
    void build(int i,int l,int r,vector<pii> &A)
    {
        if(l==r) a[i] = A[l];
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid,A);
            build(rs,mid+1,r,A);
            pu(i);
        }
    }
    pii ask(int i,int l,int r,int ql,int qr)
    {
        if(ql<=l && r<=qr) return a[i];
        if(qr<l || r<ql) return {inf,-inf};
        int mid=(l+r)>>1;
        return best(ask(ls,l,mid,ql,qr),ask(rs,mid+1,r,ql,qr));
    }
    #undef ls
    #undef rs
}seg[17];

int r[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&r[i]);
    if(n==1) return puts("0"),0;
    int N = n*3;
    vector<pii> A(N+1);
    rep(i,1,N) 
    {
        int x = r[(i-1)%n+1];
        A[i] = {max(1,i-x),min(i+x,N)};
    }
    rep(rd,0,16)
    {
        seg[rd].build(1,1,N,A);
        rep(i,1,N) A[i] = seg[rd].ask(1,1,N,A[i].FI,A[i].SE);
    }
    rep(i,n+1,n*2)
    {
        int l = i, r = i, ans = 1;
        per(rd,0,16)
        {
            auto [L,R] = seg[rd].ask(1,1,N,l,r);
            if(R-L+1<n) 
            {
                ans += 1<<rd;
                l = L, r = R;
            }
        }
        printf("%d%c",ans," \n"[i==n*2]);
    }
    return 0;
}