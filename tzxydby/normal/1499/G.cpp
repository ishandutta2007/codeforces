#include<bits/stdc++.h>
using namespace std;
const int N=1000005,mod=998244353;
int n,m,q,ans,k,v=1,f[N],c[N],a[N],s[N][2],t[N];
vector<int>x;
int fa(int x)
{
	if(x==f[x])
		return x;
	int y=f[x],t=fa(y);
	c[x]^=c[y];
	return f[x]=t;
}
void mg(int x,int y)
{
	v=v*2%mod,k++,f[k]=k;
	if(a[x]<a[y])
		swap(x,y);
	if(!a[x])
	{
		a[x]^=1,a[y]^=1;
		t[x]=t[y]=k;
		s[k][0]=v;
		return;
	}
	if(!a[y])
	{
		a[x]^=1,a[y]^=1;
		int z=t[x],r=fa(z);
		t[x]=0,t[y]=k;
		c[k]=c[z]^1,f[k]=r;
		s[r][c[k]]=(s[r][c[k]]+v)%mod;
		if(c[k])
			ans=(ans+v)%mod;
		return;
	}
	a[x]^=1,a[y]^=1;
	int z1=t[x],z2=t[y],r1=fa(z1),r2=fa(z2);
	c[k]=c[z1]^1,f[k]=r1;
	s[r1][c[k]]=(s[r1][c[k]]+v)%mod;
	if(c[k])
		ans=(ans+v)%mod;
	if(r1==r2)
		return;
	c[r2]=c[z1]^c[z2],f[r2]=r1;
	s[r1][0]=(s[r1][0]+s[r2][c[r2]])%mod;
	s[r1][1]=(s[r1][1]+s[r2][c[r2]^1])%mod;
	if(c[r2])
		ans=(ans+s[r2][0])%mod,ans=(ans+mod-s[r2][1])%mod;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	while(q--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		mg(u,v+n);
	}
	scanf("%d",&q);
	while(q--)
	{
		int ty,u,v;
		scanf("%d",&ty);
		if(ty==1)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			mg(u,v+n);
			printf("%d\n",ans);
		}
		else
		{
			x.clear();
			for(int i=1;i<=k;i++)
			{
				fa(i);
				if(c[i])
					x.push_back(i);
			}
			printf("%d ",x.size());
			for(auto i:x)
				printf("%d ",i);
			puts("");
		}
		fflush(stdout);
	}
	return 0;
}