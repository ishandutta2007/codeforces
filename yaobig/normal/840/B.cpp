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
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

vector<pii> e[maxn+5];
int d[maxn+5],cnt[maxn+5],vis[maxn+5];

vi ans;
void dfs(int now)
{
    vis[now] = 1;
    for(auto [v,id]: e[now]) if(vis[v]==0)
    {
        dfs(v);
        cnt[now] ^= cnt[v];
        if(cnt[v]&1) ans.pb(id);
    }
}

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&d[i]);
    rep(i,1,m)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb({y,i});
        e[y].pb({x,i});
    }
    int spe = min_element(d+1,d+n+1) - d, ok = d[spe]==-1;
    int tot = 0;
    rep(i,1,n) if(d[i]==1) cnt[i] ^= 1, tot++;
    if(tot&1)
    {
        if(ok==0) return puts("-1"),0;
        else cnt[spe] ^= 1;
    }
    dfs(1);
    printf("%d\n",sz(ans));
    for(auto x: ans) printf("%d\n",x);
    return 0;
}