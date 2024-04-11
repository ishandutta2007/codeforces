#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct edge
{
	int v,n;
}e[500005];
int head[300005],cnt;
inline void add(int u,int v)
{
	e[++cnt]={v,head[u]};
	head[u]=cnt;
}
queue <int> q;
int dis[300005],DIS[300005],p[300005];
vector <int> E[200005];
int main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin >> u >> v;
		add(v,u);
		E[u].push_back(v);
	}
	int s,t;
	int X;
	cin >> X;
	for(int i=1;i<=X;i++) cin >> p[i];
	s=p[1],t=p[X];
	for(int i=1;i<=n;i++) dis[i]=DIS[i]=1e9;
	q.push(s);
	dis[s]=0,DIS[t]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=e[i].n)
		{
			if(dis[e[i].v]>n)
			{
				dis[e[i].v]=dis[x]+1;
				q.push(e[i].v);
			}
		}
	}
	q.push(t);
	dis[s]=0,DIS[t]=0;
	while(!q.empty())
	{
		int x=q.front();
//		cout << x << endl;
		q.pop();
		for(int i=head[x];i;i=e[i].n)
		{
			if(DIS[e[i].v]>n)
			{
				DIS[e[i].v]=DIS[x]+1;
				q.push(e[i].v);
			}
		}
	}
	int ans1=0,ans2=0,now=dis[t];
	for(int i=2;i<=X;i++)
	{
		int mn=1e9,cnt=0;
		for(auto v:E[p[i-1]])
		{
//			cout << p[i-1] << "->" << v << endl;
			if(DIS[v]<mn) cnt=0,mn=DIS[v];
			if(DIS[v]==mn) ++cnt;
		}
//		cout << mn << " " << DIS[p[i]] << endl;
		if(DIS[p[i]]!=mn) ++ans1,++ans2;
		else if(cnt>1) ++ans2;
	}
	cout << ans1 << " " << ans2;
	return 0;
}