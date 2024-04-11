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

const int maxn = 4000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

ll a[maxn+5];
ll dp[maxn+5][maxn+5];

int solve(int l,int r,int m)
{
    if(l>r) return 0;
    ll mn=a[l];
    int mid=l;
    rep(i,l+1,r) if(chmin(mn,a[i])) mid=i;
    int ls=solve(l,mid-1,m);
    int rs=solve(mid+1,r,m);
    int L=mid-l,R=r-mid;
    rep(x,0,L) rep(y,0,R) 
    {
        ll tmp=dp[ls][x]+dp[rs][y]+1ll*x*(m-x)*(a[ls]-a[mid])+1ll*y*(m-y)*(a[rs]-a[mid]);
        chmax(dp[mid][x+y],tmp);
        chmax(dp[mid][x+y+1],tmp);
    }
    //rep(i,0,L+R+1) debug(mid, i, dp[mid][i]);
    return mid;
}

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%lld",&a[i]);
    printf("%lld\n",dp[solve(1,n,m)][m]);
    return 0;
}