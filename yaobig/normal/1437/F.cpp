#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 5000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5],dp[maxn+5],cnt[maxn+5];
int downpw[maxn+5][maxn+5];

int main()
{
    rep(i,0,maxn)
    {
        downpw[i][0]=1;
        rep(j,1,i) downpw[i][j]=1ll*downpw[i][j-1]*(i-j+1)%mod;
    }

    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    rep(i,1,n) rep(j,1,i-1) cnt[i]+=a[j]*2<=a[i];
    if(cnt[n]!=n-1) return puts("0"),0;
    dp[0]=1; cnt[0]=-1;
    rep(i,1,n) rep(j,0,i-1) if(a[j]*2<=a[i]) dp[i]=(dp[i]+1ll*dp[j]*downpw[n-2-cnt[j]][cnt[i]-cnt[j]-1])%mod;
    printf("%d\n",dp[n]);
    return 0;
}