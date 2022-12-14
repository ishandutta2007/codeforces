#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

int m=0,head[100100],to[200100],nxt[200100];

int a[100100],c[100100];
queue<int> que;

int an=0,ans[100100];

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	memset(head,-1,sizeof(head));
	for(int i=0;i<M;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		nxt[m]=head[u];head[u]=m;to[m]=v;m++;
		nxt[m]=head[v];head[v]=m;to[m]=u;m++;
	}
	for(int i=0;i<N;i++)
	{
		scanf("%d",a+i);
	}
	memset(c,0,sizeof(c));
	for(int i=0;i<N;i++)
	{
		if(a[i]==c[i]) que.push(i);
	}
	while(!que.empty())
	{
		int v=que.front();
		que.pop();
		c[v]++;
		ans[an]=v;
		an++;
		for(int e=head[v];e!=-1;e=nxt[e])
		{
			c[to[e]]++;
			if(c[to[e]]==a[to[e]]) que.push(to[e]);
		}
	}
	printf("%d\n",an);
	for(int i=0;i<an;i++)
	{
		printf("%d%c",ans[i]+1,i==an-1?'\n':' ');
	}
	return 0;
}