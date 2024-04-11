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
int fa[1000005];
int size[400005];
int findroot(int x)
{
    int root;
    for (root=x;fa[root]!=-1;root=fa[root]) ;
    int temp;
    for (;fa[x]!=-1;)
    {
        temp=fa[x];
        fa[x]=root;
        x=temp;
    }
    return root;
}
void u(int x,int y)
{
    x=findroot(x);
    y=findroot(y);
    if (x==y) return;
    if (size[x]>size[y]) swap(x,y);
    fa[x]=y;
    size[y]+=size[x];
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    scanf("%d%d",&n,&m);
    int q;
    scanf("%d",&q);
    int i;
    for (i=0;i<n+m;i++)
    {
        fa[i]=-1;
        size[i]=1;
    }
    for (i=0;i<q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        y--;
        u(x,y+n);
    }
    int sum=-1;
    for (i=0;i<n+m;i++)
    {
        if (fa[i]==-1) sum++;
    }
    printf("%d\n",sum);
    return 0;
}