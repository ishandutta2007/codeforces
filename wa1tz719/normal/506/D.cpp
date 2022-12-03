#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<memory>
#include<bitset>
#include<vector>
#include<time.h>
#include<utility>
#include<fstream>
#include<sstream>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int x[100005],y[100005],col[100005];
set<pair<int,int> > s;
map<pair<int,int>,int> ma;
int size[200005];
int father[200005];
int findroot(int x)
{
    int root=x;
    for (;father[root]!=-1;root=father[root]) ;
    for (;father[x]!=-1;)
    {
        int temp=father[x];
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
    if (size[x]>size[y]) swap(x,y);
    father[x]=y;
    size[y]+=size[x];
}
map<int,bitset<512> > ma2[100005];
int number[200005];
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
        scanf("%d%d%d",&x[i],&y[i],&col[i]);
        x[i]--;
        y[i]--;
        s.insert(make_pair(x[i],col[i]));
        s.insert(make_pair(y[i],col[i]));
    }
    set<pair<int,int> >::iterator ii;
    int sum=0;
    for (ii=s.begin();ii!=s.end();ii++)
    {
        size[sum]=1;
        father[sum]=-1;
        ma[(*ii)]=sum++;
    }
    for (i=0;i<m;i++)
    {
        int xx=ma[make_pair(x[i],col[i])];
        int yy=ma[make_pair(y[i],col[i])];
        u(xx,yy);
    }
    int count=0;
    for (i=0;i<sum;i++)
    {
        if (father[i]==-1) number[i]=count++;
    }
    for (ii=s.begin();ii!=s.end();ii++)
    {
        int t=number[findroot(ma[(*ii)])];
        int x=(*ii).first;
        ma2[x][t>>9].set(t&511);
    }
    int q;
    scanf("%d",&q);
    for (i=0;i<q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int sol=0;
        x--;
        y--;
        if (ma2[x].size()>ma2[y].size()) swap(x,y);
        map<int,bitset<512> >::iterator jj;
        for (jj=ma2[x].begin();jj!=ma2[x].end();jj++)
        {
            int t=(*jj).first;
            if (ma2[y].find(t)==ma2[y].end()) continue;
            sol+=(((*jj).second)&(ma2[y][t])).count();
        }
        printf("%d\n",sol);
    }
    return 0;
}