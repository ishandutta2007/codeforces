#include<bits/stdc++.h>
using namespace std;
const int N=2005;
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
UnionFind uf(2001);
struct edge
{
	int u,v;
	long long w;
	bool operator<(const edge x)const
	{
		return w<x.w;	
	} 
}e[N*N];
int cnt,n;
long long x[N],y[N],c[N],k[N];
vector<int>a1;
vector<pair<int,int>>a2;
void add(int u,int v,long long w)
{
	cnt++;
	e[cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;	
}
long long dis(int i,int j)
{
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		add(i,n+1,c[i]);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<i;j++)
			add(i,j,dis(i,j)*(k[i]+k[j]));
	}
	sort(e+1,e+cnt+1);
	long long ans=0;
	for(int i=1;i<=cnt;i++)
	{
		int u=e[i].u,v=e[i].v;
		long long w=e[i].w;
		if(uf.root(u)==uf.root(v))
			continue;
		uf.connect(u,v);
		ans+=w;
		if(u==n+1)
			a1.push_back(v);
		else if(v==n+1)
			a1.push_back(u);
		else
			a2.emplace_back(u,v); 
	}
	cout<<ans<<endl<<a1.size()<<endl;
	for(auto i:a1)
		cout<<i<<' ';
	cout<<endl<<a2.size()<<endl;
	for(auto i:a2)
		cout<<i.first<<' '<<i.second<<endl; 
	return 0;
}