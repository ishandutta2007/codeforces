#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
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

const int maxn = 100;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

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
    int work()
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
}M;

int a[maxn+5],b[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    int m; scanf("%d",&m);
    rep(i,1,m) scanf("%d",&b[i]);
    M.init(n,m);
    rep(i,1,n) rep(j,1,m) if(abs(a[i]-b[j])<=1) M.e[i].pb(j);
    printf("%d\n",M.work());
    return 0;
}