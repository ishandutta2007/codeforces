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

const int maxn = 1000000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

struct Segtree
{
    #define ls i*2
    #define rs i*2+1
    array<int,maxn*4+5> a,lz;
    void pu(int i,int l,int r) 
    {
        if(lz[i]) a[i]=r-l+1;
        else a[i]=(l==r?0:a[ls]+a[rs]);
    }
    void add(int i,int l,int r,int ql,int qr,const int &x)
    {
        if(ql<=l && r<=qr)
        {
            lz[i]+=x;
            pu(i,l,r);
            return;
        }
        if(qr<l || r<ql) return;
        int mid=(l+r)>>1;
        add(ls,l,mid,ql,qr,x);
        add(rs,mid+1,r,ql,qr,x);
        pu(i,l,r);
    }
    #undef ls
    #undef rs
}seg;

ll a[maxn+5],ap[maxn+5];

struct node {int t,l,r,x;};

vector<node> pool[70];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%lld",&a[i]);
    ll ans = 0;
    auto work = [&](){
        vi nxt(n+1),pre(n+1);
        stack<int> sta;
        sta.push(0);
        rep(i,1,n) 
        {
            while(ap[sta.top()]<ap[i] || (ap[sta.top()]==ap[i] && sta.top()<i)) sta.pop();
            pre[i] = sta.top() + 1;
            sta.push(i);
        }
        sta = stack<int>{};
        sta.push(n+1);
        per(i,1,n) 
        {
            while(ap[sta.top()]<ap[i] || (ap[sta.top()]==ap[i] && sta.top()<i)) sta.pop();
            nxt[i] = sta.top() - 1;
            sta.push(i);
        }
        rep(i,1,n)
        {
            int C = __builtin_popcountll(a[i]);
            pool[C].pb(node{pre[i],i,nxt[i],1});
            pool[C].pb(node{i+1,i,nxt[i],-1});
            ans += 1ll*(i+1-pre[i])*(nxt[i]-i+1);
        }
    };
    ap[0] = ap[n+1] = 1ll<<60;
    rep(i,1,n) ap[i] = a[i];
    work();
    rep(i,1,n) ap[i] = -a[i];
    work();
    rep(i,0,60) if(sz(pool[i])) sort(all(pool[i]),[](const node &A,const node &B){return A.t<B.t;});
    rep(c,0,60)
    {
        int last_time = 0;
        for(auto [t,l,r,x]: pool[c])
        {
            ans -= 1ll*seg.a[1]*(t-last_time);
            seg.add(1,1,n,l,r,x);
            last_time = t;
        }
    }
    printf("%lld\n",ans);
    return 0;
}