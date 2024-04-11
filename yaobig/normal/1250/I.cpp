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
using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 50;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

inline void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}
inline void chsub(int &x,int y) {x-=y; if(x<0) x+=mod;}

const int MAXM = 100000;

struct LinearSieve
{
    vi prime;
    bool np[MAXM+5];
    array<int,MAXM+5> mu;
    void init(int n)
    {
        mu[1]=1;
        prime.clear();
        rep(i,2,n)
        {
            if(np[i]==0)
            {
                prime.pb(i);
                mu[i]=-1;
            }
            for(auto p: prime)
            {
                ll v=1ll*i*p;
                if(v>n) break;
                np[v]=1;
                if(i%p==0)
                {
                    mu[v]=0;
                    break;
                }
                mu[v]=-mu[i];
            }
        }
    }
}sieve;

int l[maxn+5],r[maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d%d",&l[i],&r[i]);
    sieve.init(m);
    array<int,MAXM+5> &mu = sieve.mu;

    auto solve = [&](int d) {
        int M = m/d;
        static int C[maxn+5];
        rep(i,1,n)
        {
            int L = (l[i]+d-1)/d, R = r[i]/d;
            C[i] = R-L;
            M -= L;
        }
        if(M<0) return 0;
        static int A[MAXM+5];
        rep(i,0,M) A[i] = i==0;
        rep(i,1,n) if(C[i])
        {
            per(j,C[i]+1,M) chsub(A[j],A[j-C[i]-1]);
            rep(j,1,M) chadd(A[j],A[j-1]);
        }
        int ans = 0;
        rep(i,0,M) chadd(ans,A[i]);
        return ans;
    };
    int ans = 0;
    rep(i,1,m) if(mu[i])
    {
        int res = solve(i);
        if(mu[i]==1) chadd(ans,res);
        else chsub(ans,res);
    }
    printf("%d\n",ans);
    return 0;
}