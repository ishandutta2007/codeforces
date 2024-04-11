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
int a[2005];
int sum[10005];
int tot[10005];
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
    int j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (a[i]<=a[j]) continue;
            sum[a[i]-a[j]]++;
        }
    }
    tot[0]=0;
    for (i=1;i<=10000;i++)
    {
        tot[i]=tot[i-1]+sum[i];
    }
    long long ans=0;
    for (i=1;i<=5000;i++)
    {
        int j;
        for (j=1;j<=5000;j++)
        {
            ans+=(long long)sum[i]*sum[j]*tot[i+j];
        }
    }
    printf("%.12lf\n",((long long)tot[5000]*tot[5000]*tot[5000]-ans)*1.0/tot[5000]/tot[5000]/tot[5000]);
    return 0;
}