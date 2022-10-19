#include<bits/stdc++.h>
using namespace std;
struct flow
{
	static const int N=200005,inf=1000000000;
	int n,m,s,t,h[N],to[N],f[N],nx[N],q[N],bg,ed,d[N],c[N];
	void init()
	{
		m=1;
		for(int i=1;i<=n;i++)
			h[i]=0;
	}
	void addedge(int u,int v,int w)
	{
		m++;
		f[m]=w,to[m]=v;
		nx[m]=h[u];
		h[u]=m;
	}
	void add(int u,int v,int w)
	{
		addedge(u,v,w);
		addedge(v,u,0);
	}
	int bfs()
	{
		bg=ed=0;
		for(int i=1;i<=n;i++)
			d[i]=inf,c[i]=h[i];
		d[s]=0;
		q[ed++]=s;
		while(bg<ed)
		{
			int u=q[bg++];
			for(int i=h[u];i;i=nx[i])
			{
				int v=to[i],w=f[i];
				if(w&&d[v]>d[u]+1)
				{
					d[v]=d[u]+1;
					q[ed++]=v;
				}
			}
		}
		return d[t]<inf;
	}
	int dfs(int u,int l)
	{
		if(u==t)
			return l;
		int t=0;
		for(int &i=c[u];i;i=nx[i])
		{
			int v=to[i],w=f[i];
			if(d[v]!=d[u]+1)
				continue;
			int r=dfs(v,min(l,w));
			t+=r,l-=r;
			f[i]-=r,f[i^1]+=r;
			if(!l)
				break;
		}
		return t;
	}
	int mf()
	{
		int t=0;
		while(bfs())
			t+=dfs(s,inf);
		return t;
	}
}g;
const int N=105,M=200005,mx=200000;
int n,k,p[N],c[N],l[N],pr[M];
int chk(int x)
{
	int s=0,h=0;
	g.init();
	for(int i=1;i<=n;i++)
		if(c[i]==1)
			h=max(h,p[i]);
	for(int i=1;i<=n;i++)
	{
		if(c[i]==1&&p[i]!=h)
			continue;
		if(l[i]<=x)
		{
			s+=p[i];
			if(c[i]&1)
			{
				g.add(g.s,i,p[i]);
				for(int j=1;j<=n;j++)
					if(l[j]<=x&&!pr[c[i]+c[j]])
						g.add(i,j,1e9);
			}
			else
				g.add(i,g.t,p[i]);
		}
		if(c[i]==1)
			h=-1;
	}
	s-=g.mf();
	return s>=k;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&p[i],&c[i],&l[i]);
	for(int i=2;i<=mx;i++)
		if(!pr[i])
			for(int j=i+i;j<=mx;j+=i)
				pr[j]=1;
	g.n=n+2,g.s=g.n-1,g.t=g.n;
	if(!chk(n+1))
	{
		puts("-1");
		return 0;
	}
	int l=0,r=n;
	while(r-l>1)
	{
		int m=l+r>>1;
		if(chk(m))
			r=m;
		else
			l=m;
	}
	printf("%d\n",r);
	return 0;
}