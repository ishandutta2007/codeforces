#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5];
ll dp[maxn+5][3][2][2];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    if(n==1) return printf("%d\n",a[1]),0;
    memset(dp,0x80,sizeof dp);
    dp[0][0][0][0]=0;
    rep(i,0,n-1) rep(rem,0,2) rep(last,0,1) rep(ok,0,1) if(dp[i][rem][last][ok]>-1ll<<60)
    {
        rep(nlast,0,1)
        {
            int nok=ok || (i>0 && last==nlast);
            int nrem=(rem+(nlast==1)+1)%3;
            dp[i+1][nrem][nlast][nok]=max(dp[i+1][nrem][nlast][nok],dp[i][rem][last][ok]+(nlast?-a[i+1]:a[i+1]));
        }
    }
    printf("%lld\n",max(dp[n][1][0][1],dp[n][1][1][1]));
    return 0;
}