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
int a[5005];
int sum[5005];
int ans[5005][5005];
int maxs[5005][5005];
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
    sum[0]=0;
    for (i=0;i<n;i++)
    {
        sum[i+1]=sum[i]^a[i];
    }
    for (i=n-1;i>=0;i--)
    {
        int j;
        for (j=1;;j<<=1)
        {
            ans[i][j]=sum[i+j]^sum[i];
            int k;
            for (k=j+1;k<j+j;k++)
            {
                if (i+k>n) break;
                ans[i][k]=ans[i][k-j]^ans[i+j][k-j];
            }
            if (i+k>n) break;
        }
    }
    for (i=0;i<n;i++)
    {
        int j;
        for (j=1;i+j<=n;j++)
        {
            maxs[i][j]=max(maxs[i][j-1],ans[i][j]);
        }
    }
    int q;
    scanf("%d",&q);
    for (i=0;i<q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        l--;
        int max_ans=0;
        int i;
        for (i=l;i<r;i++)
        {
            int k=r-i;
            max_ans=max(max_ans,maxs[i][k]);
        }
        printf("%d\n",max_ans);
    }
    return 0;
}