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

const int maxn = 1<<18;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

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

const hashv base = {131,10007}; //{100003,100019}, {500009,500029}
hashv pw[maxn+5];

vector<hashv> hx[maxn+5][18];

int main()
{
    pw[0] = {1,1};
    rep(i,1,maxn) pw[i] = pw[i-1]*base;

    int n; scanf("%d",&n);
    int N = 1<<n;
    static char s[maxn+5]; scanf("%s",s);
    function<void(int,int,int)> solve = [&](int dep,int st,int len) {
        if(dep==0)
        {
            hx[st][0].pb(hashv{s[st],s[st]});
            return;
        }
        int m = len/2;
        solve(dep-1,st,m); solve(dep-1,st+m,m);
        rep(i,0,m-1) hx[st][dep].pb(hx[st][dep-1][i]*pw[m]+hx[st+m][dep-1][i]);
        rep(i,0,m-1) hx[st][dep].pb(hx[st+m][dep-1][i]*pw[m]+hx[st][dep-1][i]);
    };
    solve(n,0,N);

    auto cmp = [&](int i,int j) {
        if(hx[0][n][i]==hx[0][n][j]) return false;

        function<bool(int,int,int,int,int)> dfs = [&](int dep,int msk1,int msk2,int st1,int st2) {
            if(dep==0) return s[st1]>s[st2];

            int nmsk1 = msk1>>(dep-1)&1 ? msk1^(1<<(dep-1)) : msk1;
            int nmsk2 = msk2>>(dep-1)&1 ? msk2^(1<<(dep-1)) : msk2;
            int nst1 = msk1>>(dep-1)&1 ? st1^(1<<(dep-1)) : st1;
            int nst2 = msk2>>(dep-1)&1 ? st2^(1<<(dep-1)) : st2;
            if(hx[nst1][dep-1][nmsk1]!=hx[nst2][dep-1][nmsk2]) return dfs(dep-1,nmsk1,nmsk2,nst1,nst2);
            else return dfs(dep-1,nmsk1,nmsk2,nst1^(1<<(dep-1)),nst2^(1<<(dep-1)));
        };
        return dfs(n,i,j,0,0);
    };
    int id = 0;
    rep(i,1,N-1) if(cmp(id,i)) id = i;
    rep(i,0,N-1) putchar(s[i^id]);
    puts("");
    return 0;
}