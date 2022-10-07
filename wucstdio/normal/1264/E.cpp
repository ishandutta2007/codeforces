#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
struct Edge
{
	int to;
	int nxt;
	int cost;
	int flow;
}e[1000005];
int n,m,s,t,edgenum=-1,tot;
int a[55][55],dis[10005],p1[10005],p2[10005],head[10005],d[55],res[55][55];
bool flag[10005];
queue<int>q;
void add(int u,int v,int c,int f)
{
	e[++edgenum].cost=c;
	e[edgenum].flow=f;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int bfs()
{
    memset(dis,0x3f,sizeof(dis));
    q.push(s);
	dis[s]=0;
	flag[s]=1;
    while(!q.empty())
    {
    	int node=q.front();
    	q.pop();
		flag[node]=0;
        for(int hd=head[node];hd!=-1;hd=e[hd].nxt)
        {
        	int to=e[hd].to;
            if(dis[to]>dis[node]+e[hd].cost&&e[hd].flow)
            {
                dis[to]=dis[node]+e[hd].cost,p1[to]=hd,p2[to]=node;
                if(!flag[to])
				{
					flag[to]=1;
					q.push(to);
				}
            }
        }
    }
    return dis[t]<1000000000;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
		if(j!=i)a[i][j]=2;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		a[u][v]=1;
		a[v][u]=0;
	}
    s=0,t=tot=n+1;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>=j) continue;
            if(a[i][j]==2)
			{
				res[i][j]=edgenum+4;
				add(s,++tot,0,1);
				add(tot,s,0,0);
				add(tot,i,0,1);
				add(i,tot,0,0);
				add(tot,j,0,1);
				add(j,tot,0,0);
				add(i,t,d[i],1);
				add(t,i,-d[i],0);
				add(j,t,d[j],1);
				add(t,j,-d[j],0);
				d[i]++;
				d[j]++;
			}
            if(a[i][j]==1)
			{
				res[i][j]=-1;
				add(s,i,0,1);
				add(i,s,0,0);
				add(i,t,d[i],1);
				add(t,i,-d[i],0);
				d[i]++;
			}
            if(a[i][j]==0)
			{
				res[i][j]=-2;
				add(s,j,0,1);
				add(j,s,0,0);
				add(j,t,d[j],1);
				add(t,j,-d[j],0);
				d[j]++;
			}
        }
    }
    while(bfs())
    {
        int minn=1<<30;
        for(int i=t;i!=s;i=p2[i])
		  minn=min(minn,e[p1[i]].flow);
        for(int i=t;i!=s;i=p2[i])
		  e[p1[i]].flow-=minn,e[p1[i]^1].flow+=minn;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>j)printf("%d",res[j][i]^1);
            else if(i==j)printf("0");
            else
            {
                if(res[i][j]==-1)res[i][j]=1;
                else if(res[i][j]==-2)res[i][j]=0;
                else res[i][j]=e[res[i][j]].flow;
                printf("%d",res[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}