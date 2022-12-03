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
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    for (i=1;;i++)
    {
        int x1=i/2;
        int x2=i/3;
        int x3=i/6;
        x1-=x3;
        x2-=x3;
        x1=min(x1,n);
        x2=min(x2,m);
        if (x1+x2+x3>=n+m)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}