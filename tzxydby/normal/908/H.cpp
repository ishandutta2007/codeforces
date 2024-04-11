#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n,f[N],sz[N],d[N][N],a[N],m,p[N],c[N],ans;
char s[N][N];
int fa(int x){return x==f[x]?x:f[x]=fa(f[x]);}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		f[i]=i,sz[i]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=n;j++)
		{
			if(s[i][j]=='A')
			{
				int fi=fa(i),fj=fa(j);
				if(fi!=fj)
				{
					f[fi]=fj;
					sz[fj]+=sz[fi];
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		fa(i);
		if(f[i]==i&&sz[i]>1)
		{
			m++;
			a[i]=m;
			p[m]=m;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[i][j]=='X')
			{
				if(f[i]==f[j])
				{
					puts("-1");
					return 0;
				}
				d[a[f[i]]][a[f[j]]]=1;
			}
		}
	}
	ans=n;
	for(int z=1;z<=1000;z++)
	{
		random_shuffle(p+1,p+m+1);
		int mx=0;
		for(int i=1;i<=m;i++)
		{
			int s=0;
			for(int j=1;j<=m;j++)
				if(d[p[i]][j])
					s|=(1<<c[j]);
			for(int j=1;j<=m;j++)
			{
				if(!(s>>j&1))
				{
					c[p[i]]=j;
					mx=max(mx,j);
					break;
				}
			}
		}
		for(int i=1;i<=m;i++)
			c[i]=0;
		ans=min(ans,mx);
	}
	printf("%d\n",ans+n-1);
	return 0;
}