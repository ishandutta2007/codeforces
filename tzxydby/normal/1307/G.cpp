#include<bits/stdc++.h>
using namespace std;
const int N=100005,inf=1e9;
int n,m,h[N],to[N],nxt[N],f[N],c[N],s=1,in[N],d[N],p1[N],p2[N],g[N],t,z;
queue<int>q;
int add(int u,int v,int b,int w)
{
	s++;
	nxt[s]=h[u],h[u]=s;
	to[s]=v,f[s]=b,c[s]=w;
}
int spfa()
{
	for(int i=1;i<=n;i++)
		d[i]=inf;
	d[1]=0,in[1]=1;
	q.push(1);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		in[u]=0;
		for(int i=h[u];i;i=nxt[i])
		{
			if(f[i])
			{
				int v=to[i],w=c[i];
				if(d[v]>d[u]+w)
				{
					d[v]=d[u]+w;
					p1[v]=u;
					p2[v]=i;
					if(!in[v])
					{
						q.push(v);
						in[v]=1;
					}
				}
			}
		}
	}
	return d[n]<inf;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,1,w);
		add(v,u,0,-w);
	}
	while(spfa())
	{
		int s=0;
		for(int i=n;i!=1;i=p1[i])
		{
			s+=c[p2[i]];
			f[p2[i]]--;
			f[p2[i]^1]++;
		}
		g[++t]=s;
		g[t]+=g[t-1];
	}
	scanf("%d",&z);
	while(z--)
	{
		int x;
		scanf("%d",&x);
		double ans=inf;
		for(int i=1;i<=t;i++)
			ans=min(ans,1.0*(g[i]+x)/i);
		printf("%.9lf\n",ans);
	}
	return 0;
}