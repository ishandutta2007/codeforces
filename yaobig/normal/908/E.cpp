#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

char msk[55][maxn+5];
int dp[maxn+5],C[maxn+5][maxn+5];

int main()
{
    rep(i,0,maxn) C[i][0]=1;
    rep(i,1,maxn) rep(j,1,i) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod; 

    int m,n; scanf("%d%d",&m,&n);
    rep(i,0,n-1) scanf("%s",msk[i]+1);

    dp[0]=1;
    rep(i,1,m) rep(j,0,i-1) dp[i]=(dp[i]+1ll*C[i-1][j]*dp[i-1-j])%mod;
    map<ll,int> cnt;
    rep(i,1,m) 
    {
        ll x=0;
        rep(j,0,n-1) if(msk[j][i]=='1') x |= 1ll<<j;
        cnt[x]++;
    }
    ll ans=1;
    for(auto [x,c]: cnt) ans=ans*dp[c]%mod;
    printf("%lld\n",ans);
    return 0;
}