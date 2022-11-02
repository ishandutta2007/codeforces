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
int father[300005];
int findroot(int x)
{
    int root=x;
    for (;father[root]!=-1;root=father[root]) ;
    int temp;
    for (;father[x]!=-1;)
    {
        temp=father[x];
        father[x]=root;
        x=temp;
    }
    return root;
}
void u(int x,int y)
{
    x=findroot(x);
    y=findroot(y);
    if (x==y) return;
    father[x]=y;
}
int ans[300005];
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
        ans[i]=-1;
    }
    father[n]=-1;
    for (i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x--;
        z--;
        int j;
        for (j=findroot(x);j<y;j=findroot(j))
        {
            if (j==z)
            {
                j++;
                continue;
            }
            ans[j]=z;
            u(j,j+1);
        } 
    }
    for (i=0;i<n;i++)
    {
        printf("%d ",ans[i]+1);
    }
    printf("\n");
    return 0;
}