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
int a[10005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int i;
    int n;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        int r;
        scanf("%d",&r);
        int j;
        for (j=0;j<r;j++)
        {
            int x;
            scanf("%d",&x);
            a[x]++;
        }
    }
    for (i=1;i<=100;i++)
    {
        if (a[i]==n)
        {
            printf("%d ",i);
        }
    }
    return 0;
}