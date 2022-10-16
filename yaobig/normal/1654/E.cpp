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
string to_string(bool b) {return (b ? "true" : "false");}
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
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

template<const int maxn> struct Union_Set
{
    int ti;
    array<int,maxn+5> fa,sz,mark;
    void init(int n) 
    {
        ti = 1;
        rep(i,1,n) mark[i] = 1;
    }
    int getfa(int x) 
    {
        if(mark[x]!=ti) fa[x] = x, sz[x] = 1, mark[x] = ti;
        return fa[x]==x ? x : fa[x]=getfa(fa[x]);
    }
	bool check(int x,int y) {return getfa(x)!=getfa(y);}
    int merge(int x,int y)
    {
        int fx = getfa(x), fy = getfa(y);
        if(fx==fy) return 0;
        if(sz[fx]<sz[fy]) swap(fx,fy);
        fa[fy] = fx;
        sz[fx] += sz[fy];
        return sz[fx];
    }
};

Union_Set<maxn+5> us;

int a[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    int ans = 1;
    auto solve = [&]() {
        static ll b[maxn+5];
        rep(i,1,n) b[i] = a[i];
        int sq = 200;
        rep(d,0,sq)
        {
            static vector<ll> vec; vec.clear();
            rep(i,1,n) vec.pb(b[i]);
            sort(all(vec));
            ll last = -1ll<<60;
            int cnt = 0;
            for(auto x: vec)
            {
                if(last!=x) last = x, cnt = 0;
                cnt++, chmax(ans, cnt);
            }
            rep(i,1,n) b[i] -= i-1;
        }
        static vector<pii> pool[maxn+5];
        rep(i,0,maxn) pool[i].clear();
        int L = maxn/sq;
        rep(i,1,n) rep(j,i+1,min(i+L,n))
        {
            if(a[j]>=a[i] && (a[j]-a[i])%(j-i)==0)
            {
                int d = (a[j]-a[i])/(j-i);
                pool[d].pb({i,j});
            }
        }
        us.init(n);
        rep(d,0,maxn) 
        {
            us.ti++;
            for(auto [i,j]: pool[d])
            {
                int res = us.merge(i,j);
                if(res) chmax(ans, res);
            }
        }
    };
    solve();
    rep(i,1,n) a[i] = maxn+1-a[i];
    solve();
    printf("%d\n",n-ans);
    return 0;
}