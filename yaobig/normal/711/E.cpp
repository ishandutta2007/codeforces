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

const int maxn = 2000;
const int mod = 1000003;
const int inf = 0x3f3f3f3f;

ll qp(ll a,ll k)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%mod) if(k&1) res = res*a%mod;
    return res;
}

int main()
{
    ll n,k; scanf("%lld%lld",&n,&k);
    if(n<=60 && k>1ll<<n) return puts("1 1"),0;
    ll N = qp(2,n), p = 1, q = qp(N,k-1);
    rep(i,1,k-1) 
    {
        p = p*(N-i)%mod;
        if(p==0) break;
    }
    ll pw = 0, x = k-1;
    while(x)
    {
        pw += x/2;
        x /= 2;
    }
    ll g = qp(2,pw);
    p = p*qp(g,mod-2)%mod;
    q = q*qp(g,mod-2)%mod;
    printf("%lld %lld\n",(q-p+mod)%mod,q);
    return 0;
}