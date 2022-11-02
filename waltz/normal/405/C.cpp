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
int now[1005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int i,n;
    scanf("%d",&n);
    int j;
    int nowans=0;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            int x;
            scanf("%d",&x);
            if (i==j) nowans^=x;
        }
    }
    int q;
    scanf("%d",&q);
    for (i=0;i<q;i++)
    {
        int oper,x;
        scanf("%d",&oper);
        if (oper!=3)
        {
            nowans^=1;
            scanf("%d",&x);
        }
        else printf("%d",nowans);
    }
    printf("\n");
    return 0;
}