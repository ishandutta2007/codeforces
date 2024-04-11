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

const int maxn = 50;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

using mat = array<array<char,maxn+5>,maxn+5>;
mat s,t;

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) 
    {
        static char b[maxn+5]; scanf("%s",b+1);
        rep(j,1,m) s[i][j] = b[j];
    }
    rep(i,1,n) 
    {
        static char b[maxn+5]; scanf("%s",b+1);
        rep(j,1,m) t[i][j] = b[j];
    }

    int inv = m&1;
    if(inv)
    {
        static char M[300]; 
        M['U'] = 'L';
        M['D'] = 'R';
        M['L'] = 'U';
        M['R'] = 'D';
        static char tmp[maxn+5][maxn+5];
        rep(i,1,n) rep(j,1,m) tmp[i][j] = M[(int)s[i][j]];
        rep(i,1,n) rep(j,1,m) s[j][i] = tmp[i][j];
        rep(i,1,n) rep(j,1,m) tmp[i][j] = M[(int)t[i][j]];
        rep(i,1,n) rep(j,1,m) t[j][i] = tmp[i][j];
        swap(n,m);
    }
    static char a[maxn+5][maxn+5];
    rep(i,1,n) rep(j,1,m) a[i][j] = j&1 ? 'L' : 'R';

    vector<pii> A,B;
    function<void(mat&,int,int,vector<pii>&)> dfs = [&](mat &s,int x,int y,vector<pii> &ans) {
        char c = s[x][y];
        //debug(x,y);
        if(c=='L')
        {
            assert(x+1<=n);
            if(s[x+1][y]!='L') dfs(s,x+1,y,ans);
            s[x][y] = s[x][y+1] = 'U';
            s[x+1][y] = s[x+1][y+1] = 'D';
        }
        else
        {
            assert(y+1<=m);
            if(s[x][y+1]!='U') dfs(s,x,y+1,ans);
            s[x][y] = s[x+1][y] = 'L';
            s[x][y+1] = s[x+1][y+1] = 'R';
        }
        ans.pb({x,y});
    };
    rep(i,1,n) rep(j,1,m) if(s[i][j]!=a[i][j]) dfs(s,i,j,A);
    rep(i,1,n) rep(j,1,m) if(t[i][j]!=a[i][j]) dfs(t,i,j,B);
    reverse(all(B));
    A.insert(A.end(),all(B));
    printf("%d\n",sz(A));
    for(auto [x,y]: A) printf("%d %d\n",inv?y:x,inv?x:y);
    return 0;
}