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
bool dp[35][65][2005];
bool last[35][65][2005];
int a[35];
int b[65];
int res[65][65];
void dfs(int n,int k,int j)
{
    if (k==0) return;
    b[k-1]=a[n-1];
    if (last[n][k][j]==1)
    {
        dfs(n-1,k-1,j-a[n-1]);
    }
    else
    {
        dfs(n,k-1,j-a[n-1]);
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    dp[0][0][0]=true;
    for (i=1;i<=n;i++)
    {
        int j;
        int k;
        for (k=i;k<=61;k++)
        {
            for (j=k*(k-1)/2;j<=60*61/2;j++)
            {
                if (j<a[i-1]) continue;
                if (dp[i-1][k-1][j-a[i-1]])
                {
                    dp[i][k][j]=true;
                    last[i][k][j]=1;
                }
                if (dp[i][k-1][j-a[i-1]])
                {
                    dp[i][k][j]=true;
                    last[i][k][j]=0;
                }
            }
        }
    }
    int ans;
    for (ans=0;;)
    {
        if (ans>=61)
        {
            puts("=(");
            return 0;
        }
        ans++;
        if (dp[n][ans][ans*(ans-1)/2]) break;
    }
    printf("%d\n",ans);
    dfs(n,ans,ans*(ans-1)/2);
    memset(res,-1,sizeof(res));
    for (i=0;i<ans;i++)
    {
        res[i][i]=0;
    }
    for (i=0;i<ans;i++)
    {
        int j;
        int mins=ans+1,min_id=-1;
        for (j=0;j<ans;j++)
        {
            if (b[j]<mins)
            {
                mins=b[j];
                min_id=j;
            }
        }
        j=min_id;
        int k;
        for (k=0;k<b[j];k++)
        {
            int l;
            int min2=ans+1,min2_id=-1;
            for (l=0;l<ans;l++)
            {
                if (res[j][l]!=-1) continue;
                if (j==l) continue;
                if (b[l]<min2)
                {
                    min2=b[l];
                    min2_id=l;
                }
            }
            res[j][min2_id]=1;
            res[min2_id][j]=0;
        }
        for (k=0;k<ans;k++)
        {
            if (res[j][k]!=-1) continue;
            res[j][k]=0;
            res[k][j]=1;
            b[k]--;
        }
        b[j]=ans+1;
    }
    for (i=0;i<ans;i++)
    {
        int j;
        for (j=0;j<ans;j++)
        {
            printf("%d",res[i][j]);
        }
        printf("\n");
    }
    return 0;
}