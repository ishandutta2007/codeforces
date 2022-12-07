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
void impossible()
{
    printf("IMPOSSIBLE\n");
    return;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    int x,y;
    int maxans=0;
    scanf("%d%d",&x,&y);
    maxans=x+y-1;
    for (i=1;i<m;i++)
    {
        int xx,yy;
        scanf("%d%d",&xx,&yy);
        int t=xx-x;
        if (y>yy)
        {
            if (y-yy>t)
            {
                impossible();
                return 0;
            }
            maxans=max(maxans,y+(xx-x-(y-yy))/2);
        }
        else
        {
            if (yy-y>t)
            {
                impossible();
                return 0;
            }
            maxans=max(maxans,yy+(xx-x-(yy-y))/2);
        }
        x=xx;
        y=yy;
    }
    maxans=max(maxans,(n-x)+y);
    printf("%d\n",maxans);
    return 0;
}