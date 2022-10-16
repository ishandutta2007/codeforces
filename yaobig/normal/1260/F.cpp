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

const int maxn = 100'000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

inline void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}
inline void chsub(int &x,int y) {x-=y; if(x<0) x+=mod;}

vi e[maxn+5];

struct Centroid_Decomposition
{
    array<int,maxn+5> sz;
    array<bool,maxn+5> vis;
    vi anc[maxn+5]; // ancestors in centroid tree, including itself.
    vi cdis[maxn+5]; // distances to ancestors in centroid tree, not necessarily monotone.
    void solve(int _,int SZ)
    {
        int mn = inf, rt = -1;
        function<void(int,int)> getrt = [&](int now,int fa) {
            sz[now]=1;
            int mx = 0;
            for(auto v: e[now]) if(v!=fa && vis[v]==0)
            {
                getrt(v,now);
                sz[now]+=sz[v];
                chmax(mx,sz[v]);
            }
            chmax(mx,SZ-sz[now]);
            if(chmin(mn,mx)) rt=now;
        };
        getrt(_,0); vis[rt]=1; 

        function<void(int,int,int)> dfs = [&](int now,int fa,int dep) {
            anc[now].pb(rt); cdis[now].pb(dep);
            for(auto v: e[now]) if(v!=fa && vis[v]==0) dfs(v,now,dep+1);
        };
        dfs(rt,0,0);
        // start your work here.

        for(auto v: e[rt]) if(vis[v]==0) solve(v, sz[v]<sz[rt] ? sz[v] : SZ-sz[rt]);
    }
    array<int,maxn+5> cnt,sum,sump;
    int ans;
    void build(int n)
    {
        rep(i,1,n) vis[i]=0;
        rep(i,1,n) anc[i].clear();
        rep(i,1,n) cdis[i].clear();
        solve(1,n);
        ans = 0;
        rep(i,1,n) cnt[i] = sum[i] = 0;
    }

    int get(int now)
    {
        int last = 0, res = 0;
        per(i,0,sz(anc[now])-1)
        {
            int v = anc[now][i];
            int c = cnt[v]; chsub(c, last ? cnt[last] : 0);
            chadd(res, sum[v]);
            chsub(res, last ? sump[last] : 0);
            chadd(res, 1ll*c*cdis[now][i]%mod);

            last = v;
        }
        return res;
    }
    void add(int now,int val)
    {
        chadd(ans, 1ll*get(now)*val%mod);
        int i = 0;
        for(auto v: anc[now])
        {
            chadd(cnt[v], val);
            chadd(sum[v], 1ll*cdis[now][i]*val%mod);
            if(i) chadd(sump[v], 1ll*cdis[now][i-1]*val%mod);
            i++;
        }
    }
    void sub(int now,int val)
    {
        int i = 0;
        for(auto v: anc[now])
        {
            chsub(cnt[v], val);
            chsub(sum[v], 1ll*cdis[now][i]*val%mod);
            if(i) chsub(sump[v], 1ll*cdis[now][i-1]*val%mod);
            i++;
        }
        chsub(ans, 1ll*get(now)*val%mod);
    }
}cd;

vector<pii> pool[maxn+5];

int inv[maxn+5];

int main()
{
    inv[1] = 1;
    rep(i,2,maxn) inv[i] = 1ll*inv[mod%i]*(mod-mod/i)%mod;

    int n; scanf("%d",&n);
    int fac = 1;
    rep(i,1,n) 
    {
        int l,r; scanf("%d%d",&l,&r);
        pool[l].pb({i, inv[r-l+1]});
        pool[r+1].pb({i, -inv[r-l+1]});
        fac = 1ll*fac*(r-l+1)%mod;
    }
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    cd.build(n);
    int ans = 0;
    rep(pos,1,maxn)
    {
        for(auto [it,val]: pool[pos]) val>0 ? cd.add(it,val) : cd.sub(it,-val);
        //debug(pos, 1ll*cd.ans*fac%mod);
        chadd(ans,cd.ans);
    }
    ans = 1ll*ans*fac%mod;
    printf("%d\n",ans);
    return 0;
}