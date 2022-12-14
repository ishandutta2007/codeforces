#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pr[20][20],two[31],dp[1<<20];

int main()
{
    int n;
    int S[20]={0};
    for(int i=0;i<31;i++)
    {
        two[i]=1<<i;
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        x--;
        for(int j=0;j<20;j++)
        {
            if(x!=j)pr[j][x]+=S[j];
        }
        S[x]++;
    }

    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<two[20];i++)
    {
        for(int j=0;j<20;j++)
        {
            if(!(two[j]&i))
            {
                ll t=dp[i];
                for(int k=0;k<20;k++)
                {
                    if(two[k]&i)t+=pr[j][k];
                }
                dp[two[j]|i]=min(dp[two[j]|i],t);
            }
        }
    }
    printf("%lld",dp[two[20]-1]);
    return 0;
}