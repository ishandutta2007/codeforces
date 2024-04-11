#include<bits/stdc++.h>
using namespace std;
const int N=200005;
vector<int>e[N];
int n,m,k,a[N],dis[N],s[N],mi,ma;
queue<int>q;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[v].push_back(u);
	}
	memset(dis,-1,sizeof(dis));
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&a[i]);
	dis[a[k]]=0;
	q.push(a[k]);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto v:e[u])
		{
			if(dis[v]==-1)
			{
				dis[v]=dis[u]+1;
				q.push(v);
			}
			else if(dis[v]==dis[u]+1)
				s[v]++;
		}
	}
	for(int i=2;i<=k;i++)
	{
		if(dis[a[i]]!=dis[a[i-1]]-1)
			mi++;
		if(dis[a[i]]!=dis[a[i-1]]-1||s[a[i-1]])
			ma++;
	}
	printf("%d %d\n",mi,ma);
	return 0;
}