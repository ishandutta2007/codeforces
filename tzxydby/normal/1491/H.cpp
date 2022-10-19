#include<bits/stdc++.h>
using namespace std;
const int N=100005,B=330;
int n,q,a[N],t[N],b[N],l[N],r[N],m,g[N];
int nx(int x){return max(1,a[x]-t[b[x]]);}
int jp(int x){if(t[b[x]]>=B)return nx(x);return g[x];}
void reb(int x)
{
	for(int i=l[x];i<=r[x];i++)
	{
		int j=nx(i);
		if(j<l[x])
			g[i]=j;
		else
			g[i]=g[j];
	}
}
void upd(int x,int y,int v)
{
	if(b[x]==b[y])
	{
		for(int i=x;i<=y;i++)
			a[i]=max(1,a[i]-v);
		reb(b[x]);
		return;
	}
	for(int i=x;i<=r[b[x]];i++)
		a[i]=max(1,a[i]-v);
	reb(b[x]);
	for(int i=b[x]+1;i<b[y];i++)
	{
		t[i]=min(t[i]+v,n);
		if(t[i]<B)
			reb(i);
	}
	for(int i=l[b[y]];i<=y;i++)
		a[i]=max(1,a[i]-v);
	reb(b[y]);
}
void lca(int u,int v)
{
	int lu=u,lv=v;
	while(u!=v)
	{
		if(u<v)
			swap(u,v),swap(lu,lv);
		lu=u;u=jp(u);
	}
	u=lu,v=lv;
	while(u!=v)
	{
		if(u<v)
			swap(u,v);
		u=nx(u);
	}
	printf("%d\n",u);
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++)
		scanf("%d",&a[i]);
	for(int x=1;x<=n;x+=B)
	{
		int y=min(x+B-1,n);
		m++;
		l[m]=x,r[m]=y;
		for(int i=x;i<=y;i++)
			b[i]=m;
		reb(m);
	}
	while(q--)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);
			upd(x,y,v);
		}
		else
		{
			int u,v;
			scanf("%d%d",&u,&v);
			lca(u,v);
		}
	}
	return 0;
}