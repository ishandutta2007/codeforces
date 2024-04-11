#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
queue<int>q;
int n,m;
struct Graph
{
	struct Edge
	{
		int to;
		int nxt;
	}e[200005];
	int edgenum,head[200005],f[200005],d[200005];
	void add(int u,int v)
	{
		e[++edgenum].to=v;
		e[edgenum].nxt=head[u];
		d[v]++;
		head[u]=edgenum;
	}
	void solve()
	{
		for(int i=1;i<=n;i++)
		{
			f[i]=n+1;
			if(d[i]==0)q.push(i);
		}
		while(!q.empty())
		{
			int node=q.front();
			q.pop();
			f[node]=min(f[node],node);
			for(int hd=head[node];hd;hd=e[hd].nxt)
			{
				int to=e[hd].to;
				d[to]--;
				f[to]=min(f[to],f[node]);
				if(d[to]==0)q.push(to);
			}
		}
	}
};
Graph A,B;
int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		A.add(u,v);
		B.add(v,u);
	}
	A.solve();
	B.solve();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(A.d[i]||B.d[i])
		{
			printf("-1\n");
			return 0;
		}
		if(min(A.f[i],B.f[i])==i)ans++;
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	{
		if(min(A.f[i],B.f[i])==i)putchar('A');
		else putchar('E');
	}
	printf("\n");
	return 0;
}