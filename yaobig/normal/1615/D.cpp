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

const int maxn = 200000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

pii ed[maxn+5];
int ans[maxn+5];

vector<pii> e[maxn+5];

struct solver
{
    vector<pii> e[maxn+5];
    int n,vis[maxn+5];
    void init(int _n)
    {
        n = _n;
        rep(i,1,n) e[i].clear();
        rep(i,1,n) vis[i] = 0;
    }
    void addedge(int x,int y,int c)
    {
        e[x].pb({y,c});
        e[y].pb({x,c});
    }
    bool solve(vi &clr)
    {
        int ok = 1;
        clr.assign(n+1,0);
        function<void(int,int)> dfs = [&](int now,int c) {
            vis[now] = 1;
            clr[now] = c;
            for(auto [v,w]: e[now]) 
            {
                if(vis[v]==0) dfs(v,c^w);
                else if(c!=(clr[v]^w)) ok = 0;
            }
        };
        rep(i,1,n) if(ok && vis[i]==0) dfs(i,0);
        return ok;
    }
}sol;

void dfs(int now,int fa)
{
    for(auto [v,w]: e[now]) if(v!=fa)
    {
        if(w!=-1) sol.addedge(now,v,w);
        dfs(v,now);
    }
}

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n,m; scanf("%d%d",&n,&m);
        rep(i,1,n) e[i].clear();
        rep(i,1,n-1)
        {
            int x,y,w; scanf("%d%d%d",&x,&y,&w);
            ed[i] = {x,y}; ans[i] = w;
            if(w==-1) 
            {
                e[x].pb({y,-1});
                e[y].pb({x,-1});
            }
            else
            {
                e[x].pb({y,__builtin_popcount(w)&1});
                e[y].pb({x,__builtin_popcount(w)&1});
            }
        }
        sol.init(n);
        dfs(1,0);
        while(m--)
        {
            int x,y,w; scanf("%d%d%d",&x,&y,&w);
            sol.addedge(x,y,w);
        }
        vi res;
        bool ok = sol.solve(res);
        if(ok==0) puts("NO");
        else
        {
            puts("YES");
            rep(i,1,n-1)
            {
                auto [x,y] = ed[i]; int w = ans[i];
                if(w!=-1) printf("%d %d %d\n",x,y,w);
                else
                {
                    printf("%d %d %d\n",x,y,res[x]^res[y]);
                }
            }
        }
    }
    return 0;
}