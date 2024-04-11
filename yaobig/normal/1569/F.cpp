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

const int maxn = 15;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int g[maxn+5][maxn+5];
ll pw[15];

vector<pii> match;
int vis[maxn+5];
bool dp[1<<6][6];

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
gp_hash_table<ll,int> H;

vector<ll> vec;
using node = array<int,12>;
int n;


inline ll node2ll(const node &x)
{
    ll res = 0;
    rep(i,0,n-1) res += x[i]*pw[i];
    return res; 
}
inline node ll2node(const ll &x)
{
    node res{};
    rep(i,0,n-1) res[i] = x/pw[i]%6;
    return res;
}


void getmatch(int dep)
{
    if(dep==n)
    {
        int h = n/2, N = 1<<h;
        //for(auto p: match) debug(p);
        rep(msk,1,N-1) rep(last,0,h-1)
        {
            dp[msk][last] = 0;
            if((msk>>last&1) == 0) continue;
            int nmsk = msk ^ (1<<last);
            //debug(msk,nmsk,sz(match));
            auto [x,y] = match[last];
            if(nmsk==0) dp[msk][last] = g[x][y];
            else
            {
                rep(nlast,0,h-1) if(dp[nmsk][nlast]) 
                {
                    auto [u,v] = match[nlast];
                    //debug(msk, x, y, nmsk, u, v);
                    if((g[u][x] && g[v][y]) || (g[u][y] && g[v][x])) 
                    {
                        dp[msk][last] = 1; break;
                    }
                }
            }
        }
        //puts("fuck");
        int ok = 0;
        rep(i,0,h-1) if(dp[N-1][i]) ok = 1;
        if(ok)
        {
            //for(auto [x,y]: match) debug(pii{x,y});
            ll st=0;
            rep(i,0,sz(match)-1) st += i*(pw[match[i].FI]+pw[match[i].SE]);
            vec.pb(st);
        }
        return;
    }
    if(vis[dep]) getmatch(dep+1);
    else
    {
        rep(i,dep+1,n-1) if(vis[i]==0)
        {
            vis[dep]=vis[i]=1;
            match.pb({dep,i});
            getmatch(dep+1);
            vis[dep]=vis[i]=0;
            match.pop_back();
        }
    }
}

int main()
{
    pw[0]=1;
    rep(i,1,12) pw[i] = pw[i-1]*6;
    int m,k; scanf("%d%d%d",&n,&m,&k);
    rep(i,1,m)
    {
        int x,y; scanf("%d%d",&x,&y); x--; y--;
        g[x][y]=g[y][x]=1;
    }
    getmatch(0);
    rep(id,0,sz(vec)-1)
    {
        auto now = ll2node(vec[id]);
        int C = 0;
        rep(i,0,n-1) chmax(C, now[i]);
        rep(from,0,C) rep(to,0,from-1)
        {
            auto nn = now;
            rep(i,0,n-1) 
            {
                if(nn[i]==from) nn[i]=to;
                else if(nn[i]>from) nn[i]--;
            }
            auto MSK = node2ll(nn);
            if(H.find(MSK)==H.end())
            {
                H[MSK] = 1;
                vec.push_back(MSK);
            }
        }
    }
    vector<ll> downfac(15);
    downfac[0] = 1;
    rep(i,1,k) downfac[i] = downfac[i-1]*(k-i+1);
    ll ans = 0;
    for(auto MSK: vec)
    {
        auto now = ll2node(MSK);
        //rep(i,0,n-1) debug(i, now[i]);
        int C = 0;
        rep(i,0,n-1) chmax(C, now[i]+1);
        //rep(i,0,n-1) printf("%d ",now[i]);
        //printf(" %d\n",C);
        if(C<=k) ans += downfac[C];
    }
    printf("%lld\n",ans);
    return 0;
}