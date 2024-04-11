#include<bits/stdc++.h>
using namespace std;
int n,m,p;
long long d[110000];
int h[110000];
long long t[110000];
long long sumt[110000];
long long f[110000];
long long g[110000];//hi
int l,r;
int aa[110000];
inline double slope(double x1,double y1,double x2,double y2)
{
	return (y2-y1)/(x2-x1);
}
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for(int i=2;i<=n;i++) scanf("%lld",&d[i]);
	for(int i=1;i<=m;i++) scanf("%d%lld",&h[i],&t[i]);
	d[1]=0;
	for(int i=2;i<=n;i++) d[i]+=d[i-1];
	for(int i=1;i<=m;i++) t[i]-=d[h[i]];
	sort(t+1,t+m+1);
	sumt[0]=0;
	for(int i=1;i<=m;i++) sumt[i]=sumt[i-1]+t[i];
	for(int i=1;i<=m;i++) f[i]=(i-1)*t[i]-sumt[i-1];
	for(int j=2;j<=p;j++)
	{
		for(int i=1;i<=m;i++) g[i]=f[i];
		l=1,r=0;
		for(int i=1;i<=m;i++)
		{
			for(;r-l>=1;r--)
			{
				if(slope(aa[r],g[aa[r]]+sumt[aa[r]],i,g[i]+sumt[i])>=slope(aa[r-1],g[aa[r-1]]+sumt[aa[r-1]],aa[r],g[aa[r]]+sumt[aa[r]])) break;
			}
			r++;
			aa[r]=i;
			for(;r-l>0;l++)
			{
				if(slope(aa[l],g[aa[l]]+sumt[aa[l]],aa[l+1],g[aa[l+1]]+sumt[aa[l+1]])>=t[i]) break;
			}
			f[i]=g[aa[l]]+sumt[aa[l]]-aa[l]*t[i]+i*t[i]-sumt[i];
		}
	}
	printf("%lld",f[m]);
	return 0;
}