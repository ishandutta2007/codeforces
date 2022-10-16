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

const int maxn = 300000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

vi e[2][maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,m)
    {
        int u,v; scanf("%d%d",&u,&v);
        e[0][u].pb(v);
        e[1][v].pb(u);
    }
    // cnt[o][u] is either: 
    // - the number of vertices that stands after vertex u in the topo order, 
    // - or -inf. (-inf only happens when we can assure that there are >= 2 vertices which has no path between them and u.)

    static int cnt[2][maxn+5];
    auto solve = [&](int o) {
        static int deg[maxn+5];
        rep(i,1,n) deg[i] = sz(e[o^1][i]);
        queue<int> q;
        rep(i,1,n) if(deg[i]==0) q.push(i);
        int tot = 0;
        while(sz(q))
        {
            int now = q.front(); q.pop(); tot++;
            if(sz(q)==0) cnt[o][now] = n-tot;
            else if(sz(q)==1)
            {
                int nxt = q.front();
                cnt[o][now] = n-tot-1;
                for(auto v: e[o][nxt]) if(deg[v]==1) {cnt[o][now] = -inf; break;}
            }
            else cnt[o][now] = -inf;
            for(auto v: e[o][now]) if(--deg[v]==0) q.push(v);
        }
    };
    solve(0);
    solve(1);
    int ans = 0;
    rep(i,1,n) ans += cnt[0][i]+cnt[1][i]>=n-2;
    printf("%d\n",ans);
    return 0;
}