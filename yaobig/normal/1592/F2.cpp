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

const int maxn = 500;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int a[maxn+5][maxn+5];
char s[maxn+5];

struct Kuhn
{
    // indices start from 1.
    int n,m; // n=size of X, m=size of Y.
    vi e[maxn+5]; // from X part to Y part.
    int from[maxn+5]; // record the matched vertex for vertices in Y.
    bool used[maxn+5];

    void init(int _n,int _m) 
    {
        n=_n, m=_m;
        rep(i,1,n) e[i].clear();
    }
    void addedge(int x, int y) {e[x].pb(y);}
    bool match(int u)
    {
        for(auto v: e[u]) if(used[v]==0)
        {
            used[v]=1;
            if(from[v]==-1 || match(from[v]))
            {
                from[v]=u;
                return 1;
            }
        }
        return 0;
    }
    int work() // use this to get maximum matching.
    {
        int res=0;
        rep(i,1,m) from[i]=-1;
        rep(i,1,n)
        {
            rep(i,1,m) used[i]=0;
            res+=match(i);
        }
        return res;
    }
}mt;


int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) 
    {
        scanf("%s",s+1);
        rep(j,1,m) a[i][j]=s[j]=='B';
    }
    rep(i,1,n) rep(j,1,m) a[i][j]^=a[i][j+1]^a[i+1][j]^a[i+1][j+1];
    int ans=0;
    rep(i,1,n) rep(j,1,m) ans+=a[i][j];
    mt.init(n-1,m-1);
    rep(i,1,n-1) rep(j,1,m-1) if(a[i][j] && a[i][m] && a[n][j]) mt.addedge(i,j);
    int down=mt.work();
    //debug(a[n][m]);
    //debug(down);
    if(a[n][m] && down&1) down++;
    if(a[n][m]==0 && down&1) down--;
    printf("%d\n",ans-down);
    return 0;
}