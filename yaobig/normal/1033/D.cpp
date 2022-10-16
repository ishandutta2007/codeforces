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

const int maxn = 805;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

inline ll mul(ll a,ll b,ll c)
{ // using __int128 is a little bit slower
    ll s=a*b-c*ll((long double)a/c*b+0.5);
    return (s<0)?(s+c):s;
}
ll qp(ll a,ll k,ll M)
{
    ll res=1;
    for(;k;k>>=1,a=mul(a,a,M)) if(k&1) res=mul(res,a,M);
    return res;
}

bool test(ll n,int a)
{
    if(n==a) return 1;
    if(n%2==0) return 0;
    ll d = (n-1) >> __builtin_ctzll(n-1);
    ll r = qp(a,d,n);
    while(d<n-1 && r!=1 && r!=n-1) d<<=1, r=mul(r,r,n);
    return r==n-1 || d%2;
}
bool miller(ll n)
{
    if(n==2) return 1;
    vi b({2,3,5,7,11,13});
    for(auto p: b) if(test(n,p)==0) return 0;
    return 1;
}

mt19937_64 rng(20000902);
ll myrand(ll l,ll r) { return l + rng()%(r-l+1); }
ll pollard(ll n) // return some nontrivial factor of n.
{
    auto f = [&](ll x) { return (mul(x,x,n) + 1) % n; };
    ll x = 0, y = 0, t = 30, prd = 2;
    while(t++%40 || __gcd(prd, n)==1) 
    {   // speedup: don't take __gcd in each iteration.
        if(x==y) x = myrand(2,n-1), y = f(x);
        ll tmp = mul(prd, abs(x-y), n);
        if(tmp) prd = tmp;
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}

map<ll,int> M;

void factorization(ll n)
{
    if(n==1) return;
    if(miller(n)) M[n]++;
    else
    {
        ll x=pollard(n);
        factorization(x); factorization(n/x);
    }
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n)
    {
        ll x; scanf("%lld",&x);
        factorization(x);
    }
    int ans = 1;
    for(auto [x,c]: M) ans = 1ll*ans*(c+1)%mod;
    printf("%d\n",ans);
    return 0;
}