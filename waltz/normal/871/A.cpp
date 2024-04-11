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
    int q;
    scanf("%d",&q);
    int i;
    for (i=0;i<q;i++)
    {
        int n;
        scanf("%d",&n);
        int ans=0;
        if (n%2==1)
        {
            n-=9;
            ans++;
        }
        if (n==0)
        {
            printf("%d\n",ans);
            continue;
        }
        if (n<=3)
        {
            printf("-1\n");
            continue;
        }
        printf("%d\n",ans+n/4);
    }
    return 0;
}