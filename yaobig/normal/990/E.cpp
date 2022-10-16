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

const int maxn = 1000000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int a[maxn+5],ban[maxn+5];
int pre[maxn+5];

int main()
{
    int n,m,k; scanf("%d%d%d",&n,&m,&k);
    rep(i,1,m)
    {
        int x; scanf("%d",&x); ban[x+1] = 1;
    }
    rep(i,1,k) scanf("%d",&a[i]);
    rep(i,1,n) pre[i] = ban[i] ? pre[i-1] : i;

    if(pre[1]!=1) return puts("-1"),0;
    ll ans = 1ll<<60;
    rep(i,1,k) 
    {
        int now = 1;
        ll cost = 0;
        while(now<=n)
        {
            if(now-pre[now]>=i) {cost = 1ll<<60; break;}
            now = pre[now]+i;
            cost += a[i];
        }
        chmin(ans,cost);
    } 
    if(ans==1ll<<60) puts("-1");
    else printf("%lld\n",ans);
    return 0;
}