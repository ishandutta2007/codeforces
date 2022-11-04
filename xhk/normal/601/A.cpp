#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

struct edge
{int u,v,next;
};
struct edge e[200010];

int n,m,num,ans,inf=1e9;
int ga[510][510],p[510],q[1000010],used[510],dis[510];

void add(int u,int v)
{e[num].u=u;
 e[num].v=v;
 e[num].next=p[u];
 p[u]=num;
 num++;
 
 e[num].u=v;
 e[num].v=u;
 e[num].next=p[v];
 p[v]=num;
 num++;
}

void spfa()
{int i,j,t,w;
 
 for(i=2;i<=n;i++)
    dis[i]=inf;
 dis[1]=0;  
 
 t=1;
 w=1;
 q[t]=1;
 while(t<=w)
 {  j=p[q[t]];
    while(j!=-1)
    {   if(dis[q[t]]+1<dis[e[j].v])
        {   dis[e[j].v]=dis[q[t]]+1;
            if(used[e[j].v]==0)
            {   used[e[j].v]=1;
                w++;
                q[w]=e[j].v;
            }
        }
        j=e[j].next;
    }
    t++;
 }
}

int main()
{int i,j,x,y,flag=0;
 
 scanf("%d%d",&n,&m);

 for(j=1;j<=m;j++)
 {  scanf("%d%d",&x,&y);
    ga[x][y]=1;
    ga[y][x]=1;
 }
 
 memset(p,-1,sizeof(p));
 
 if(ga[1][n]==1) flag=1;
 
 for(i=1;i<=n;i++)
    for(j=i+1;j<=n;j++)
        if(flag==1 && ga[i][j]==0)
            add(i,j);
        else if(flag==0 && ga[i][j]==1)
            add(i,j);
            
 spfa();
 ans=max(1,dis[n]);
 
 if(ans!=inf)
    printf("%d\n",ans);
 else
    printf("-1\n"); 
 
 return 0;
}