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

const int maxn = 100000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

const int MAXA = 2000000;
int maxp[MAXA+5];

int a[maxn+5],dep[maxn+5];
vi e[maxn+5],sta[MAXA+5];
int ans[maxn+5];

void dfs(int now,int fa)
{
    dep[now] = dep[fa]+1;
    ans[now] = -1;
    int x = a[now], last = 0, mx = 0;
    vi pf;
    while(x!=1)
    {
        int p = maxp[x]; x /= p;
        if(last!=p)
        {
            last = p;
            pf.pb(p);
        }
    }
    for(auto p: pf) if(sz(sta[p]) && chmax(mx,dep[sta[p].back()])) ans[now] = sta[p].back();
    for(auto p: pf) sta[p].pb(now);
    for(auto v: e[now]) if(v!=fa) dfs(v,now);
    for(auto p: pf) sta[p].pop_back();
}

int main()
{
    rep(i,2,MAXA) if(maxp[i]==0)
    {
        for(int j = i;j<=MAXA;j += i) maxp[j] = i;
    }
    int n,q; scanf("%d%d",&n,&q);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    dfs(1,0);
    while(q--)
    {
        int op,v; scanf("%d%d",&op,&v);
        if(op==1) printf("%d\n",ans[v]);
        else
        {
            int w; scanf("%d",&w);
            a[v] = w;
            dfs(1,0);
        }
    }
    return 0;
}