#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int to;
	int dis;
	int nxt;
	int from;
};
Edge edge[100005];
int fir[100005];
int ss;
bool used[100005];
bool visit[100005];
int data[100005];
int n,m;
void add(int u,int v,int w)
{
	ss++;
	edge[ss].to=v;
	edge[ss].dis=w;
	edge[ss].from=u;
	edge[ss].nxt=fir[u];
	fir[u]=ss;
}
bool dfs(int now,int x)
{
	used[now]=true;
	visit[now]=true;
	for(int i=fir[now];i!=0;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(edge[i].dis<=x)
		{
			continue;
		}
		if(visit[to]==true||dfs(to,x)==false)
		{
			return false;
		}
	}
	visit[now]=false;
	return true;
}
bool judge(int x)
{
	memset(used,false,sizeof(used));
	memset(visit,false,sizeof(visit));
	for(int i=1;i<=n;i++)
	{
		if(used[i]==false)
		{
			if(dfs(i,x)==false)
			{
				return false;
			}
		}
	}
	return true;
}
int cnt;
int dgr[100005];
int main()
{
	cin>>n>>m;
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		add(u,v,w);
	}
	int l=0,r=0x3fffffff;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(judge(mid)==true)
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(edge[i].dis>r)
		{
			dgr[edge[i].to]++; 
		}
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(dgr[i]==0)
		{
			q.push(i);
			data[i]=++cnt;
		}
	}
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		for(int i=fir[t];i!=0;i=edge[i].nxt)
		{
			int to=edge[i].to;
			if(edge[i].dis<=r)
			{
				continue;
			}
			dgr[to]--;
			if(dgr[to]==0)
			{
				data[to]=++cnt;
				q.push(to);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(data[i]==0)
		{
			data[i]=++cnt;
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		if(edge[i].dis<=r)
		{
			if(data[edge[i].from]>data[edge[i].to])
			{
				ans++;
			}
		}
	}
	cout<<r<<" "<<ans<<endl;
	for(int i=1;i<=m;i++)
	{
		if(edge[i].dis<=r)
		{
			if(data[edge[i].from]>data[edge[i].to])
			{
				printf("%d ",i);
			}
		}
	}
	cout<<"\n";
	return 0;
}