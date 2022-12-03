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
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    if (n%2==0)
    {
        printf("-1\n");
        return 0;
    }
    for (i=0;i<n;i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    for (i=1;i<n;i++)
    {
        printf("%d ",i);
    }
    printf("0 \n");
    for (i=0;i<n-1;i++)
    {
        printf("%d ",(i+(i+1))%n);
    }
    printf("%d \n",n-1);
    return 0;
}