#include<bits/stdc++.h>
using namespace std;
struct flow
{
	static const int N=105,M=10005,inf=1000000000;
	int n,m,s,t,h[N],to[M],f[M],nx[M],q[M],bg,ed,d[N],c[N];
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
};
const int N=55;
int n,m,k,x[N],y[N],fl,r[N],vis[N];
struct gr
{
	int a[N][N];
	int cal()
	{
		flow g;
		g.n=n*2+2,g.s=g.n-1,g.t=g.n;
		g.init();
		for(int i=1;i<=n;i++)
		{
			g.add(g.s,i,1);
			g.add(i+n,g.t,1);
			for(int j=1;j<=n;j++)
				if(a[i][j])
					g.add(i,j+n,1);
		}
		int ans=n-g.mf();
		return ans;
	}
}a;
struct an
{
	long long c;
	vector<int>p;
	bool operator<(const an k)const{return c<k.c;}
}b,ans;
vector<int>q[N];
set<pair<int,int>>s;
int pre(gr g,int x)
{
	if(x<0)
		for(int i=1;i<=n;i++)
			g.a[i][-x]=0;
	else
		for(int i=1;i<=n;i++)
			g.a[x][i]=0;
	return g.cal();
}
void ch(int x,int id)
{
	if(x<0)
		for(int i=1;i<=n;i++)
			a.a[i][-x]=0;
	else
		for(int i=1;i<=n;i++)
			a.a[x][i]=0;
	q[id].push_back(x);
}
int dec()
{
	if(!s.size())
		return 0;
	int id=s.begin()->second;
	s.erase(s.begin());
	r[id]--;
	b.c-=y[id];
	if(r[id])
		s.insert({y[id],id});
	return id;
}
void chk(int h)
{
	an y=b;
	for(int i=1;i<h;i++)
	{
		for(auto j:q[i])
			y.p.push_back(j);
		y.p.push_back(0);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			y.p.push_back(i);
	for(int i=h;i<=k;i++)
		y.p.push_back(0);
	for(int i=h+1;i<=k;i++)
		y.c+=x[i];
	ans=max(ans,y);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a.a[i][j]=0;
	while(m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		a.a[u][v]=1;
	}	
	for(int i=1;i<=k;i++)
		scanf("%d%d",&x[i],&y[i]);
	b.c=0,ans.c=-1;
	for(int h=1;h<=k;h++)
	{
		chk(h);
		r[h]=x[h]/y[h];
		if(r[h])
			s.insert({y[h],h});
		b.c+=x[h];
		while(a.cal()<=h)
		{
			int id=dec();
			if(!id)
			{
				fl=1;
				break;
			}
			int mx=-1,op=0;
			for(int i=1;i<=n;i++)
			{
				int y;
				y=pre(a,i);
				if(y>mx)
					mx=y,op=i;
				y=pre(a,-i);
				if(y>mx)
					mx=y,op=-i;
			}
			ch(op,id);
			if(op>0)
				vis[op]=1;
		}
		if(fl)
			break;
	}
	for(int i=1;i<=k;i++)
	{
		for(auto j:q[i])
			b.p.push_back(j);
		b.p.push_back(0);
	}
	if(!fl)
		ans=max(ans,b);
	printf("%d\n",ans.p.size());
	for(auto i:ans.p)
		printf("%d ",i);
	return 0;
}