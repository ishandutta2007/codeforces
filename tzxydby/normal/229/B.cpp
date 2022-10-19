#include<bits/stdc++.h>
using namespace std;
const int INF=2e9;
int d[100005];
vector<int>z[100005];
vector<pair<int,int>>edge[100005];
set<pair<long long,int>>qu;
int main()
{
	int n,m,from,to,w,x,u;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&from,&to,&w);
		edge[from].push_back(make_pair(to,w));
		edge[to].push_back(make_pair(from,w));
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for(int j=0;j<x;j++)
		{
			scanf("%d",&u);
			z[i].push_back(u);
		}
	}
	for(int i=1;i<=n;i++)
		d[i]=INF;
	d[1]=0;
	qu.insert(make_pair(0,1));
	while(!qu.empty())
	{
		int k=qu.begin()->second;
		qu.erase(qu.begin());
		long long cur=d[k];
		for(int i=0;i<z[k].size();i++)
			if(z[k][i]==cur)
				cur++;
		for(int i=0;i<edge[k].size();i++)
		{
			if(d[edge[k][i].first]>cur+edge[k][i].second)
			{
				qu.erase(make_pair(d[edge[k][i].first],edge[k][i].first));
				d[edge[k][i].first]=cur+edge[k][i].second;
				qu.insert(make_pair(d[edge[k][i].first],edge[k][i].first));
			}
		}
	}
	printf("%d\n",d[n]==INF?-1:d[n]);
	return 0;
}