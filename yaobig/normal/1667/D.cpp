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

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        static vector<pii> e[maxn+5];
        static pii ed[maxn+5];
        rep(i,1,n) e[i].clear();
        rep(i,1,n-1)
        {
            int x,y; scanf("%d%d",&x,&y);
            e[x].pb({y,i});
            e[y].pb({x,i});
            ed[i] = {x,y};
        }
        bool ok = 1;
        static int par[maxn+5];
        static vi dom[maxn+5];
        rep(i,1,n-1) dom[i].clear();
        function<void(int,int)> dfs = [&] (int now,int fa) {
            int pid = -1;
            vi pool[2];
            for(auto [v,i]: e[now]) 
            {
                if(v==fa) { pid = i; continue; }
                dfs(v,now);
                pool[par[i]].pb(i);
            }
            if(pid!=-1)
            {
                if(sz(pool[0])>=sz(pool[1])) pool[1].pb(pid), par[pid] = 1;
                else pool[0].pb(pid), par[pid] = 0;
            }
            if(sz(pool[0])!=sz(pool[1]) && sz(pool[0])+1!=sz(pool[1])) ok = 0;
            else
            {
                int N = sz(pool[0]) + sz(pool[1]) - 1;
                while(N--)
                {
                    if(sz(pool[0])==sz(pool[1])) dom[pool[0].back()].pb(pool[1].back()), pool[0].pop_back();
                    else dom[pool[1].back()].pb(pool[0].back()), pool[1].pop_back();
                }
            }
        };
        dfs(1,0);
        if(ok==0) puts("NO");
        else
        {
            puts("YES");
            queue<int> q;
            vi deg(n);
            rep(i,1,n-1) for(auto x: dom[i]) deg[x]++;
            rep(i,1,n-1) if(deg[i]==0) q.push(i);
            while(sz(q))
            {
                int now = q.front(); q.pop();
                printf("%d %d\n",ed[now].FI,ed[now].SE);
                for(auto v: dom[now]) if(--deg[v]==0) q.push(v);
            }
        }
    }
    return 0;
}