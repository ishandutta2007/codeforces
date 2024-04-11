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
map<int,int> ma[100005];
int a[100005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    for (i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        y--;
        ma[x][y]=1;
        ma[y][x]=1;
    }
    srand(time(0));
    #ifdef RP
    for (;;) rp++;
    #endif
    for (i=0;i<n;i++)
    {
        a[i]=i;
    }
    for (i=0;i<10000;i++)
    {
        random_shuffle(a,a+n);
        int j;
        a[n]=a[0];
        for (j=0;j<m;j++)
        {
            if (ma[a[j]][a[j+1]]) break;
        }
        if (j==m)
        {
            for (j=0;j<m;j++)
            {
                printf("%d %d\n",a[j]+1,a[j+1]+1);
            }
            return 0;
        }
    }
    puts("-1");
    return 0;
}