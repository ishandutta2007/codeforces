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

const int maxn = 500;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int dis[maxn+5][maxn+5],e[maxn+5][maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    memset(dis,0x3f,sizeof dis);
    rep(i,1,n) dis[i][i] = 0;
    rep(i,1,m)
    {
        int x,y,w; scanf("%d%d%d",&x,&y,&w);
        e[x][y] = e[y][x] = w;
        chmin(dis[x][y],w);
        chmin(dis[y][x],w);
    }
    rep(k,1,n) rep(i,1,n) rep(j,1,n) chmin(dis[i][j],dis[k][i]+dis[k][j]);
    rep(src,1,n)
    {
        static int cnt[maxn+5];
        rep(i,1,n) cnt[i] = 0;
        rep(i,1,n) rep(j,1,n) if(e[i][j] && dis[src][i]==dis[src][j]+e[i][j]) cnt[i]++;
        rep(dest,src+1,n) 
        {
            int ans = 0;
            rep(i,1,n) if(dis[src][dest]==dis[src][i]+dis[dest][i]) ans += cnt[i];
            printf("%d ",ans);
        }
    }
    puts("");
    return 0;
}