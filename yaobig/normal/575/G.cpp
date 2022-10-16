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

vector<pii> e[maxn+5];
vi bac[maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,m)
    {
        int x,y,w; scanf("%d%d%d",&x,&y,&w); x++; y++;
        e[x].pb({y,w});
        e[y].pb({x,w});
        if(w==0) bac[x].pb(y), bac[y].pb(x);
    }
    vi dis(n+1,inf), dis_zero(n+1,inf), nxt(n+1);
    queue<int> q; q.push(n); dis_zero[n] = 0;
    while(sz(q))
    {
        int now = q.front(); q.pop();
        for(auto v: bac[now]) if(chmin(dis_zero[v],dis_zero[now]+1)) q.push(v), nxt[v] = now;
    }
    q.push(1); dis[1] = 0;
    while(sz(q))
    {
        int now = q.front(); q.pop();
        for(auto [v,w]: e[now]) if(chmin(dis[v],dis[now]+1)) q.push(v);
    }
    int D = inf;
    rep(i,1,n) if(dis_zero[i]!=inf) chmin(D,dis[i]);

    static vi pool[maxn+5];
    rep(i,1,n) if(dis[i]!=inf) pool[dis[i]].pb(i);
    vi mark(n+1,0); 
    rep(i,1,n) if(dis[i]==D && dis_zero[i]!=inf) mark[i] = 1;
    vi ans;
    per(i,0,D-1) 
    {
        int mn = 9;
        for(auto now: pool[i]) for(auto [v,w]: e[now]) if(dis[v]==i+1 && mark[v]) chmin(mn,w);
        for(auto now: pool[i]) for(auto [v,w]: e[now]) if(dis[v]==i+1 && mark[v] && w==mn) mark[now] = 1;
        putchar('0'+mn);
        ans.pb(mn);
    }
    puts(D ? "": "0");
    assert(mark[1]);
    vi pre(n+1,-1);
    pre[1] = 0;
    reverse(all(ans));
    rep(i,0,D-1) for(auto now: pool[i]) if(pre[now]!=-1) for(auto [v,w]: e[now]) if(dis[v]==dis[now]+1 && w==ans[i]) pre[v] = now;
    int mn = inf, tar = -1;
    rep(i,1,n) if(dis_zero[i]!=inf && pre[i]!=-1 && chmin(mn,dis_zero[i])) tar = i;
    assert(tar!=-1);
    vi vec;
    int now = tar;
    while(now!=1) now = pre[now], vec.pb(now);
    reverse(all(vec));
    now = tar;
    while(now) vec.pb(now), now = nxt[now];
    printf("%d\n",sz(vec));
    rep(i,1,sz(vec)) printf("%d%c",vec[i-1]-1," \n"[i==sz(vec)]);
    return 0;
}