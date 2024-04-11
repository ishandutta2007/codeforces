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
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,k;
    scanf("%d%d",&n,&k);
    int i;
    int t=(n-1)/k;
    t*=2;
    if ((n-1)%k>=1) t++;
    if ((n-1)%k>=2) t++;
    printf("%d\n",t);
    int num=(n-1)/k;
    int sum=2;
    for (i=1;i<=k;i++)
    {
        int t=num;
        if ((n-1)%k>=i)
        {
            t++;
        }
        int j;
        printf("1 %d\n",sum);
        sum++; 
        for (j=1;j<t;j++)
        {
            printf("%d %d\n",sum-1,sum);
            sum++;
        }
    }
    return 0;
}