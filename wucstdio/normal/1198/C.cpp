#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<ctime>
#include<cstdlib>
#define rand() (rand()*32768+rand())
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[1000005];
int t,n,m,edgenum,d[300005],head[300005],u[500005],v[500005],p[500005],pos[500005];
int ind[100005];
bool flag[300005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q,del;
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		edgenum=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=3*n;i++)d[i]=head[i]=flag[i]=0;
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
			d[u]++,d[v]++;
		}
		while(!q.empty())q.pop();
		while(!del.empty())del.pop();
		for(int i=1;i<=3*n;i++)q.push(make_pair(d[i],i));
		bool ff=1;
		for(int i=1;i<=n;i++)
		{
			int node;
			do
			{
				while(!q.empty()&&!del.empty()&&q.top()==del.top())
				{
					q.pop();
					del.pop();
				}
				if(q.empty())
				{
					ff=0;
					break;
				}
				node=q.top().second;
				q.pop();
			}
			while(ff&&flag[node]);
			if(!ff)break;
			flag[node]=1;
			ind[i]=node;
			for(int hd=head[node];hd;hd=e[hd].nxt)
			{
				int to=e[hd].to;
				if(flag[to])continue;
				flag[to]=1;
				for(int hd=head[to];hd;hd=e[hd].nxt)
				{
					int t=e[hd].to;
					if(flag[t])continue;
					del.push(make_pair(d[t],t));
					d[t]--;
					q.push(make_pair(d[t],t));
				}
			}
		}
		if(ff)
		{
			printf("IndSet\n");
			for(int i=1;i<=n;i++)printf("%d ",ind[i]);
			printf("\n");
			continue;
		}
		srand((unsigned)time(0));
		ff=0;
		for(int o=1;o<=10;o++)
		{
			for(int i=1;i<=3*n;i++)flag[i]=0;
			for(int i=1;i<=m;i++)p[i]=i;
			random_shuffle(p+1,p+m+1);
			for(int i=1;i<=edgenum;i+=2)
			{
				u[p[(i+1)/2]]=e[i].to;
				v[p[(i+1)/2]]=e[i+1].to;
			}
			int cnt=0;
			for(int i=1;i<=m;i++)
			{
				if(flag[u[i]]||flag[v[i]])continue;
				flag[u[i]]=flag[v[i]]=1;
				ind[++cnt]=i;
			}
			if(cnt>=n)
			{
				ff=1;
				break;
			}
		}
		if(!ff)while(1);
		for(int i=1;i<=m;i++)pos[p[i]]=i;
		printf("Matching\n");
		for(int i=1;i<=n;i++)printf("%d ",pos[ind[i]]);
		printf("\n");
	}
	return 0;
}