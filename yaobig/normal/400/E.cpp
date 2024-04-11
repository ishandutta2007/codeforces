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

const int maxn = 100000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

auto binom2(int x)
{
    x++;
    return 1ll*x*(x-1)/2;
}

struct node
{
    set<int> S;
    void init(int n)
    {
        S.insert(0);
        S.insert(n+1);
    }
    ll insert(int x)
    {
        auto l = *--S.lower_bound(x);
        auto r = *S.lower_bound(x);
        S.insert(x);
        return binom2(r-l-1) - binom2(x-l-1) - binom2(r-x-1);
    }
    ll erase(int x)
    {
        S.erase(x);
        auto l = *--S.lower_bound(x);
        auto r = *S.lower_bound(x);
        return binom2(r-l-1) - binom2(x-l-1) - binom2(r-x-1);
    }
}L[17];

int a[maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,0,16) L[i].init(n);
    ll ans = 0;
    rep(i,0,16) ans += binom2(n)<<i;
    rep(i,1,n) rep(j,0,16) if((a[i]>>j&1)==0) ans -= L[j].insert(i)<<j;
    while(m--)
    {
        int p,v; scanf("%d%d",&p,&v);
        rep(j,0,16) 
        {
            if((a[p]>>j&1)==0 && v>>j&1) ans += L[j].erase(p)<<j;
            if(a[p]>>j&1 && (v>>j&1)==0) ans -= L[j].insert(p)<<j;
        }
        a[p] = v;
        printf("%lld\n",ans);
    }
    return 0;
}