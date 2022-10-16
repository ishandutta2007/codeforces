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
string to_string(char c) {return "'" + string(1,c) + "'";}
string to_string(bool x) {return x ? "true" : "false";}
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
const int mod = 998244353;

pii operator +(pii a,pii b) { return pii{a.FI + b.FI, a.SE + b.SE}; }

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    static vi e[2][maxn+5];
    rep(i,1,m)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[0][x].pb(y);
        e[1][y].pb(x);
    }
    pii dis[19][maxn+5]; memset(dis,0x3f,sizeof dis);
    dis[0][1] = {0,0};
    using P = pair<pii,pii>;
    priority_queue<P,vector<P>,greater<P> > q; q.push(mp(dis[0][1],pii{0,1}));
    while(sz(q))
    {
        auto [d,it] = q.top(); q.pop();
        auto [rd,now] = it;
        if(d!=dis[rd][now]) continue;
        auto upd = [&](int rd,int now,int nrd,int v,pii w) {
            if(chmin(dis[nrd][v], dis[rd][now] + w)) q.push(mp(dis[nrd][v],pii{nrd,v}));
        };
        for(auto v: e[rd&1][now]) upd(rd,now,rd,v,pii{0,1});
        int nrd = rd==18 ? rd-1 : rd+1;
        upd(rd,now,nrd,now,pii{1,0});
    }
    int ans = inf;
    pii best = {inf,inf};
    rep(rd,0,18)
    {
        auto [x,y] = dis[rd][n];
        if(x<=18) chmin(ans, (1<<x)-1+y);
        chmin(best, {x,y});
    }
    if(ans==inf)
    {
        ans = 1;
        auto [x,y] = best;
        while(x--) ans = ans * 2 % mod;
        ans = (ans - 1 + mod) % mod;
        ans = (ans + y) % mod;
    }
    printf("%d\n",ans);
    return 0;
}