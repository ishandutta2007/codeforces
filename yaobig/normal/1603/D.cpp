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

const int maxn = 100000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

struct LinearSieve
{
    vi prime;
    bool np[maxn+5];
    array<int,maxn+5> phi;
    void init(int n)
    {
        phi[1] = 1;
        prime.clear();
        rep(i,2,n)
        {
            if(np[i]==0)
            {
                prime.pb(i); 
                phi[i]=i-1;
            }
            for(auto p: prime)
            {
                ll v=1ll*i*p;
                if(v>n) break;
                np[v]=1;
                if(i%p==0)
                {
                    phi[v]=phi[i]*p;
                    break;
                }
                phi[v]=phi[i]*(p-1);
            }
        }
    }
}sieve;

ll ps[maxn+5];
ll dp[17][maxn+5];

void solve(int k,int l,int r,int L,int R)
{
    if(l>r) return;
    int mid = (l+r)>>1, pos = -1;
    ll res = 1ll<<60;
    auto cal = [](int L,int R) {
        ll res = 0;
        for(int l = L;l<=R;)
        {
            int num = R/l;
            int r = R/num;
            res += 1ll*(r-l+1)*ps[num];
            l = r + 1;
        }
        return res;
    };
    ll val = cal(L,mid);
    rep(i,L,min(mid,R))
    {
        if(chmin(res, dp[k-1][i-1] + val)) pos = i;
        val -= ps[mid/i];
    }
    if(pos==-1)
    {
        debug(k,l,r,mid,L,R);
        assert(0);
    }
    dp[k][mid] = res;
    solve(k,l,mid-1,L,pos);
    solve(k,mid+1,r,pos,R);
}

int main()
{
    sieve.init(maxn);
    array<int,maxn+5> &phi = sieve.phi;
    //debug(phi[maxn]);
    rep(i,1,maxn) ps[i] = ps[i-1] + phi[i];
    
    memset(dp,0x3f,sizeof dp); 
    dp[0][0] = 0;
    rep(k,1,16) solve(k,k,maxn,k,maxn);

    int cas; scanf("%d",&cas); while(cas--)
    {
        int n,k; scanf("%d%d",&n,&k);
        if(k>=17) printf("%d\n",n);
        else printf("%lld\n",dp[k][n]);
    }
    return 0;
}