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
template <typename A, typename B> string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}
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
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 100000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

const int MAXA = 20000000;
int cnt[MAXA+5];
ll dp[MAXA+5];

struct LinearSieve
{
    vi prime;
    int minp[MAXA+5];
    void init(int n)
    {
        rep(i,1,n) minp[i] = 0;
        prime.clear();
        rep(i,2,n)
        {
            if(minp[i]==0)
            {
                prime.pb(i);
                minp[i]=i;
            }
            for(auto p: prime)
            {
                ll v=1ll*i*p;
                if(v>n) break;
                minp[v]=p;
                if(i%p==0) break;
            }
        }
    }
}sieve;

int main()
{
    sieve.init(MAXA);
    vi pr = sieve.prime;

    int n; scanf("%d",&n);
    rep(i,1,n) {int x; scanf("%d",&x); cnt[x]++;}
    for(auto p: pr) 
    {
        per(j,1,MAXA/p) cnt[j] += cnt[j*p];
    }
    ll ans = 0;
    per(i,1,MAXA) 
    {
        dp[i] = 1ll*i*cnt[i];
        for(auto p: pr) if(1ll*i*p<=MAXA) chmax(dp[i],dp[i*p]+1ll*(cnt[i]-cnt[i*p])*i); else break;
        chmax(ans,dp[i]);
    }
    printf("%lld\n",ans);
    return 0;
}