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
int a[10005];
int n;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int sum=0;
    for (;;)
    {
        int num=0;
        for (i=0;i<n;i++)
        {
            if (a[i]>=num)
            {
                a[i]=-1;
                num++;
            }
        }
        for (i=0;i<n;i++)
        {
            if (a[i]!=-1) break;
        }
        sum++;
        if (i==n) break;
    }
    printf("%d\n",sum);
    return 0;
}