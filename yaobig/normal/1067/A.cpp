#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 100000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll dp[2][205][2];
ll sum[205][2];
int a[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,0,200) sum[i][0]=1;
    rep(i,1,n)
    {
        rep(j,1,200) dp[i&1][j][0]=0;
        rep(j,1,200) dp[i&1][j][1]=0;
        if(a[i]!=-1)
        {
            int x=a[i];
            dp[i&1][x][0]=(sum[x-1][0]+sum[x-1][1])%mod;
            dp[i&1][x][1]=(sum[200][1]-sum[x][1]+dp[i-1&1][x][0]+dp[i-1&1][x][1])%mod;
        }
        else
        {
            rep(x,1,200)
            {
                dp[i&1][x][0]=(sum[x-1][0]+sum[x-1][1])%mod;
                dp[i&1][x][1]=(sum[200][1]-sum[x][1]+dp[i-1&1][x][0]+dp[i-1&1][x][1]+mod)%mod;
            }
        }
        sum[0][0]=0;
        sum[0][1]=0;
        rep(j,1,200) sum[j][0]=(sum[j-1][0]+dp[i&1][j][0])%mod;
        rep(j,1,200) sum[j][1]=(sum[j-1][1]+dp[i&1][j][1])%mod;
    }
    printf("%I64d\n",sum[200][1]);
    return 0;
}