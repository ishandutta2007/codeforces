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
int father[100005],size[100005];
int col[100005];
const int modo=1000000007;
int power(int x,int y)
{
    if (y==0) return 1;
    int t=power(x,y/2);
    t=(long long)t*t%modo;
    if (y%2==1) t=(long long)t*x%modo;
    return t;
}
int return_col;
int findroot(int x)
{
    int root=x;
    return_col=0;
    for (;father[root]!=-1;root=father[root]) return_col^=col[root];
    return root;
}
void u(int x,int y,int color)
{
    if (size[x]>size[y]) swap(x,y);
    father[x]=y;
    size[y]+=size[x];
    col[x]=color;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    for (i=0;i<n;i++)
    {
        father[i]=-1;
        size[i]=1;
        col[i]=1;
    }
    for (i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int t;
        scanf("%d",&t);
        t^=1;
        x--;
        y--;
        x=findroot(x);
        t^=return_col;
        y=findroot(y);
        t^=return_col;
        if (x==y)
        {
            if (t==1)
            {
                printf("0\n");
                return 0;
            }
            else
            {
                continue;
            }
        }
        u(x,y,t);
    }
    int sum=-1;
    for (i=0;i<n;i++)
    {
        if (father[i]==-1) sum++;
    }
    printf("%d\n",power(2,sum));
    return 0;
}