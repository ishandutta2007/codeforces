#include<bits/stdc++.h>
#define maxn 200005 
using namespace std;
int n,m,k;
int a[maxn];
vector<int> g[maxn];
int dis1[maxn],dis2[maxn];
bool vis[maxn];
pair<int,int> A[maxn];
int pmax[maxn],smax[maxn];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;++i)scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	queue<int> q;
	q.push(1);dis1[1]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int v:g[u])
			if(!dis1[v])dis1[v]=dis1[u]+1,q.push(v);
	}
	q.push(n);dis2[n]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int v:g[u])
			if(!dis2[v])dis2[v]=dis2[u]+1,q.push(v); 
	}
	for(int i=1;i<=n;++i)dis1[i]--,dis2[i]--;
	for(int i=1;i<=k;++i)A[i]=make_pair(dis2[a[i]]-dis1[a[i]],a[i]);
	sort(A+1,A+k+1);
	for(int i=1;i<=k;++i)pmax[i]=max(pmax[i-1],dis2[A[i].second]);
	for(int i=k;i>=1;--i)smax[i]=max(smax[i+1],dis1[A[i].second]);
	int ans=0;
	for(int i=1;i<=k;++i)
	{
		if(i>1)ans=max(ans,dis1[A[i].second]+pmax[i-1]+1);
		if(i<k)ans=max(ans,dis2[A[i].second]+smax[i+1]+1);
	}
	ans=min(ans,dis1[n]);
	printf("%d\n",ans);
}