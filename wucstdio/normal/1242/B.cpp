#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
#define ll long long
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[200005];
int n,m,edgenum,head[100005];
set<int>s1,s2;
queue<int>q;
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void check(int node)
{
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(s1.find(to)!=s1.end())s2.insert(to);
	}
	for(set<int>::iterator it=s1.begin();it!=s1.end();it++)
	  if(s2.find(*it)==s2.end())
		q.push(*it);
	s1=s2;
	s2.clear();
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	int ans=0;
	for(int i=2;i<=n;i++)s1.insert(i);
	q.push(1);
	while(!s1.empty())
	{
		while(!q.empty())
		{
			int node=q.front();
			q.pop();
			check(node);
		}
		if(s1.empty())break;
		int node=*s1.begin();
		s1.erase(node);
		ans++;
		q.push(node);
	}
	printf("%d\n",ans);
	return 0;
}