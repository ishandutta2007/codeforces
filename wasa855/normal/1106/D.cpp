#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int to;
	int nxt;
};
Edge edge[200005];
int fir[100005];
int ans[100005];
bool used[100005];
int ss;
void add(int u,int v)
{
	ss++;
	edge[ss].to=v;
	edge[ss].nxt=fir[u];
	fir[u]=ss;
	ss++;
	edge[ss].to=u;
	edge[ss].nxt=fir[v];
	fir[v]=ss;
}
int main()
{
	int n,m;
	cin>>n>>m;
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		add(u,v);
	}
	priority_queue<int,vector<int>,greater<int> > q;
	q.push(1);
	int k=0;
	used[1]=true;
	while(!q.empty())
	{
		ans[++k]=q.top();
		int x=q.top();
		q.pop();
		for(int i=fir[x];i!=0;i=edge[i].nxt)
		{
			int to=edge[i].to;
			if(used[to]==false)
			{
				q.push(to);
				used[to]=true;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
	cout<<"\n";
	return 0;
}