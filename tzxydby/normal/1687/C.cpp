#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,a[N],b[N],f[N],q[N],bg,ed,z,pl[N],pr[N];
long long c[N],d[N];
int fa(int x){return x==f[x]?x:f[x]=fa(f[x]);}
vector<int>e[N];
void mg(int u){f[u]=fa(u+1);z--;}
void sol()
{
	scanf("%d%d",&n,&m);
	z=n+1;
	bg=ed=0;
	for(int i=0;i<=n+1;i++)
	{
		a[i]=b[i]=c[i]=d[i]=0;
		f[i]=i;
		e[i].clear();
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&pl[i],&pr[i]);
		e[pl[i]-1].push_back(i);
		e[pr[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		c[i]=c[i-1]+a[i];
		d[i]=d[i-1]+b[i];
	}
	for(int i=0;i<=n;i++)
	{
		if(c[i]==d[i])
		{
			mg(i);
			q[ed++]=i;
		}
	}
	while(bg<ed)
	{
		int u=q[bg++];
		for(auto d:e[u])
		{
			int l=pl[d],r=pr[d];
			if(fa(l-1)==l-1)
				continue;
			if(fa(r)==r)
				continue;
			for(int i=fa(l);i<=r;i=fa(i))
			{
				mg(i);
				q[ed++]=i;
			}
		}
	}
	puts(z?"NO":"YES");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}