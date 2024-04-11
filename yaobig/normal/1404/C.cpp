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

const int maxn = 300'000;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

template<class T,const int maxn> struct Segtree
{
    #define ls i*2
    #define rs i*2+1
    array<T,maxn*4+5> a;
    void pu(int i) {a[i] = a[ls]+a[rs];}
    void add(int i,int l,int r,int ql,int qr,T x)
    {
        if(ql<=l && r<=qr)
        {
            a[i] += x;
            return;
        }
        if(qr<l || r<ql) return;
        int mid=(l+r)>>1;
        add(ls,l,mid,ql,qr,x);
        add(rs,mid+1,r,ql,qr,x);
        pu(i);
    }
    T ask(int i,int l,int r,int ql,int qr)
    {
        if(ql<=l && r<=qr) return a[i];
        if(qr<l || r<ql) return 0;
        int mid=(l+r)>>1;
        return ask(ls,l,mid,ql,qr) + ask(rs,mid+1,r,ql,qr);
    }
    int lb(int i,int l,int r,T x) // find the first position p such that sum of a[p...n] < x.
    {
        while(l<r)
        {
            int mid = (l+r)>>1;
            if(a[rs]<x) r = mid, x -= a[rs], i = ls;
            else l = mid+1, i = rs;
        }
        return a[i]<x ? r : r+1;
    }
    #undef ls
    #undef rs
};
Segtree<int,maxn> seg;

int a[maxn+5];

int main()
{   
    int n,q; scanf("%d%d",&n,&q);
    rep(i,1,n) scanf("%d",&a[i]);
    
    static vector<pii> qpool[maxn+5];
    rep(i,1,q)
    {
        int x,y; scanf("%d%d",&x,&y);
        int l = x+1, r = n-y;
        qpool[r].pb({l,i});
    }
    static int ans[maxn+5];
    rep(i,1,n) 
    {
        int slack = i-a[i];
        if(slack>=0)
        {
            int pos = seg.lb(1,1,n,slack) - 1;
            chmin(pos, i);
            if(pos>=1) seg.add(1,1,n,pos,pos,1);
        }
        for(auto [l,qid]: qpool[i]) ans[qid] = seg.ask(1,1,n,l,n);
    }
    rep(i,1,q) printf("%d\n",ans[i]);
    return 0;
}