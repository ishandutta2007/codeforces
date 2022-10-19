#include<bits/stdc++.h>
using namespace std;
const int N=50005,M=3000005;
int n,m,t[N],ans[N],c,d,lc[M],rc[M],h[M],rt,p[M],f[M];
long long l[N],r[N];
vector<int>e[M],g[M];
vector<long long>v;
char b[10];
void add(int &k,long long l,long long r,long long a,long long b)
{
	if(!k) k=++d;
	if(l==a&&r==b)
	{
		h[k]=++c;
		return;
	}
	long long mid=l+r>>1;
	if(b<=mid) add(lc[k],l,mid,a,b);
	else if(a>mid) add(rc[k],mid+1,r,a,b);
	else add(lc[k],l,mid,a,mid),add(rc[k],mid+1,r,mid+1,b);
}
void dfs(int k1,int k2,int d)
{
	if(d>0)
	{
		if(h[k1]) 
			return;
		dfs(lc[k1],lc[k2],d-1);
		dfs(rc[k1],rc[k2],d-1);
		return;
	}
	if(d==0)
	{
		if(h[k1])
			return;
		dfs(lc[k1],rc[k2],d-1);
		return;
	}
	if(h[k1]&&h[k2])
	{
		e[h[k1]].push_back(h[k2]);
		e[h[k2]].push_back(h[k1]);
		return;
	}
	if(h[k1])
	{
		dfs(k1,lc[k2],d-1);
		dfs(k1,rc[k2],d-1);
		return;
	}
	if(h[k2])
	{
		dfs(lc[k1],k2,d-1);
		dfs(rc[k1],k2,d-1);
		return;
	}
	dfs(lc[k1],lc[k2],d-1);
	dfs(rc[k1],rc[k2],d-1);
}
void ask(int k,long long l,long long r,long long a,long long b,int d)
{
	if(l==a&&r==b)
	{
		p[h[k]]=d;
		g[d].push_back(h[k]);
		return;
	}
	long long mid=l+r>>1;
	if(b<=mid) ask(lc[k],l,mid,a,b,d);
	else if(a>mid) ask(rc[k],mid+1,r,a,b,d);
	else ask(lc[k],l,mid,a,mid,d),ask(rc[k],mid+1,r,mid+1,b,d);
}
int fa(int x){return x==f[x]?x:f[x]=fa(f[x]);}
void ins(int u)
{
	f[u]=u;
	for(auto v:e[u])
		if(f[v])
			f[fa(u)]=fa(v);
}
int cal(long long x)
{
	int k=rt;
	for(int i=n-1;i>=0;i--)
	{
		if(x>>i&1)
			k=rc[k];
		else
			k=lc[k];
		if(h[k])
			return h[k];
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%s%lld%lld",b,&l[i],&r[i]);
		if(b[0]=='a')
			t[i]=1;
		else
			v.push_back(l[i]-1),v.push_back(r[i]);
	}
	v.push_back(-1),v.push_back((1LL<<n)-1);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<v.size();i++)
		add(rt,0,(1LL<<n)-1,v[i-1]+1,v[i]);
	for(int i=0;i<n;i++)
		dfs(rt,rt,n-1-i);
	for(int i=1;i<=m;i++)
		if(!t[i])
			ask(rt,0,(1LL<<n)-1,l[i],r[i],i);
	for(int i=1;i<=c;i++)
		if(!p[i])
			ins(i);
	for(int i=m;i>=1;i--)
	{
		if(!t[i])
		{
			for(auto u:g[i])
				ins(u);
		}
		else
		{
			l[i]=cal(l[i]),r[i]=cal(r[i]);
			ans[i]=(fa(l[i])==fa(r[i]));
		}
	}
	for(int i=1;i<=m;i++)
		if(t[i])
			printf("%d\n",ans[i]);
	return 0;
}