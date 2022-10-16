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

const int maxn = 300000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int c[maxn+5];
char s[maxn+5];
vi e[maxn+5];
int nxt[maxn*2+5][26],sz[maxn*2+5];
int tot;
int ans, cnt;

int Merge(int x,int y)
{
    if(x==0 || y==0) return x|y;
    int z = ++tot;
    memcpy(nxt[z],nxt[x],sizeof nxt[x]);
    rep(i,0,25) if(nxt[y][i]) nxt[z][i] = Merge(nxt[z][i],nxt[y][i]);
    rep(i,0,25) sz[z] += sz[nxt[z][i]];
    sz[z]++;
    return z;
}

void dfs(int now,int fa)
{
    for(auto v: e[now]) if(v!=fa)
    {
        dfs(v,now);
        int ch = s[v]-'a';
        nxt[now][ch] = Merge(v,nxt[now][ch]);
    }
    rep(i,0,25) sz[now] += sz[nxt[now][i]];
    sz[now]++;
    if(chmax(ans,sz[now]+c[now])) cnt = 1;
    else if(ans==sz[now]+c[now]) cnt++;
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&c[i]);
    scanf("%s",s+1);
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    tot = n;
    dfs(1,0);
    printf("%d\n%d\n",ans,cnt);
    return 0;
}