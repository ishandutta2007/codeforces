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

const int maxn = 300000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

inline void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}

vi e[maxn+5];
int ind[maxn+5];
int a[maxn+5];
int cnt[maxn+5];

void dfs(int now,int dep)
{
    if(ind[now]<=1 && sz(e[now])==0) 
    {
        cnt[dep]++;
        return;
    }
    if(ind[now]>1 || sz(e[now])!=1) return;
    for(auto v: e[now]) dfs(v,dep+1);
}

int dp[maxn+5];

int main()
{
    int n,m,k; scanf("%d%d%d",&n,&m,&k);
    set<pii> S;
    rep(i,1,n)
    {
        int l; scanf("%d",&l);
        rep(i,1,l) scanf("%d",&a[i]);
        rep(i,1,l-1) if(S.count({a[i],a[i+1]})==0)
        {
            e[a[i]].pb(a[i+1]);
            S.insert({a[i],a[i+1]});
            ind[a[i+1]]++;
        }
    }
    rep(i,1,k) if(ind[i]==0) dfs(i,1);
    vi vec;
    rep(i,1,k) if(cnt[i]) vec.pb(i);
    dp[0]=1;
    rep(i,1,m) for(auto v: vec) if(i>=v) chadd(dp[i],1ll*dp[i-v]*cnt[v]%mod);
    printf("%d\n",dp[m]);
    return 0;
}