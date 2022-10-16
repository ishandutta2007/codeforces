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
template <typename A> string to_string(A v) 
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
//using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 500;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

char s[maxn+5][maxn+5];
const pii mov[4] = {{1,0},{-1,0},{0,1},{0,-1}};
vector<pii> e[maxn+5][maxn+5];
int clr[maxn+5][maxn+5];
void dfs(int x,int y,int c)
{
    clr[x][y] = c;
    for(auto [nx,ny]: e[x][y]) if(clr[nx][ny]==0) dfs(nx,ny,5-c); else assert(clr[nx][ny]==5-c); 
}

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%s",s[i]+1);
    rep(i,1,n) rep(j,1,m) if(s[i][j]=='X')
    {
        static vector<pii> tmp; tmp.clear(); 
        for(auto [dx,dy]: mov)
        {
            int ni = i + dx;
            int nj = j + dy;
            if(s[ni][nj]=='.') tmp.pb({ni,nj});
        } 
        auto addedge = [](pii a,pii b) {e[a.FI][a.SE].pb(b);};
        if(sz(tmp)&1) return puts("NO"),0;
        if(sz(tmp)==2) addedge(tmp[0],tmp[1]), addedge(tmp[1],tmp[0]);
        if(sz(tmp)==4) addedge(tmp[0],tmp[2]), addedge(tmp[2],tmp[0]), addedge(tmp[1],tmp[3]), addedge(tmp[3],tmp[1]);
    }
    rep(i,1,n) rep(j,1,m) if(s[i][j]=='.' && clr[i][j]==0) dfs(i,j,1);
    puts("YES");
    rep(i,1,n) rep(j,1,m)
    {
        if(s[i][j]=='X') for(auto [dx,dy]: mov) 
        {
            int nx = i+dx, ny = j+dy;
            if(s[nx][ny]=='.') clr[i][j] += clr[nx][ny];
        }
        printf("%d%c",clr[i][j]," \n"[j==m]);
    }
    return 0;
}