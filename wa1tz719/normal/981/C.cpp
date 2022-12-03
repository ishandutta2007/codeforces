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
int deg[100005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        deg[x]++;
        deg[y]++;
    }
    int center_point=-1;
    int cnt=0;
    for (i=1;i<=n;i++)
    {
        if (deg[i]==1)
        {
            cnt++;
        }
        if (deg[i]>=3)
        {
            if (center_point!=-1)
            {
                puts("No");
                return 0;
            }
            center_point=i;
        }
    }
    puts("Yes");
    if (center_point==-1)
    {
        puts("1");
        for (i=1;i<=n;i++)
        {
            if (deg[i]==1)
            {
                printf("%d ",i);
            }
        }
    }
    else
    {
        printf("%d\n",cnt);
        for (i=1;i<=n;i++)
        {
            if (deg[i]==1)
            {
                printf("%d %d\n",i,center_point);
            }
        }
    }
    return 0;
}