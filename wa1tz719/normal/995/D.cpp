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
int a[1<<18];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,r;
    scanf("%d%d",&n,&r);
    int k=(1<<n);
    int i;
    long long sum=0;
    for (i=0;i<k;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    printf("%.12lf\n",sum*1.0/k);
    for (i=0;i<r;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        sum-=a[x];
        a[x]=y;
        sum+=y;
        printf("%.12lf\n",sum*1.0/k);
    }
    return 0;
}