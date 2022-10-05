#include <bits/stdc++.h>
using namespace std;
int ans[100005],a[100005],minn[100005][105],cnt,head[100005],n,m,s,k;
bool vis[100005];
struct lin
{
	int nxt,to,w;
}line[200005];
void add(int a,int b,int w)
{
	line[++cnt]=(lin){head[a],b,w};
	head[a]=cnt;
}
struct pt
{
	int pro,d,id,to;
	bool operator < (const pt &a) const
	{
		return d>a.d;
	}
};
priority_queue <pt> que; 
void bfs(int pro)
{
	for(int i=1;i<=n;i++)
		if(a[i]==pro) 
		{
			vis[i]=true;
			for(int j=head[i];j;j=line[j].nxt)
				if(!vis[line[j].to])
					que.push((pt){pro,1,i,line[j].to});
		}
	while(!que.empty())
	{
		pt now=que.top();
		que.pop();
		if(!vis[now.to])
		{
			minn[now.to][pro]=now.d;
			vis[now.to]=true;
			for(int j=head[now.to];j;j=line[j].nxt)
				if(!vis[line[j].to])
					que.push((pt){pro,now.d+line[j].w,now.to,line[j].to});
		}
		
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&s);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y,1);
		add(y,x,1);
	}
	for(int i=1;i<=k;i++)
	{
		memset(vis,0,sizeof(vis));
		while(!que.empty()) que.pop();
 		bfs(i);
	}
	for(int i=1;i<=n;i++)
	{ 
		sort(minn[i]+1,minn[i]+1+k);
		for(int j=1;j<=s;j++)
			ans[i]+=minn[i][j];
		printf("%d ",ans[i]);
	}
	return 0;
}