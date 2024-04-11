#include<bits/stdc++.h>
using namespace std;
const int N=55,inf=1e9;
int n,k,u[N*N],v[N*N],w[N*N],s,t,d,in[N*N],c[N*N],q[N*N*N*N],dis[N*N],pr[N*N],a[N*N],lj[N][N],ans=inf,bg,ed;
vector<int>e[N*N];
struct d1
{
	int f[N];
	void init(int n){for(int i=1;i<=n;i++)f[i]=i;}
	int fa(int x){return x==f[x]?x:f[x]=fa(f[x]);}
	void mg(int u,int v){f[fa(u)]=fa(v);}
	int ok(int u,int v){return fa(u)!=fa(v);}
}t1,t2;
struct d2
{
	int z[N],l[N];
	void init(int n){for(int i=1;i<=n;i++)z[i]=0,l[i]=inf;}
	void mg(int u,int v){z[u]++,z[v]++;}
	int ok(int u,int v){return z[u]<l[u]&&z[v]<l[v];}
}t3,t4,t5;
int dfs()
{
	for(int i=1;i<=d+2;i++)
		e[i].clear();
	t2=t1,t5=t4;
	for(int i=1;i<=d;i++)
		if(a[i])
			t2.mg(u[i],v[i]),t5.mg(u[i],v[i]);
	for(int i=1;i<=d;i++)
	{
		if(!a[i])
		{
			if(t2.ok(u[i],v[i]))
				e[s].push_back(i);
			if(t5.ok(u[i],v[i]))
				e[i].push_back(t);
		}
	}
	for(int i=1;i<=d;i++)
	{
		if(a[i])
		{
			t2=t1,t5=t4;
			for(int j=1;j<=d;j++)
				if(i!=j&&a[j])
					t2.mg(u[j],v[j]),t5.mg(u[j],v[j]);
			for(int j=1;j<=d;j++)
			{
				if(!a[j])
				{
					if(t2.ok(u[j],v[j]))
						e[i].push_back(j);
					if(t5.ok(u[j],v[j]))
						e[j].push_back(i);
				}
			}
		}
	}
	bg=ed=0;
	for(int i=1;i<=d+2;i++)
		dis[i]=inf,pr[i]=c[i]=in[i]=0;
	dis[s]=0,q[ed++]=s,in[s]=1;
	while(bg<ed)
	{
		int u=q[bg++];
		in[u]=0;
		for(auto v:e[u])
		{
			int nd=dis[u]+(a[v]?-w[v]:w[v]);
			if(nd<dis[v]||(nd==dis[v]&&c[u]+1<c[v]))
			{
				dis[v]=nd,c[v]=c[u]+1,pr[v]=u;
				if(!in[v])
					q[ed++]=v,in[v]=1;
			}
		}
	}
	if(dis[t]==inf)
		return -1;
	for(int i=pr[t];i!=s;i=pr[i])
		a[i]^=1;
	return dis[t];
}
int main()
{
	scanf("%d%d",&n,&k);
	t3.init(n);
	for(int i=1;i<=k;i++)
		scanf("%d",&t3.l[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			scanf("%d",&lj[i][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=max(i+1,k+1);j<=n;j++)
		{
			d++;
			u[d]=i,v[d]=j;
			w[d]=lj[i][j];
		}
	}
	s=d+1,t=d+2;
	int b=(1<<(k*(k-1)/2))-1;
	for(int x=0;x<=b;x++)
	{
		t1.init(n);
		t4=t3;
		for(int i=1;i<=d;i++)
			a[i]=0;
		int z=0,f=1,r=0;
		for(int i=1;i<=k;i++)
		{
			for(int j=i+1;j<=k;j++)
			{
				if(x>>z&1)
				{
					f&=t1.ok(i,j),f&=t4.ok(i,j);
					t1.mg(i,j),t4.mg(i,j);
					r+=lj[i][j];
				}
				z++;
			}
		}
		if(!f)
			continue;
		int p=n-1-__builtin_popcount(x);
		while(p--)
		{
			int y=dfs();
			if(y==-1)
			{
				f=0;
				break;
			}
			r+=y;
		}
		if(f)
			ans=min(ans,r);
	}
	printf("%d\n",ans);
	return 0;
}