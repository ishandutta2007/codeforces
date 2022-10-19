#include<bits/stdc++.h>
using namespace std;
const int N=200005,inf=1e9;
int n,m,a[N],d[N];
vector<int>e[N];
priority_queue<pair<int,int>>pq;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[v].push_back(u);
		d[u]++;
	}
	for(int i=1;i<=n;i++)
		a[i]=inf;
	a[n]=0;
	pq.emplace(0,n);
	while(pq.size())
	{
		int u=pq.top().second,ds=-pq.top().first;
		pq.pop();
		if(ds!=a[u])
			continue;
		for(auto v:e[u])
		{
			d[v]--;
			if(a[u]+d[v]+1<a[v])
			{
				a[v]=a[u]+d[v]+1;
				pq.emplace(-a[v],v);
			}
		}
	}
	printf("%d\n",a[1]);
	return 0;
}