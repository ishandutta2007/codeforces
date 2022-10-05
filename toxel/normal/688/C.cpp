#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N (100001)
typedef struct edge
{
	int to,next;
};
typedef struct point
{
	int first,color;
};
int e=0,n,m,u[N],v[N],queue[N],head=0,tail=-1,length=0,a=0,b=0;
edge edg[2*N];
point poi[N];
void addedge(int u,int v)
{
	edg[++e].to=v;
	edg[e].next=poi[u].first;
	poi[u].first=e;
	edg[++e].to=u;
	edg[e].next=poi[v].first;
	poi[v].first=e;
}
bool bfs()
{
	int i,j,col=1;
	for (i=1;i<=n;i++)
	{
		if (!poi[i].color)
		{
			poi[i].color=1;
			tail=(tail+1)%N;
			length++;
			queue[tail]=i;
			while (length)
			{
				for(j=poi[queue[head]].first;j;j=edg[j].next)
					if (!poi[edg[j].to].color)
					{
						poi[edg[j].to].color=poi[queue[head]].color%2+1;
						tail=(tail+1)%N;
						length++;
						queue[tail]=edg[j].to;
					}
					else
						if (poi[edg[j].to].color==poi[queue[head]].color)
							return false;
				head=(head+1)%N;
				length--;
			}
		}
	}
	return true;
}
int main()
{
	int i;
	scanf("%d%d",&n,&m);
	memset(edg,0,2*N*sizeof(edge));
	memset(poi,0,N*sizeof(point));
	for (i=0;i<m;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		addedge(u[i],v[i]);
	}
	if(bfs())
	{
		for (i=1;i<=n;i++)
			if (poi[i].color==1)
				a++;
			else
				b++;
		printf("%d\n",a);
		for (i=1;i<=n;i++)
			if (poi[i].color==1)
				printf("%d ",i);
		printf("\n%d\n",b);
		for (i=1;i<=n;i++)
			if (poi[i].color==2)
				printf("%d ",i);
	}
	else
		printf("-1");
	return 0;
}