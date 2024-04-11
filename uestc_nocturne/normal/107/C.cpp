#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
LL dp[1<<17];
int ans[120],n,son[120];
int nu[1<<17];
LL Cal()
{
    for(int i=0;i<(1<<n);i++)dp[i]=0;
    dp[0]=1;
    for(int i=1;i<(1<<n);i++)
    for(int j=0;j<n;j++)
    if((i&(1<<j))==(1<<j)&&(son[j]&i)==son[j]&&(ans[j]==-1||ans[j]==n-nu[i]))
    dp[i]+=dp[i^(1<<j)];
    return dp[(1<<n)-1];
}
LL Y;
int m,i,j,k,less[120][120],x,y,vis[120];
int main()
{
    for(i=0;i<(1<<16);i++)
    for(nu[i]=0,j=i;j;j-=j&-j)nu[i]++;
    while(~scanf("%d%I64d%d",&n,&Y,&m))
    {
        Y-=2000;
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        less[i][j]=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            x--;y--;less[x][y]=1;
        }
        for(k=0;k<n;k++)
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if(less[i][k]&&less[k][j])
        less[i][j]=1;
        for(i=0;i<n;i++)
        {
            son[i]=0;
            for(j=0;j<n;j++)
            if(less[i][j])
            son[i]|=(1<<j);
        }
        for(i=0;i<n;i++)ans[i]=-1;
        if(Cal()<Y)
        {
            puts("The times have changed");
            continue;
        }
        for(i=0;i<n;i++)vis[i]=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(vis[j])continue;
                ans[i]=j;
                LL te=Cal();
                if(te>=Y)
                {
                    vis[j]=1;
                    break;
                }
                Y-=te;
            }
        }
        for(i=0;i<n;i++)
        {
            if(i)printf(" ");
            printf("%d",ans[i]+1);
        }puts("");
    }
}