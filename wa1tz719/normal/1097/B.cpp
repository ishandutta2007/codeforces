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
int a[25];
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
    for (i=0;i<(1<<n);i++)
    {
        int j;
        int sum=0;
        for (j=0;j<n;j++)
        {
            if ((1<<j)&i)
            {
                sum+=a[j];
            }
            else
            {
                sum-=a[j];
            }
        }
        if (sum%360==0)
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}