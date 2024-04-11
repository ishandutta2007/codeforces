#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int ans[1<<12][105];
int w[15];
int sum[1<<12];
int diff[1<<12];
int n,q,m;
int get_val()
{
    static char a[1005];
    scanf("%s",a);
    int i;
    int sum=0;
    for (i=0;a[i]!='\0';i++)
    {
        if (a[i]=='1')
        {
            sum+=(1<<i);
        }
    }
    return sum;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d%d%d",&n,&m,&q);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
    }
    for (i=0;i<m;i++)
    {
        int t=get_val();
        sum[t]++;
    }
    for (i=0;i<(1<<n);i++)
    {
        int j;
        int sum=0;
        for (j=0;j<n;j++)
        {
            if ((1<<j)&i) sum+=w[j];
        }
        diff[i]=sum;
    }
    for (i=0;i<(1<<n);i++)
    {
        int j;
        for (j=0;j<(1<<n);j++)
        {
            if (diff[i^j^((1<<n)-1)]>100) continue;
            ans[i][diff[i^j^((1<<n)-1)]]+=sum[j];
        }
    }
    for (i=0;i<q;i++)
    {
        int x=get_val();
        int y;
        scanf("%d",&y);
        int j;
        int sum=0;
        for (j=0;j<=y;j++)
        {
            sum+=ans[x][j];
        }
        printf("%d\n",sum);
    }
    return 0;
}