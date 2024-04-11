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

const int maxn = 200000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

template<class T> struct BIT
{
    int n;
    T a[maxn+5];
    void init(int _n)
    {
        n=_n;
        rep(i,1,n) a[i]=0;
    }
    void add(int i,T x) {for(;i<=n;i+=i&-i) a[i]+=x;}
    T ask(int i)
    {
        T ans=0;
        for(;i;i-=i&-i) ans+=a[i];
        return ans;
    }
    void add(int l,int r,T x) {add(l,x); add(r+1,-x);}
};
BIT<int> bit;

int a[maxn+5];
vi e[maxn+5];
int in[maxn+5],out[maxn+5],tot,dep[maxn+5];
void dfs(int now,int fa)
{
    in[now] = ++tot;
    dep[now] = dep[fa]+1;
    for(auto v: e[now]) if(v!=fa) dfs(v,now);
    out[now] = tot;
}

int main()
{
    int n,q; scanf("%d%d",&n,&q);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    dfs(1,0);
    bit.init(n);
    while(q--)
    {
        int op; scanf("%d",&op);
        if(op==1)
        {
            int v,x; scanf("%d%d",&v,&x);
            bit.add(in[v],out[v],dep[v]&1?x:-x);
        }
        else
        {
            int v; scanf("%d",&v);
            int ans = bit.ask(in[v]);
            if(dep[v]%2==0) ans = -ans;
            printf("%d\n",a[v]+ans);
        }
    }
    return 0;
}