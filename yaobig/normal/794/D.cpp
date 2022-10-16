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

const int maxn = 300'000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

using hashv = pair<int,int>;
const int mod1 = 1000000007;
const int mod2 = 1000050131;

inline int Madd(int x,int y,int mod) {return x+y<mod?x+y:x+y-mod;}
inline int Msub(int x,int y,int mod) {return x-y>=0?x-y:x-y+mod;}

hashv operator +(hashv a,hashv b) {return {Madd(a.FI,b.FI,mod1), Madd(a.SE,b.SE,mod2)};}
hashv operator +(hashv a,int b) {return {Madd(a.FI,b,mod1), Madd(a.SE,b,mod2)};}
hashv operator -(hashv a,hashv b) {return {Msub(a.FI,b.FI,mod1), Msub(a.SE,b.SE,mod2)};}
hashv operator *(hashv a,hashv b) {return {1ll*a.FI*b.FI%mod1, 1ll*a.SE*b.SE%mod2};}
hashv operator *(hashv a,int b) {return {1ll*a.FI*b%mod1, 1ll*a.SE*b%mod2};}

const hashv base = {2,2};
hashv pw[maxn+5];

int main()
{
    pw[0] = {1,1};
    rep(i,1,maxn) pw[i] = pw[i-1]*base;

    int n,m; scanf("%d%d",&n,&m);
    vector<pii> E(m);
    for(auto &it: E) scanf("%d%d",&it.FI,&it.SE);
    static hashv hx[maxn+5];
    rep(i,1,n) hx[i] = hx[i] + pw[i];
    for(auto [x,y]: E)
    {
        hx[x] = hx[x] + pw[y];
        hx[y] = hx[y] + pw[x];
    }
    map<hashv,vi> M;
    rep(i,1,n) M[hx[i]].pb(i);
    int N = sz(M);
    if(N==1)
    {
        puts("YES");
        rep(i,1,n) printf("%d%c",1," \n"[i==n]);
        return 0;
    }
    static set<int> e[maxn+5];
    for(auto [x,y]: E)
    {
        int u = M[hx[x]][0];
        int v = M[hx[y]][0];
        if(u==v) continue;
        e[u].insert(v);
        e[v].insert(u);
    }
    int id = -1;
    for(auto &it: M)
    {
        int x = it.SE[0];
        if(sz(e[x])==1) id = x;
    }
    if(id==-1) return puts("NO"),0;
    int now = id, last = 0, tot = 0;
    map<hashv,int> X;
    while(now)
    {
        X[hx[now]] = ++tot;
        if(sz(e[now])>2) return puts("NO"),0;
        int nxt = last; last = now;
        for(auto v: e[now]) nxt ^= v;
        now = nxt;
    }
    if(tot!=N) return puts("NO"),0;
    puts("YES");
    rep(i,1,n) printf("%d%c",X[hx[i]]," \n"[i==n]);
    return 0;
}