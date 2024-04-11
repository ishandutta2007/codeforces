#include<bits/stdc++.h>
using namespace std;
struct flow
{
	static const int N=300005,inf=INT_MAX;
	int n,m,s,t,h[N],to[N],f[N],nx[N],c[N],q[N],bg,ed,d[N],in[N],fu[N],fe[N];
	void init()
	{
		m=1;
		for(int i=1;i<=n;i++)
			h[i]=0;
	}
	void addedge(int u,int v,int w,int wc)
	{
		m++;
		to[m]=v,f[m]=w,c[m]=wc;
		nx[m]=h[u];
		h[u]=m;
	}
	void add(int u,int v,int w,int wc)
	{
		addedge(u,v,w,wc);
		addedge(v,u,0,-wc);
	}
	pair<int,int> spfa()
	{
		int z=0,y=0;
		while(1)
		{
			bg=ed=0;
			for(int i=1;i<=n;i++)
				d[i]=inf,in[i]=fu[i]=fe[i]=0;
			d[s]=0;
			q[ed++]=s;
			while(bg<ed)
			{
				int u=q[bg++];
				in[u]=0;
				for(int i=h[u];i;i=nx[i])
				{
					if(!f[i])
						continue;
					int v=to[i],w=c[i];
					if(d[v]>d[u]+w)
					{
						d[v]=d[u]+w;
						fu[v]=u;
						fe[v]=i;
						if(!in[v])
						{
							q[ed++]=v;
							in[v]=1;
						}
					}
				}
			}
			if(d[t]==inf)
				return make_pair(y,z);
			int l=inf;
			for(int i=t;i!=s;i=fu[i])
				l=min(l,f[fe[i]]);
			y+=l;
			z+=l*d[t];
			for(int i=t;i!=s;i=fu[i])
				f[fe[i]]-=l,f[fe[i]^1]+=l;
		}
	}
}g;
const int N=55;
int n,q,a[N],b[N];
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		a[i]=1,b[i]=n;
	for(int i=1;i<=q;i++)
	{
		int t,l,r,v;
		scanf("%d%d%d%d",&t,&l,&r,&v);
		if(t==1)
		{
			for(int j=l;j<=r;j++)
				a[j]=max(a[j],v);
		}
		else
		{
			for(int j=l;j<=r;j++)
				b[j]=min(b[j],v);
		}
	}
	g.n=n*n+n+2,g.s=g.n-1,g.t=g.n;
	g.init();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			g.add((i-1)*n+j,g.t,1,2*j-1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]>b[i])
		{
			puts("-1");
			return 0;
		}
		g.add(g.s,n*n+i,1,0);
		for(int j=a[i];j<=b[i];j++)
			for(int k=1;k<=n;k++)
				g.add(n*n+i,(j-1)*n+k,1,0);
	}
	int ans=g.spfa().second;
	printf("%d\n",ans);
	return 0;
}