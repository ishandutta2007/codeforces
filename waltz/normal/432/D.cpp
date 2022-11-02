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
#include<sstream>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
char a[100005];
int d[100005];
int sum[100005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%s",a);
    memset(sum,0,sizeof(sum));
    int i;
    int n=strlen(a);
    int maxl=0,maxr=0;
    d[0]=n;
    for (i=1;i<n;i++)
    {
        int t=i-maxl;
        if (i>=maxr)
        {
            d[i]=0;
            for (;;)
            {
                if (a[i+d[i]]!=a[d[i]]) break;
                d[i]++;
            }
            if (i+d[i]>maxr)
            {
                maxl=i;
                maxr=i+d[i];
            }
        }
        else
        {
            d[i]=d[t];
            if (i+d[i]>=maxr) d[i]=maxr-i;
            for (;;)
            {
                if (a[i+d[i]]!=a[d[i]]) break;
                d[i]++;
            }
            if (i+d[i]>maxr)
            {
                maxl=i;
                maxr=i+d[i];
            }
        }
        //printf("%d ",d[i]);
    }
    int ans=0;
    for (i=0;i<n;i++)
    {
        sum[d[i]]++;
        if (d[n-i-1]>i)
        {
            ans++;
        }
    }
    printf("%d\n",ans);
    for (i=n;i>=0;i--)
    {
        sum[i]+=sum[i+1];
    }
    for (i=1;i<=n;i++)
    {
        if (d[n-i]>=i)
        {
            printf("%d %d\n",i,sum[i]);
        }
    }
    return 0;
}