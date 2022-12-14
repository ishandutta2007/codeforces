#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=3e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

ll a[maxn],b[maxn],dp[maxn][3];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&a[i],&b[i]);
        }
        dp[0][0]=0;
        dp[0][1]=b[0];
        dp[0][2]=b[0]*2;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                dp[i][j]=linf;
                for(int k=0;k<3;k++)
                {
                    if(j+a[i]!=k+a[i-1])
                    {
                        dp[i][j]=min(dp[i][j],dp[i-1][k]);
                    }
                }
                dp[i][j]+=b[i]*j;
            }
        }
        ll ans=linf;
        for(int i=0;i<3;i++)
        {
            ans=min(ans,dp[n-1][i]);
        }
        printf("%lld\n",ans);
    }

	return 0;
}