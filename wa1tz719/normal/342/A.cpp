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
int a[15];
int b[15];
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
        a[x]++;
        b[x]++;
        if ((x==5)||(x==7))
        {
            printf("-1\n");
            return 0;
        }
    }
    for (i=0;i<a[3];i++)
    {
        b[1]--;
        b[3]--;
        b[6]--;
    }
    for (i=0;i<a[4];i++)
    {
        b[1]--;
        b[2]--;
        b[4]--;
    }
    for (i=0;i<a[6]-a[3];i++)
    {
        b[1]--;
        b[2]--;
        b[6]--;
    }
    for (i=1;i<=6;i++)
    {
        if (b[i]!=0)
        {
            printf("-1\n");
            return 0;
        }
    }
    for (i=0;i<a[3];i++)
    {
        printf("1 3 6\n");
    }
    for (i=0;i<a[4];i++)
    {
        printf("1 2 4\n");
    }
    for (i=0;i<a[6]-a[3];i++)
    {
        printf("1 2 6\n");
    }
    return 0;
}