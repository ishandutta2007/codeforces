#include <stdio.h>
class DSU
{
private:
	int *p,*r;
public:
	DSU(){}
	DSU(int n)
	{
		n++;
		p=new int[n];
		r=new int[n];
		for(int i=0;i<n;i++) r[i]=0,p[i]=i;
	}
	int Find(int x)
	{
		if(p[x]!=x) p[x]=Find(p[x]);
		return p[x];
	}
	void Union(int x, int y)
	{
		x=Find(x);
		y=Find(y);
		if(x==y) return;
		if(r[x]>r[y]) p[y]=x;
		if(r[x]<r[y]) p[x]=y;
		if(r[x]==r[y]) r[x]++,p[y]=x;
	}
} d;
int cnt[100],sol;
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,m,i,u,v;
	scanf("%i %i",&n,&m);
	d=DSU(n);
	while(m--) scanf("%i %i",&u,&v),d.Union(u,v);
	for(i=1;i<=n;i++) cnt[d.Find(i)]++;
	for(i=1;i<=n;i++) if(cnt[i]>0) sol+=cnt[i]-1;
	printf("%lld\n",1ll<<sol);
	return 0;
}