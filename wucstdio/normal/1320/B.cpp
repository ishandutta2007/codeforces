#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[200005];
int n,m,s,t,edgenum,head[200005],dep[200005],a[200005];
bool flag[200005];
queue<int>q;
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void bfs()
{
	memset(dep,0x3f,sizeof(dep));
	q.push(t);
	dep[t]=0;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(dep[to]>dep[node]+1)
			{
				dep[to]=dep[node]+1;
				flag[to]=0;
				q.push(to);
			}
			else if(dep[to]==dep[node]+1)flag[to]=1;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(v,u);
	}
	int k;
	scanf("%d",&k);
	for(int i=1;i<=k;i++)scanf("%d",&a[i]);
	s=a[1],t=a[k];
	bfs();
	int ans1=0,ans2=0;
	for(int i=1;i<k;i++)
	{
		if(dep[a[i]]==dep[a[i+1]]+1)
		{
			if(flag[a[i]])ans2++;
		}
		else ans1++,ans2++;
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}