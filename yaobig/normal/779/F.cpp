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

const int maxn = 600000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int e[maxn+5][26],sz[maxn+5];
int ans[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n-1)
    {
        char s[5]; int x,y; scanf("%d%d%s",&x,&y,s);
        e[x][s[0]-'a'] = y;
    }
    int tot = n;
    auto newnode = [&]() {
        sz[++tot] = 1;
        memset(e[tot],0,sizeof e[tot]);
        return tot;
    };
    function<int(int,int)> merge = [&](int x,int y){
        if(x==0 || y==0) return x | y;
        int z = newnode();
        rep(i,0,25)
        {
            e[z][i] = merge(e[x][i],e[y][i]);
            sz[z] += sz[e[z][i]];
        }
        return z;
    };

    function<void(int,int)> dfs = [&](int now,int dep){
        sz[now] = 1;
        for(auto v: e[now]) if(v!=0) 
        {
            dfs(v,dep+1);
            sz[now] += sz[v];
        }
        tot = n;
        int x = newnode();
        for(auto v: e[now]) x = merge(x,v);
        ans[dep] += sz[now] - sz[x];
    };
    dfs(1,1);
    int mx = 0, d = -1;
    rep(i,1,n) if(chmax(mx,ans[i])) d = i;
    printf("%d\n%d\n",n-mx,d);
    return 0;
}