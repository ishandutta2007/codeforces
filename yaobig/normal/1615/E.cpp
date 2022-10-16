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

const int maxn = 200000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

vi e[maxn+5];
int in[maxn+5],out[maxn+5],tot,idx[maxn+5],dep[maxn+5];

struct Segtree
{
    #define ls i*2
    #define rs i*2+1
    array<int,maxn*4+5> a,id,lz;
    void push(int i,int x)
    {
        a[i]+=x;
        lz[i]+=x;
    }
    void pu(int i) 
    {
        if(a[ls]>=a[rs]) a[i]=a[ls], id[i]=id[ls];
        else a[i]=a[rs], id[i]=id[rs];
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
    void build(int i,int l,int r)
    {
        lz[i]=0;
        if(l==r) 
        {
            id[i] = l;
            a[i] = dep[idx[l]];
        }
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid);
            build(rs,mid+1,r);
            pu(i);
        }
        //debug(i,l,r,a[i],id[i]);
    }
    void add(int i,int l,int r,int ql,int qr,const int &x)
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
    pii ask(int i,int l,int r,int ql,int qr)
    {
        if(ql<=l && r<=qr) return pii{a[i],id[i]};
        if(qr<l || r<ql) return pii{-inf,0};
        int mid=(l+r)>>1;
        pd(i);
        return max(ask(ls,l,mid,ql,qr),ask(rs,mid+1,r,ql,qr));
    }
    #undef ls
    #undef rs
}seg;

int par[maxn+5],vis[maxn+5];
void dfs(int now,int fa)
{
    par[now] = fa;
    in[now] = ++tot;
    idx[tot] = now;
    //debug(id[tot]);
    dep[now] = dep[fa]+1;
    for(auto v: e[now]) if(v!=fa) dfs(v,now);
    out[now] = tot;
}
int main()
{
    int n,k; scanf("%d%d",&n,&k);
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    dfs(1,0);
    seg.build(1,1,n);
    int red = 0, cov = 0;
    while(k)
    {
        auto [mx,pos] = seg.ask(1,1,n,1,n);
        //debug(mx,pos);
        if(mx<=0) break;
        red++; k--;
        cov += mx;
        int now = idx[pos];
        while(now!=0 && vis[now]==0)
        {
            seg.add(1,1,n,in[now],out[now],-1);
            vis[now] = 1;
            now = par[now];
        }
    }
    int blue = n-cov;
    int wh = n-red-blue;
    while(k)
    {
        if(1ll*wh*(red-blue)<=1ll*(wh-1)*(red+1-blue)) wh--,red++,k--;
        else break;
    }
    while(1)
    {
        if(1ll*wh*(red-blue)>=1ll*(wh+1)*(red-blue+1)) wh++,blue--;
        else break;
    }
    printf("%lld\n",1ll*wh*(red-blue));
    return 0;
}