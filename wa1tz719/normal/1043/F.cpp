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
int a[300005];
int dp[300005];
int cnt[300005];
int cnt2[300005];
vector<int> v[300005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    memset(dp,-1,sizeof(dp));
    for (i=2;i<=300000;i++)
    {
        if (v[i].size()==0)
        {
            v[i].push_back(i);
            int j;
            for (j=i+i;j<=300000;j+=i)
            {
                v[j].push_back(i);
            }
        }
    }
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        dp[a[i]]=1;
    }
    for (i=1;i<=300000;i++)
    {
        int j;
        for (j=i;j<=300000;j+=i)
        {
            if (dp[j]==1)
            {
                cnt[i]++;
            }
        }
    }
    for (i=1;i<=300000;i++)
    {
        int j;
        for (j=0;j<(1<<v[i].size());j++)
        {
            int s=1;
            int k;
            int p=1;
            for (k=0;k<(int)v[i].size();k++)
            {
                if ((1<<k)&j)
                {
                    s=-s;
                }
                else
                {
                    p*=v[i][k];
                }
            }
            cnt2[i]+=cnt[p]*s;
        }
    }
    for (i=300000;i>=1;i--)
    {
        int j;
        for (j=i+i;j<=300000;j+=i)
        {
            if ((cnt2[j/i]!=0)&&(dp[j]!=-1))
            {
                if ((dp[i]==-1)||(dp[j]+1<dp[i]))
                {
                    dp[i]=dp[j]+1;
                }
            }
        }
    }
    printf("%d\n",dp[1]);
    return 0;
}