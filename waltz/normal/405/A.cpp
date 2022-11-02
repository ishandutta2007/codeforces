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
int a[105],b[105];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    int i;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        int j;
        for (j=0;j<x;j++)
        {
            a[j]++;
        }
    }
    for (i=0;i<100;i++)
    {
        int j;
        for (j=0;j<a[i];j++)
        {
            b[j]++;
        }
    }
    for (i=n-1;i>=0;i--)
    {
        printf("%d ",b[i]);
    }
    printf("\n");
    return 0;
}