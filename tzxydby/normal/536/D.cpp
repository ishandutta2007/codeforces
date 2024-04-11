#include<bits/stdc++.h>
using namespace std;
#define INF (1ll<<60)
const int N=2005;
int n,m,s,t,used[N],new_s[N][N],new_t[N][N],ranks[N],rankt[N];
long long graph[N][N],p[N],dist[N],dists[N],distt[N],dps[N][N],dpt[N][N];
vector<pair<long long,long long>>vs,vt;
long long calc_s(int x,int y)
{
	if(x==n)
		return 0;
	if(!new_s[x][y])
		return dps[x+1][y];
	long long next_cost=p[vs[x].second];
	long long ans=next_cost+dps[x+1][y];
	for(int i=x+1;i<=n;i++)
	{
		ans=max(ans,next_cost-dpt[i][y]);
		if(new_s[i][y])
			break;
	}
	return ans;
}
long long calc_t(int x,int y)
{
	if(y==n)
		return 0;
	if(!new_t[x][y])
		return dpt[x][y+1];
	long long next_cost=p[vt[y].second];
	long long ans=next_cost+dpt[x][y+1];
	for(int i=y+1;i<=n;i++)
	{
		ans=max(ans,next_cost-dps[x][i]);
		if(new_t[x][i])
			break;
	}
	return ans;
}
void get_dist(int s)
{
	for(int i=0;i<n;i++)
		dist[i]=INF;
	for(int i=0;i<n;i++)
		used[i]=0;
	dist[s]=0;
	for(int i=0;i<n;i++)
	{
		int x=-1;
		for(int j=0;j<n;j++)
			if(!used[j]&&(x==-1||dist[j]<dist[x]))
				x=j;
		used[x]=1;
		for(int j=0;j<n;j++)
			dist[j]=min(dist[j],dist[x]+graph[x][j]);
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	s--;
	t--;
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		p[i]=tmp;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i!=j)
				graph[i][j]=INF;
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		u--;
		v--;
		graph[u][v]=min(graph[u][v],(long long)w);
		graph[v][u]=min(graph[v][u],(long long)w);
	}
	get_dist(s);
	for(int i=0;i<n;i++)
		dists[i]=dist[i];
	get_dist(t);
	for(int i=0;i<n;i++)
		distt[i]=dist[i];
	for(int i=0;i<n;i++)
		vs.push_back(make_pair(dists[i],i));
	sort(vs.begin(),vs.end());
	for(int i=0;i<n;i++)
		vt.push_back(make_pair(distt[i],i));
	sort(vt.begin(),vt.end());
	for(int i=0;i<n;i++)
		ranks[vs[i].second]=i;
	for(int i=0;i<n;i++)
		rankt[vt[i].second]=i;
	for(int i=0;i<n;i++)
		for(int j=0;j<=n;j++)
			new_s[i][j]=rankt[vs[i].second]>=j;
	for(int i=0;i<=n;i++)
		for(int j=0;j<n;j++)
			new_t[i][j]=ranks[vt[j].second]>=i;
	for(int i=n;i>=0;i--)
	{
		for(int j=n;j>=0;j--)
		{
			dps[i][j]=calc_s(i,j);
			dpt[i][j]=calc_t(i,j);
		}
	}
	long long ans=dps[0][0];
	if(ans>0)
		puts("Break a heart");
	if(ans==0)
		puts("Flowers");
	if(ans<0)
		puts("Cry");
	return 0;
}