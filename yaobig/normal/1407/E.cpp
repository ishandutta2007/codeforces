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

const int maxn = 500'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    static vector<pii> e[maxn+5];
    rep(i,1,m)
    {
        int u,v,c; scanf("%d%d%d",&u,&v,&c);
        e[v].pb({u,c});
    }
    static int dis[maxn+5], ban[maxn+5];
    rep(i,1,n) dis[i] = inf, ban[i] = -1;
    dis[n] = 0, ban[n] = 0;
    queue<int> q; q.push(n);
    while(sz(q))
    {
        int now = q.front(); q.pop();
        for(auto [v,c]: e[now]) 
        {
            if(c!=ban[v])
            {
                if(ban[v]==-1) ban[v] = c;
                else if(chmin(dis[v],dis[now]+1)) q.push(v);
            }
        }
    }
    printf("%d\n",dis[1]==inf ? -1 : dis[1]);
    rep(i,1,n) printf("%d%s",ban[i]==1 ? 0 : 1, i==n ? "\n" : "");
    return 0;
}