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

const int maxn = 100000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

vi e[maxn+5];

int main()
{
    int n,k; scanf("%d%d",&n,&k);
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }

    static int pre[maxn+5];
    function<void(int,int,int,int&,int&)> getfar = [&](int now,int fa,int dep,int &mx,int &far) {
        pre[now] = fa;
        if(chmax(mx,dep)) far = now;
        for(auto v: e[now]) if(v!=fa) getfar(v,now,dep+1,mx,far);
    };
    int mx = 0, x = -1;
    getfar(1,0,0,mx,x);
    mx = 0; int y = -1;
    getfar(x,0,0,mx,y);

    vi A; int now = y;
    while(now)
    {
        A.pb(now); now = pre[now];
    }
    if(sz(A)!=k*2+1) return puts("No"), 0;

    int rt = A[k];
    int ok = 1;

    function<void(int,int,int)> dfs = [&](int now,int fa,int dep) {
        if(dep==0) ok &= sz(e[now])>=3;
        else if(dep<k) ok &= sz(e[now])-1>=3;
        else if(dep==k) ok &= sz(e[now])==1;
        else ok = 0;

        for(auto v: e[now]) if(v!=fa) dfs(v,now,dep+1);
    };
    dfs(rt,0,0);
    puts(ok?"Yes":"No");
    return 0;
}