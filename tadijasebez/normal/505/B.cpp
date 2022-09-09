#include <stdio.h>
const int N=105;
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
} d[N];
int main()
{
	int n,m,i,u,v,w,q,c;
	scanf("%i %i",&n,&m);
	for(i=1;i<=m;i++) d[i]=DSU(n);
	for(i=1;i<=m;i++)
	{
		scanf("%i %i %i",&u,&v,&w);
		d[w].Union(u,v);
	}
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&u,&v);
		c=0;
		for(i=1;i<=m;i++) c+=d[i].Find(u)==d[i].Find(v);
		printf("%i\n",c);
	}
	return 0;
}