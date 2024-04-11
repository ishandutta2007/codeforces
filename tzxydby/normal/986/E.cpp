#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=10000005,mod=1e9+7,K=700005;
int n,m,pr[M],a[N],fa[N][17],dep[N],ans[N],mp[M];
vector<int>e[N],p,c[K];
struct node
{
	int x,t,id;
};
vector<node>q[N];
int qp(int a,int b)
{
	assert(b>=0);
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
void dfs(int u,int f)
{
	fa[u][0]=f,dep[u]=dep[f]+1;
	for(auto v:e[u])
		if(v!=f)
			dfs(v,u);
}
int lca(int u,int v)
{
	if(dep[u]<dep[v])
		swap(u,v);
	for(int i=16;i>=0;i--)
		if(dep[fa[u][i]]>=dep[v])
			u=fa[u][i];
	if(u==v)
		return u;
	for(int i=16;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
void ag(int p,int x)
{
	p=mp[p];
	while(c[p].size()<=x)
		c[p].push_back(0);
	c[p][x]++;
}
void dg(int p,int x)
{
	p=mp[p];
	c[p][x]--;
}
int qg(int p,int x)
{
	p=mp[p];
	int ans=0;
	for(int i=1;i<c[p].size();i++)
	{
		if(i<=x)
			ans+=i*c[p][i];
		else
			ans+=x*c[p][i];
	}
	return ans;
}
void add(int x)
{
	for(auto i:p)
	{
		if(1ll*i*i>x)
			break;
		if(x%i)
			continue;
		int c=0;
		while(x%i==0)
		{
			c++;
			x/=i;
		}
		ag(i,c);
	}
	if(mp[x])
		ag(x,1);
}
void del(int x)
{
	for(auto i:p)
	{
		if(1ll*i*i>x)
			break;
		if(x%i)
			continue;
		int c=0;
		while(x%i==0)
		{
			c++;
			x/=i;
		}
		dg(i,c);
	}
	if(mp[x])
		dg(x,1);
}
int query(int x)
{
	int ans=1;
	for(auto i:p)
	{
		if(1ll*i*i>x)
			break;
		if(x%i)
			continue;
		int c=0;
		while(x%i==0)
		{
			c++;
			x/=i;
		}
		int r=qg(i,c);
		ans=1ll*ans*qp(i,r)%mod;
	}
	if(mp[x])
	{
		int r=qg(x,1);
		ans=1ll*ans*qp(x,r)%mod;
	}
	return ans;
}
void sol(int u,int f)
{
	add(a[u]);
	for(auto i:q[u])
	{
		int x=i.x,t=i.t,id=i.id;
		int v=query(x);
		if(t==0)
			ans[id]=1ll*ans[id]*v%mod;
		else
			ans[id]=1ll*ans[id]*qp(v,mod-2)%mod*qp(v,mod-2)%mod;
	}
	for(auto v:e[u])
		if(v!=f)
			sol(v,u);
	del(a[u]);
}
signed main()
{
	for(int i=2;i<=1e7;i++)
	{
		if(!pr[i])
		{
			p.push_back(i);
			mp[i]=p.size();
			for(int j=i+i;j<=1e7;j+=i)
				pr[j]=1;
		}
	}
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1,0);
	for(int j=1;j<=16;j++)
		for(int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,x;
		scanf("%d%d%d",&u,&v,&x);
		int l=lca(u,v);
		q[u].push_back({x,0,i});
		q[v].push_back({x,0,i});
		q[l].push_back({x,1,i});
		ans[i]=__gcd(a[l],x);
	}
	sol(1,0);
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}