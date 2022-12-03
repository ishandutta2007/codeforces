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
    int n;
    scanf("%d",&n);
    int i;
    int cnt=0;
    for (i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        if (x<=cnt)
        {
            if (x==cnt)
            {
                cnt++;
            }
        }
        else
        {
            printf("%d\n",i+1);
            return 0;
        }
    }
    puts("-1");
    return 0;
}