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
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int pf[10005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i,j;
    for (i=1;i<=n;i++)
    {
        pf[i-1]=i*i;
    }
    int sum=0;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=i;j++)
        {
            int x=i*i+j*j;
            if (pf[lower_bound(pf,pf+n,x)-pf]==x) sum++;
        }
    }
    printf("%d\n",sum);
    return 0;
}