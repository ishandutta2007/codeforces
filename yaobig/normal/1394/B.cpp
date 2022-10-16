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

const int maxn = 200'000;
const int inf = 0x3f3f3f3f;
const int mod = 1073741824;


int main()
{
    int n,m,k; scanf("%d%d%d",&n,&m,&k);
    static vector<pii> e[maxn+5];
    rep(i,1,m)
    {
        int x,y,w; scanf("%d%d%d",&x,&y,&w);
        e[x].pb({w,y});
    }
    static ll lim[maxn+5], ban[15][15];
    static bool gg[15][15];
    static int id[15][15];
    int tot = 0;
    rep(i,1,k) rep(j,1,i) id[i][j] = ++tot;
    rep(now,1,n)
    {
        sort(all(e[now]));
        int cnt = 0;
        for(auto [w,v]: e[now]) 
        {
            auto msk = 1ll<<id[sz(e[now])][++cnt];
            if(lim[v] & msk) gg[sz(e[now])][cnt] = 1;
            else lim[v] |= msk;
        }
    }
    rep(now,1,n)
    {
        int cnt = 0;
        for(auto [w,v]: e[now]) ++cnt, ban[sz(e[now])][cnt] |= lim[v] ^ (1ll<<id[sz(e[now])][cnt]);
    }
    int ans = 0;
    function<void(int,ll)> dfs = [&](int dep,ll msk) {
        if(dep>k) { ans++; return; }
        rep(j,1,dep) if((msk & (1ll<<id[dep][j]))==0 && gg[dep][j]==0)  dfs(dep+1, msk | ban[dep][j]);
    };
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}