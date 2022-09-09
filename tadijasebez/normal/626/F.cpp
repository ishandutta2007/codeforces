#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int mod=1e9+7;
const int N=205;
const int K=1005;
void add(int &x, int y){ x+=y;if(x>=mod) x-=mod;}
int a[N],dp[N][N][K];
int main()
{
    int n,k,i,j,l;
    scanf("%i %i",&n,&k);
    for(i=1;i<=n;i++) scanf("%i",&a[i]);
    sort(a+1,a+1+n);
    a[n+1]=a[n]+1;
    dp[1][0][0]=1;
    dp[1][1][0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            for(l=0;l<=k;l++)
            {
                if(!dp[i][j][l]) continue;
                int cost=l-j*a[i];
                cost+=a[i+1]*j;
                if(cost<=k)
                {
                    if(j!=0) add(dp[i+1][j][cost],(ll)dp[i][j][l]*j%mod);
                    add(dp[i+1][j][cost],dp[i][j][l]);;
                }
                if(cost<=k) add(dp[i+1][j+1][cost],dp[i][j][l]);
                if(!j) continue;
                if(cost<=k) add(dp[i+1][j-1][cost],(ll)dp[i][j][l]*j%mod);
            }
        }
    }
    int ans=0;
    for(i=0;i<=k;i++) add(ans,dp[n][0][i]);
    printf("%i\n",ans);
    return 0;
}