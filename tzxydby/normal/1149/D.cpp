#include<bits/stdc++.h>
using namespace std;
const int N=75,INF=0x3f3f3f3f;
struct UnionFind
{
	int parent[N],rnk[N];
	UnionFind(int n)
	{
		for(int i=0;i<=n;i++)
		{
			parent[i]=i;
			rnk[i]=1;
		}
	}
	int root(int x)
	{
		if(parent[x]!=x)
			parent[x]=root(parent[x]);
		return parent[x];
	}
	void connect(int x,int y)
	{
		int rx=root(x),ry=root(y);
		if(rx==ry)
			return;
		if(rx>ry)
		{
			parent[ry]=rx;
			rnk[rx]+=rnk[ry];	
		} 
		if(rx<=ry)
		{
			parent[rx]=ry;
			rnk[ry]+=rnk[rx];
		}
	}
};
UnionFind uf(70);
int n,m,a,b,s,r[N];
vector<pair<int,int>>e[N];
struct node
{
	int mask,u,val;
	node(){}
	node(int _mask,int _u,int _val):mask(_mask),u(_u),val(_val){}
	bool operator>(const node x)const
	{
		return val>x.val;
	}
};
int dp[1<<18][N];
priority_queue<node,vector<node>,greater<node>>pq;
int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back(make_pair(v,w));
		e[v].push_back(make_pair(u,w));
		if(w==a)
			uf.connect(u,v);
	}
	for(int i=1;i<=n;i++)
		r[i]=-1;
	for(int i=1;i<=n;i++)
	{
		if(r[uf.root(i)]==-1)
		{
			if(uf.rnk[uf.root(i)]<=3)
				continue;
			r[i]=r[uf.root(i)]=s++;
		}
		else
			r[i]=r[uf.root(i)];
	}
	memset(dp,INF,sizeof(dp));
	dp[0][1]=0;
	pq.push(node(0,1,0));
	while(!pq.empty())
	{
		node k=pq.top();
		pq.pop();
		int mask=k.mask,u=k.u,val=k.val;
		if(dp[mask][u]!=val)
			continue;
		for(auto i:e[u])
		{
			int v=i.first,w=i.second,nmask=mask;
			if(uf.root(u)==uf.root(v)&&w==b)
				continue;
			if(r[u]!=-1&&w==b)
				nmask|=1<<r[u];
			if(r[v]!=-1&&nmask&(1<<r[v]))
				continue;
			if(dp[nmask][v]>dp[mask][u]+w)
			{
				dp[nmask][v]=dp[mask][u]+w;
				pq.push(node(nmask,v,dp[nmask][v]));
			}
		} 
	}
	for(int i=1;i<=n;i++)
	{
		int ans=INF;
		for(int mask=0;mask<(1<<s);mask++)
			ans=min(ans,dp[mask][i]);
		printf("%d ",ans);
	}
	return 0;
}