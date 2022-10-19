#include<bits/stdc++.h>
using namespace std;
const int N=200005,B=505,BS=500,mod=1e9+7;
int n,q,a[N],b[N],d[N],m,bl[N],br[N],g[N],sz[N],ql[N],qr[N],od[N],f[N],db[B][B];
long long p[N],p1[B][B],p2[B][B],ans[N],st[N];
void build(int d)
{
	int t=0;
	for(int i=bl[d];i<=br[d];i++)
		db[d][++t]=i;
	sort(db[d]+1,db[d]+t+1,[&](int x,int y){return p[x]<p[y];});
	for(int i=1;i<=t;i++)
	{
		int j=db[d][i];
		p1[d][i]=(p1[d][i-1]+p[j]*::d[j])%mod;
		p2[d][i]=(p2[d][i-1]+::d[j])%mod;
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<n;i++)
		d[i]=a[i+1]-a[i];
	for(int i=1;i<=n;i++)
		p[i]=p[i-1]+b[i];
	for(int l=1,r=BS;l<=n;l+=BS,r+=BS)
	{
		r=min(r,n);
		m++;
		bl[m]=l;
		br[m]=r;
		sz[m]=r-l+1;
		for(int i=l;i<=r;i++)
			g[i]=m;
	}
	for(int i=1;i<=m;i++)
		build(i);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&ql[i],&qr[i]);
		qr[i]--;
		od[i]=i;
		st[i]=p[ql[i]-1];
	}
	sort(od+1,od+q+1,[&](int x,int y){return st[x]<st[y];});
	for(int h=1;h<=q;h++)
	{
		int z=od[h],l=ql[z],r=qr[z];
		if(g[l]==g[r])
		{
			for(int i=l;i<=r;i++)
				ans[z]=(ans[z]+abs(p[i]-st[z])%mod*d[i])%mod;
		}
		else
		{
			for(int i=l;i<=br[g[l]];i++)
				ans[z]=(ans[z]+abs(p[i]-st[z])%mod*d[i])%mod;
			for(int i=g[l]+1;i<g[r];i++)
			{
				while(f[i]+1<=sz[i]&&p[db[i][f[i]+1]]<st[z])
					f[i]++;
				ans[z]=(ans[z]+st[z]%mod*p2[i][f[i]]%mod-p1[i][f[i]])%mod;
				ans[z]=(ans[z]+(p1[i][sz[i]]-p1[i][f[i]])-st[z]%mod*(p2[i][sz[i]]-p2[i][f[i]])%mod)%mod;
			}
			for(int i=bl[g[r]];i<=r;i++)
				ans[z]=(ans[z]+abs(p[i]-st[z])%mod*d[i])%mod;
		}
	}
	for(int i=1;i<=q;i++)
		printf("%lld\n",(ans[i]+mod)%mod);
	return 0;
}