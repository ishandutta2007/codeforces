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

const int maxn = 400;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

inline void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}

vi e[maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,m)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    auto bfs = [&](int n,int st,vi &dis) {
        dis.assign(n+1,inf);
        dis[st] = 0;
        queue<int> q; q.push(st);
        while(sz(q))
        {
            int now = q.front(); q.pop();
            for(auto v: e[now]) if(chmin(dis[v],dis[now]+1)) q.push(v);
        }
    };
    static vi dis[maxn+5];
    rep(i,1,n) bfs(n,i,dis[i]);
    static int ans[maxn+5][maxn+5], mark[maxn+5][maxn+5];
    int ti = 0;
    rep(i,1,n) rep(j,i,n)
    {
        ti++;
        int res = 1;
        int D = dis[i][j];
        rep(now,1,n)
        {
            int ways = 0, d1 = dis[i][now], d2 = dis[j][now];
            if(d1+d2==D)
            {
                if(mark[d1][d2]==ti) { res = 0; break; }
                else mark[d1][d2] = ti, ways = 1;
            }
            else for(auto v: e[now])  ways += dis[i][v]==d1-1 && dis[j][v]==d2-1;
            res = 1ll*res*ways%mod;
        }
        ans[i][j] = ans[j][i] = res;
    }
    rep(i,1,n) rep(j,1,n) printf("%d%c",ans[i][j]," \n"[j==n]);
    return 0;
}