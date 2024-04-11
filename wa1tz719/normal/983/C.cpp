#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int state[10005];
int erase_num[805][15];
int check_order(int x)
{
    static int d[5];
    int i;
    for (i=0;i<4;i++)
    {
        d[i]=x%10;
        x/=10;
    }
    sort(d,d+4);
    int sum=0;
    for (i=0;i<4;i++)
    {
        sum*=10;
        sum+=d[i];
    }
    return sum;
}
int get_erase(int x,int y)
{
    static int d[5];
    int i;
    for (i=0;i<4;i++)
    {
        d[i]=x%10;
        x/=10;
        if (d[i]==y) d[i]=0;
    }
    sort(d,d+4);
    int sum=0;
    for (i=0;i<4;i++)
    {
        sum*=10;
        sum+=d[i];
    }
    return sum;
}
int num[805];
int dp[2005][805][10];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int i;
    int cnt=0;
    for (i=0;i<10000;i++)
    {
        if (check_order(i)==i)
        {
            num[cnt]=i;
            state[i]=cnt++;
        }
        else
        {
            state[i]=state[check_order(i)];
        }
    }
    for (i=0;i<cnt;i++)
    {
        int j;
        for (j=1;j<10;j++)
        {
            erase_num[i][j]=state[get_erase(num[i],j)];
        }
    }
    int n;
    scanf("%d",&n);
    int ans=n*105;
    for (i=0;i<=2000;i++)
    {
        int j;
        for (j=0;j<=800;j++)
        {
            int k;
            for (k=0;k<=9;k++)
            {
                dp[i][j][k]=n*105;
            }
        }
    }
    dp[0][0][1]=0;
    for (i=0;i<=n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int j;
        for (j=cnt-1;j>=0;j--)
        {
            int k;
            static int que[105];
            static int vis[15];
            int front=0,rail=0;
            for (k=1;k<=9;k++)
            {
                if (erase_num[j][k]!=j) continue;
                if (dp[i][j][k]!=n*105)
                {
                    que[rail++]=k;
                    vis[k]=true;
                }
            }
            for (;front<rail;front++)
            {
                int now=que[front];
                vis[now]=false;
                if (now!=1)
                {
                    if ((erase_num[j][now-1]==j)&&(dp[i][erase_num[j][now-1]][now-1]>dp[i][j][now]+1)&&(!vis[now-1]))
                    {
                        vis[now-1]=true;
                        que[rail++]=now-1;
                    }
                    dp[i][erase_num[j][now-1]][now-1]=min(dp[i][erase_num[j][now-1]][now-1],dp[i][j][now]+1);
                }
                if (now!=9)
                {
                    if ((erase_num[j][now+1]==j)&&(dp[i][erase_num[j][now+1]][now+1]>dp[i][j][now]+1)&&(!vis[now+1]))
                    {
                        vis[now+1]=true;
                        que[rail++]=now+1;
                    }
                    dp[i][erase_num[j][now+1]][now+1]=min(dp[i][erase_num[j][now+1]][now+1],dp[i][j][now]+1);
                }
                if ((now==a)&&(num[j]<1000))
                {
                    dp[i+1][state[num[j]*10+b]][now]=min(dp[i+1][state[num[j]*10+b]][now],dp[i][j][now]);
                }
            }
        }
    }
    int j;
    for (j=1;j<=9;j++)
    {
        ans=min(ans,n*2+dp[n][0][j]);
    }
    printf("%d\n",ans);
    return 0;
}