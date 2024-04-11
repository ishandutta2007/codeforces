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
int visit1[1000005];
int visit2[1000005];
int route[1000005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int m;
    int h1,a1;
    int x1,y1;
    int h2,a2;
    int x2,y2;
    scanf("%d%d%d%d%d%d%d%d%d",&m,&h1,&a1,&x1,&y1,&h2,&a2,&x2,&y2);
    int i;
    memset(visit1,-1,sizeof(visit1));
    memset(visit2,-1,sizeof(visit2));
    int val1=0,val2=0;
    for (i=0;i<=m;i++)
    {
        if (visit1[h1]==-1)
        {
            visit1[h1]=i;
        }
        else
        {
            val1=i-visit1[h1];
            visit1[h1]=i;
        }
        if (visit2[h2]==-1)
        {
            visit2[h2]=i;
        }
        else
        {
            val2=i-visit2[h2];
            visit2[h2]=i;
        }
        if ((h1==a1)&&(h2==a2))
        {
            printf("%d\n",i);
            return 0;
        }
        h1=((long long)h1*x1+y1)%m;
        h2=((long long)h2*x2+y2)%m;
    }
    int sum=m+1;
    for (i=0;i<m;i++)
    {
        if (h1==a1)
        {
            break;
        }
        h1=((long long)h1*x1+y1)%m;
        h2=((long long)h2*x2+y2)%m;
    }
    sum+=i;
    if (i==m)
    {
        printf("-1\n");
        return 0;
    }
    for (i=0;i<val2;i++)
    {
        route[i]=h2;
        h2=((long long)h2*x2+y2)%m;
    }
    for (i=0;i<m;i++)
    {
        if (route[(long long)val1*i%val2]==a2)
        {
            cout<<(long long)val1*i+sum<<endl;
            return 0;
        }
    }
    if (i==m)
    {
        printf("-1\n");
    }
    return 0;
}