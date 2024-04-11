#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const long long inf=1e18;
int n,t,dep[N],fa[N][21];
vector<int>e[N];
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
	for(int i=20;i>=0;i--)
		if(dep[fa[u][i]]>=dep[v])
			u=fa[u][i];
	if(u==v)
		return u;
	for(int i=20;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int dis(int u,int v){return dep[u]+dep[v]-2*dep[lca(u,v)];}
long long f(long long l,long long r,long long a,long long b)
{
	if(l>r||!a)
		return inf;
	if((l-1)/a!=r/a)
		return (l+a-1)/a;
	long long x=f((a-r%a)%a,(a-l%a)%a,b%a,a);
	if(x==inf)
		return inf;
	return (x*b+l+a-1)/a;
}
pair<long long,long long>exgcd(long long a,long long b)
{
	if(!a)
		return {0,b<0?-1:1};
	pair<long long,long long>x=exgcd(b%a,a);
	return {x.second-x.first*(b/a),x.first};
}
long long sol1(long long d1,long long d2,long long t1,long long t2)
{
	long long c=t2-t1,g=__gcd(d1,d2);
	if(c%g)
		return inf;
	pair<long long,long long>x=exgcd(d1,-d2);
	x.first*=c/g,x.second*=c/g;
	d1/=g,d2/=g;
	if(x.first<0||x.second<0)
	{
		long long s=max((-x.first-1)/d2+1,(-x.second-1)/d1+1);
		x.first+=s*d2;
		x.second+=s*d1;
	}
	long long s=min(x.first/d2,x.second/d1);
	return (x.first-s*d2)*d1*g+t1;
}
long long sol2(long long d1,long long d2,long long t1,long long t2,long long d)
{
	if((d+t1+t2)&1)
		return inf;
	long long l=((t2-t1-d)%d2+d2)%d2,r=((t2-t1+d)%d2+d2)%d2;
	long long x,y;
	if(!l||2*d==d2||l>r)
		x=0;
	else
		x=f(l,r,d1%d2,d2);
	if(x==inf)
		return inf;
	y=(x*d1+t1-t2+d)/d2;
	return (x*d1+y*d2+t1+t2+d)/2;
}
long long sol(int u,int v,int x,int y)
{
	int l[]={0,lca(u,x),lca(u,y),lca(v,x),lca(v,y)};
	sort(l+1,l+5,[](int a,int b){return dep[a]<dep[b];});
	if(l[3]==l[4]&&!(dep[l[3]]>=max(dep[lca(u,v)],dep[lca(x,y)])))
		return -1;
	int d1=dis(u,v)*2,d2=dis(x,y)*2,d=dis(l[3],l[4]);
	int u1=dis(u,l[3]),u2=dis(u,l[4]);
	if(u1<u2)
		u2=d1-u2;
	else
		u1=d1-u1;
	int x1=dis(x,l[3]),x2=dis(x,l[4]);
	if(x1<x2)
		x2=d2-x2;
	else
		x1=d2-x1;
	long long ans=min(min(sol1(d1,d2,u1,x1),sol1(d1,d2,u2,x2)),min(sol2(d1,d2,u1,x2,d),sol2(d1,d2,u2,x1,d)));
	if(ans==inf)
		return -1;
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	scanf("%d",&t);
	while(t--)
	{
		int u,v,x,y;
		scanf("%d%d%d%d",&u,&v,&x,&y);
		printf("%lld\n",sol(u,v,x,y));
	}
	return 0;
}