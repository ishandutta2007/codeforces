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

const int maxn = 400;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

struct P
{
    ll x,y;
    P(){}
    P(ll x,ll y): x(x),y(y) {}
    void in() {scanf("%lld%lld",&x,&y);}
    P operator -(const P &a) const {return P(x-a.x,y-a.y);}
    ll cross(const P &a) const {return x*a.y-y*a.x;}
};
P a[maxn+5];

pair<int,ll> dp[maxn+5][maxn+5];

bool solve(int n,int k,ll S)
{
    rep(len,2,n) rep(l,1,n)
    {
        int r=l+len;
        dp[l][r]={0,0ll};
        rep(i,l+1,r-1)
        {
            ll sum = dp[l][i].SE + dp[i][r].SE + (a[r]-a[i]).cross(a[l]-a[i]);
            pair<int,ll> tmp = {dp[l][i].FI+dp[i][r].FI,sum};
            if(sum>=S) tmp = {tmp.FI+1,0};
            chmax(dp[l][r],tmp);
        }
    }
    rep(i,1,n) if(dp[i][i+n].FI>=k+1) return 1;
    return 0;
}

int main()
{
    int n,k; scanf("%d%d",&n,&k);
    rep(i,1,n) a[i].in();
    rep(i,1,n) a[i+n]=a[i];
    ll l=0,r=1ll<<60;
    debug(r);
    while(l<r)
    {
        auto mid=(l+r)>>1;
        if(solve(n,k,mid)) l=mid+1;
        else r=mid;
    }
    printf("%lld\n",l-1);
    return 0;
}