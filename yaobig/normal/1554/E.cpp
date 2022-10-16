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
template <typename A, typename B> 
string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}

void debug_out() {cerr << endl;} 
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) 
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
using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 100000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

vi e[maxn+5];
int f[maxn+5],g[maxn+5];

int dfs(int now,int fa,int k)
{
    int x = sz(e[now]);
    for(auto v: e[now]) if(v!=fa)
    {
        int res = dfs(v,now,k);
        if(res==-1) return -1;
        x -= res;
    }
    if(x%k==0) return 1;
    if(now!=1 && (x-1)%k==0) return 0;
    return -1;
}

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        rep(i,1,n) e[i].clear();
        rep(i,1,n-1)
        {
            int x,y; scanf("%d%d",&x,&y);
            e[x].pb(y);
            e[y].pb(x);
        }
        rep(i,1,n) f[i]=0;
        f[1] = 1;
        rep(i,1,n-1) f[1]=f[1]*2%mod;
        rep(k,2,n-1) if((n-1)%k==0) f[k] = dfs(1,0,k)!=-1;
        per(i,1,n) 
        {
            g[i] = f[i];
            for(int j = i*2; j<=n; j+=i) g[i] = (g[i] - g[j] + mod) % mod;
        }
        rep(i,1,n) printf("%d%c",g[i]," \n"[i==n]);
    }
    return 0;
}