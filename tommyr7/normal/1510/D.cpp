#include <bits/stdc++.h>
using namespace std;
#define Maxn 100007
int n,d;
int a[Maxn];
__float128 dp[Maxn][10];
bool flag[Maxn][10],ans[Maxn];
int pre[Maxn][10];
int main()
{
    scanf("%d%d",&n,&d);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int j=0;j<=n;j++)
        for (int i=0;i<10;i++)
            dp[j][i]=-1000000000.0;
    dp[0][1]=0.0;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<10;j++)
            if (dp[i-1][j]>dp[i][j])
            {
                dp[i][j]=dp[i-1][j];
                flag[i][j]=false;
                pre[i][j]=j;
            }
        for (int j=0;j<10;j++)
        {
            int tmp=(j*a[i])%10;
            if (dp[i][tmp]<dp[i-1][j]+log(1.0*a[i]))
            {
                dp[i][tmp]=dp[i-1][j]+log(1.0*a[i]);
                flag[i][tmp]=true;
                pre[i][tmp]=j;
            }
        }
    }
    memset(ans,false,sizeof(ans));
    int now=d;
    int cnt=0;
    for (int i=n;i;i--)
    {
        if (flag[i][now]) ans[i]=true,++cnt;
        now=pre[i][now];
    }
    for (int i=1;i<=n;i++)
        if (a[i]%10==1&&(!ans[i]))
        {
            ans[i]=true;
            ++cnt;
        }
    int val=1;
    for (int i=1;i<=n;i++)
        if (ans[i]) val=(val*a[i])%10;
    if (val!=d||cnt==0) printf("%d\n",-1);
    else
    {
        printf("%d\n",cnt);
        for (int i=1;i<=n;i++)
            if (ans[i]) printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}