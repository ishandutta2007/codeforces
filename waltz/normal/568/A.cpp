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
int p[2000005];
int x[2000005];
int checks(int x)
{
    int wei=0;
    static int b[15];
    for (;x!=0;)
    {
        b[wei++]=x%10;
        x/=10;
    }
    int i;
    for (i=0;i<wei;i++)
    {
        if (b[i]!=b[wei-i-1]) return 0;
    }
    return 1;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int i;
    for (i=2;i<=2000000;i++)
    {
        p[i]=1;
    }
    x[1]=1;
    for (i=2;i<=2000000;i++)
    {
        if (p[i]==1)
        {
            int j;
            for (j=i+i;j<=2000000;j+=i)
            {
                p[j]=0;
            }
        }
        x[i]=checks(i);
    }
    int a,b;
    scanf("%d%d",&a,&b);
    int s=0,t=0;
    int ans;
    for (i=1;i<=2000000;i++)
    {
        s+=p[i];
        t+=x[i];
        if ((long long)s*b<=(long long)t*a) ans=i;
    }
    printf("%d\n",ans);
    return 0;
}