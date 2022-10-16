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

const int maxn = 150;
const int inf = 0x3f3f3f3f;
const int mod = 1'000'000'007;

const int MatN = 155;
using Vec = bitset<MatN>;
using Mat = array<Vec,MatN>;

Mat operator *(const Mat &a,const Mat &b)
{
    Mat res{};
    rep(i,0,MatN-1) rep(j,0,MatN-1) if(a[i][j]) res[i] |= b[j];
    return res;
}

Mat qp(Mat a,ll k)
{
    Mat res{}; rep(i,0,MatN-1) res[i][i] = 1;
    for(;k;k>>=1,a=a*a) if(k&1) res=res*a;
    return res;
}


int main()
{
    int n,m; scanf("%d%d",&n,&m);
    map<int,vector<pii>> M;
    rep(i,1,m)
    {
        int x,y,d; scanf("%d%d%d",&x,&y,&d);
        M[d].pb({x,y});
    }
    Mat A{}; A[1][1] = 1;
    Mat base{};
    int last = 0, ans = inf;
    for(auto [t,e]: M)
    {
        A = A * qp(base,t-last);
        for(auto [x,y]: e) base[x][y] = 1;
        static int dis[maxn+5][maxn+5];
        rep(i,1,n) rep(j,1,n) dis[i][j] = i==j ? 0 : inf;
        rep(i,1,n) rep(j,1,n) if(base[i][j]) chmin(dis[i][j], 1);
        rep(k,1,n) rep(i,1,n) rep(j,1,n) chmin(dis[i][j],dis[i][k]+dis[k][j]);
        rep(i,1,n) if(A[1][i]) chmin(ans, t+dis[i][n]);
        last = t;
    }
    if(ans>=inf) puts("Impossible");
    else printf("%d\n",ans);
    return 0;
}