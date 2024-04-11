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
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int x,y,z,t1,t2,t3;
    scanf("%d%d%d%d%d%d",&x,&y,&z,&t1,&t2,&t3);
    long long time1=(abs(x-y)+abs(x-z))*t2+t3*3;
    long long time2=(abs(x-y))*t1;
    if (time1<=time2)
    {
        puts("YES");
    }
    else
    {
        puts("NO");
    }
    return 0;
}