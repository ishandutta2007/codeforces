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
int a[10005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    int cnt=1;
    for (i=0;i<n;i++)
    {
        int x,y,z,w;
        scanf("%d%d%d%d",&x,&y,&z,&w);
        int sum=x+y+z+w;
        a[i]=sum;
        if (a[i]>a[0]) cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}