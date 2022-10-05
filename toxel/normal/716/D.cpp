#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<climits> 
#define N 10010
using namespace std;
queue<long long>q;
typedef struct edge
{
	long long next,to;
	long long length;
	bool flag,era;
};
typedef struct point
{
	long long first,pre1,pre2;
	long long dis;
};
edge edg[2*N];
point poi[N];
long long e=0;
void addedge(long long u,long long v,long long length)
{
	edg[e].to=v;
	edg[e].length=length;
	edg[e].next=poi[u].first;
	poi[u].first=e++;
	edg[e].to=u;
	edg[e].length=length;
	edg[e].next=poi[v].first;
	poi[v].first=e++;
	if (!length)
	{
		edg[e-1].era=true;
		edg[e-2].era=true;
	}
	else
	{
		edg[e+1].era=false;
		edg[e-2].era=false;
	}
}
void bfs()
{
	long long i,j;
	while (!q.empty())
	{
		for (i=q.front(),q.pop(),j=poi[i].first;j!=-1;j=edg[j].next)
			if (poi[edg[j].to].dis>poi[i].dis+edg[j].length)
			{
				q.push(edg[j].to);
				poi[edg[j].to].dis=poi[i].dis+edg[j].length;
				poi[edg[j].to].pre1=i;
				poi[edg[j].to].pre2=j;
			}
	}
}
int main()
{
	long long n,m,s,t,i,u,v,L,length;
	scanf("%I64d%I64d%I64d%I64d%I64d",&n,&m,&L,&s,&t);
	for (i=0;i<n;i++)
		poi[i].first=-1;
	for (i=0;i<m;i++)
	{
		scanf("%I64d%I64d%I64d",&u,&v,&length);
		addedge(u,v,length);
	}
	for (i=0;i<2*m;i++)
		if (edg[i].era)
			edg[i].length=100000000000000000;
	for (i=0;i<n;i++)
	{
		q.push(i);
		poi[i].dis=100000000000000000;
	}
	poi[s].dis=0;
	bfs();
	if (poi[t].dis<L)
	{
		printf("NO\n");
		return 0;
	}
	if (poi[t].dis==L)
	{
		printf("YES\n");
		for (i=0;i<m;i++)
			printf("%I64d %I64d %I64d\n",edg[2*i+1].to,edg[2*i].to,edg[2*i].length);
		return 0;
	}
	for (i=0;i<2*m;i++)
		if (edg[i].era)
			edg[i].length=1;
	for (i=0;i<n;i++)
		poi[i].dis=100000000000000000;
	q.push(s);
	poi[s].dis=0;
	poi[s].pre1=-1;
	poi[s].pre2=-1;
	bfs();
	if (poi[t].dis>L)
	{
		printf("NO\n");
		return 0;
	}
	while (poi[t].dis!=L)
	{
		for (i=0;i<2*m;i++)
			edg[i].flag=false;
		i=t;
		while (poi[i].pre1!=-1)
		{
			edg[poi[i].pre2].flag=true;
			edg[poi[i].pre2^1].flag=true;
			i=poi[i].pre1;
		}
		i=t;
		while(!edg[poi[i].pre2].era)
			i=poi[i].pre1;
		edg[poi[i].pre2].length+=L-poi[t].dis;
		edg[poi[i].pre2^1].length+=L-poi[t].dis;
		for (i=0;i<2*m;i++)
			if (!edg[i].flag && edg[i].era)
			{
				edg[i].length=100000000000000000;
				edg[i^1].length=100000000000000000;
			}
		for (i=0;i<n;i++)
			poi[i].dis=100000000000000000;
		q.push(s);
		poi[s].dis=0;
		poi[s].pre1=-1;
		poi[s].pre2=-1;
		bfs();
	}
	/*if (poi[t].dis<L)
	{
		for (i=0;i<2*m;i++)
			if (edg[i].era)
				edg[i].length=100000000000000000;
		i=t;
		while (!edg[poi[i].pre2].era)
			i=poi[i].pre1;
		edg[poi[i].pre2].length=1+L-poi[t].dis;
		edg[poi[i].pre2^1].length=1+L-poi[t].dis;
		while (poi[i].pre1!=-1)
		{
			i=poi[i].pre1;
			if (edg[poi[i].pre2].era)
			{
				edg[poi[i].pre2].length=1;
				edg[poi[i].pre2^1].length=1;
			}
		}
	}*/
	printf("YES\n");
	for (i=0;i<m;i++)
		printf("%I64d %I64d %I64d\n",edg[2*i+1].to,edg[2*i].to,edg[2*i].length);
	return 0;
}