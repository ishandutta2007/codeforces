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
int ans[1005];
int a[1005];
int cnt=0;
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
    for (i=n-1;i>=1;i--)
    {
        a[i]-=a[i-1];
    }
    for (i=1;i<=n;i++)
    {
        int j;
        for (j=0;j<n;j++)
        {
            if (a[j]!=a[j%i])
            {
                break;
            }
        }
        if (j==n)
        {
            ans[cnt++]=i;
        }
    }
    printf("%d\n",cnt);
    for (i=0;i<cnt;i++)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}