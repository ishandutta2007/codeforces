#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 14
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

char str[maxn+5][maxn+5];
vector<ll> dp[1<<maxn][maxn];

int main()
{
    int n; scanf("%d",&n);
    rep(i,0,n-1) scanf("%s",str[i]);
    int N=1<<n;
    rep(msk,1,N-1) rep(i,0,n-1) if(msk&(1<<i)) dp[msk][i]=vector<ll>(1<<(__builtin_popcount(msk)-1),0);
    rep(i,0,n-1) dp[1<<i][i][0]=1;
    rep(msk,1,N-1) rep(i,0,n-1) if(msk&(1<<i))
    {
        int B=1<<(__builtin_popcount(msk)-1);
        rep(s,0,B-1) if(dp[msk][i][s])
        {
            rep(j,0,n-1) if((msk&(1<<j))==0) dp[msk^(1<<j)][j][s*2+(str[i][j]=='1')]+=dp[msk][i][s];
        }
    }
    vector<ll> ans(1<<(n-1),0);
    int B=1<<(n-1);
    rep(i,0,n-1) rep(s,0,B-1) ans[s]+=dp[N-1][i][s];
    rep(s,0,B-1) printf("%lld%c",ans[s]," \n"[s==B-1]);
    return 0;
}