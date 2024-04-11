#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int V=1200;
struct Point
{
    double x,y;
}P[V],C[V];
int bel[V],R[V];
double sqr(double x){return x*x;} 
double Dis(Point x,Point y)
{
    return sqr(x.x-y.x)+sqr(x.y-y.y);
}
struct Edge{int num,ne;}e[2100000];
int p[V],K;
void add(int x,int y)
{
//  printf("Add : %d %d\n",x,y);
    e[K].num=y;e[K].ne=p[x];p[x]=K++;
}
int pre[V],deep[V],vis[V],q[V];
int n,m;
void spfa()
{
    int i,j,k,top,tail;
    for(i=0;i<=m;i++)
    {
        deep[i]=0;
        vis[i]=0;
    }
    deep[0]=0;vis[0]=1;pre[0]=-1;
    top=0;tail=1;q[1]=0;
    while(top!=tail)
    {
        top=(top+1)%V;
        i=q[top];vis[i]=0;
        for(j=p[i];j!=-1;j=e[j].ne)
        {
            k=e[j].num;
            if(deep[k]-1<deep[i])
            {
                deep[k]=deep[i]+1;pre[k]=i;
                if(!vis[k])
                {
                    vis[k]=1;
                    tail=(tail+1)%V;
                    q[tail]=k;
                }
            }
        }
    }
}
int fa[V][22];
void lcainit()
{
    int i,j;
    for(i=0;i<=m;i++)fa[i][0]=pre[i];
    for(j=1;j<20;j++)
    for(i=0;i<=m;i++)
    {
        if(fa[i][j-1]==-1)fa[i][j]=-1;
        else fa[i][j]=fa[fa[i][j-1]][j-1];
    }
}
int LCA(int x,int y)
{
    if(deep[x]<deep[y])swap(x,y);
    int d=deep[x]-deep[y],t=0;
    while(d>0)
    {
        if(d&1)x=fa[x][t];
        t++;d/=2;
    }
    if(x==y)return x;
    for(int i=19;i>=0;i--)
    {
        if(fa[x][i]!=fa[y][i])
        x=fa[x][i],y=fa[y][i];
    }
    return fa[x][0];
}
int Q,i,j,x,y;
int main()
{
    while(~scanf("%d%d%d",&n,&m,&Q))
    {
        for(i=0;i<n;i++)
        cin>>P[i].x>>P[i].y;
        for(i=1;i<=m;i++)
        cin>>R[i]>>C[i].x>>C[i].y;
        for(i=0;i<=m;i++)p[i]=-1;K=0;
        for(i=1;i<=m;i++)
        {
            add(0,i);
            for(j=1;j<=m;j++)
            {
                if(i==j)continue;
                if(Dis(C[i],C[j])<sqr(R[i])&&R[i]>R[j])
                add(i,j);
            }
        }
        spfa();
        lcainit();
    //  for(i=0;i<=m;i++)printf("%d ",deep[i]);puts("");
        for(i=0;i<n;i++)
        {
            bel[i]=0;
            for(j=1;j<=m;j++)
            {
                if(Dis(P[i],C[j])<=sqr(R[j]))
                {
                    if(deep[bel[i]]<deep[j])
                    bel[i]=j;
                }
            }
        }
    //  for(i=0;i<n;i++)printf("%d ",bel[i]);puts("");
        while(Q--)
        {
            scanf("%d%d",&x,&y);x--;y--;
            x=bel[x];y=bel[y];
            int rt=LCA(x,y);
            printf("%d\n",deep[x]+deep[y]-2*deep[rt]);
        }
    }
}