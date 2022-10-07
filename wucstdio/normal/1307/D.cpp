#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[400005];
int n,m,k,edgenum,head[200005],dep1[200005],depn[200005],sa1[200005],sa2[200005];
queue<int>q;
priority_queue<int>s,del;
bool flag[200005];
bool cmp1(int a,int b)
{
	return dep1[a]<dep1[b];
}
bool cmp2(int a,int b)
{
	return depn[a]<depn[b];
}
bool check(int mid)
{
	while(!s.empty()) s.pop();
	while(!del.empty()) del.pop();
	int j=n;
	for(int i=1;i<=n;i++)
	{
		if(!flag[sa2[i]])continue;
		del.push(depn[sa2[i]]);
		while(j&&depn[sa2[i]]+dep1[sa1[j]]>=mid)
		{
			if(flag[sa1[j]])s.push(depn[sa1[j]]);
			j--;
		}
		while(!s.empty()&&!del.empty()&&s.top()==del.top())
		{
			s.pop();
			del.pop();
		}
		if(!s.empty()&&s.top()+dep1[sa2[i]]>=mid)return 1;
		q.push(depn[sa2[i]]);
	}
	return 0;
}
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		int x;
		scanf("%d",&x);
		flag[x]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	q.push(1);
	dep1[1]=1;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(!dep1[to])
			{
				dep1[to]=dep1[node]+1;
				q.push(to);
			}
		}
	}
	q.push(n);
	depn[n]=1;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(!depn[to])
			{
				depn[to]=depn[node]+1;
				q.push(to);
			}
		}
	}
	for(int i=1;i<=n;i++)dep1[i]--,depn[i]--;
	for(int i=1;i<=n;i++)sa1[i]=sa2[i]=i;
	sort(sa1+1,sa1+n+1,cmp1);
	sort(sa2+1,sa2+n+1,cmp2);
	int l=1,r=dep1[n];
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid-1))l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",r);
	return 0;
}