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

const int MAXK = 300000;

struct node
{
    int l,r,id;
}seg[MAXK+5];

struct Persistent_segtree
{
    #define MAXN (MAXK*(__lg(maxn)+2))
    int tot;
    array<int,MAXN+5> ls,rs,a;
    void init()
    {
        tot = 0;
        a[0] = inf;
    }
    int clone(int now)
    {
        ++tot;
        ls[tot] = ls[now];
        rs[tot] = rs[now];
        a[tot] = a[now];
        return tot;
    }
    void pu(int now) { a[now] = max(a[ls[now]],a[rs[now]]); }
    void upd(int &now,int l,int r,int p,int x)
    {
        now = clone(now);
        if(l==r) 
        {
            chmin(a[now],x);
            return;
        }
        int mid=(l+r)>>1;
        if(p<=mid) upd(ls[now],l,mid,p,x);
        else upd(rs[now],mid+1,r,p,x);
        pu(now);
    }
    int ask(int now,int l,int r,int ql,int qr)
    {
        if(ql<=l && r<=qr) return a[now];
        if(qr<l || r<ql) return 0;
        int mid = (l+r)>>1;
        return max(ask(ls[now],l,mid,ql,qr),ask(rs[now],mid+1,r,ql,qr));
    }
    #undef MAXN
}pseg;

int main()
{
    int n,m,k; scanf("%d%d%d",&n,&m,&k);
    rep(i,1,k) 
    {
        int l,r,id; scanf("%d%d%d",&l,&r,&id); seg[i] = node{l,r,id};
    }
    auto cmp = [&](const node &a,const node &b) {return a.l>b.l;};
    sort(seg+1,seg+k+1,cmp);

    pseg.init();
    static int rt[MAXK+5];
    rep(i,1,k) rt[i] = rt[i-1], pseg.upd(rt[i],1,n,seg[i].id,seg[i].r);

    while(m--)
    {
        int a,b,x,y; scanf("%d%d%d%d",&a,&b,&x,&y);
        int pos = lower_bound(seg+1,seg+k+1,node{x-1,0,0},cmp) - seg - 1;
        int mx = pseg.ask(rt[pos],1,n,a,b);
        puts(mx<=y?"yes":"no");
        fflush(stdout);
    }
    return 0;
}