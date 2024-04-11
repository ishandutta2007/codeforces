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
int a[1000005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    memset(a,0,sizeof(a));
    for (i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        a[x]=1;
    }
    printf("%d\n",n);
    int sum=0;
    for (i=1;i<=1000000;i++)
    {
        if (a[i]==1)
        {
            if (a[1000001-i]==0)
            {
                a[1000001-i]=2;
                printf("%d ",1000001-i);
                sum++;
            }
        }
    }
    for (i=1;i<=1000000;i++)
    {
        if (sum<n)
        {
            if ((a[i]==0)&&(a[1000001-i]==0))
            {
                printf("%d %d ",i,1000001-i);
                a[i]=3;
                a[1000001-i]=3;
                sum+=2;
            }
        }
    }
    printf("\n");
    return 0;
}