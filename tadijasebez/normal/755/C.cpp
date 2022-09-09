#include <stdio.h>
const int N=10050;
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
int main()
{
	int n,i,p;
	scanf("%i",&n);
	d=DSU(n);
	for(i=1;i<=n;i++) scanf("%i",&p),d.Union(i,p);
	int sol=0;
	for(i=1;i<=n;i++) if(d.Find(i)==i) sol++;
	printf("%i\n",sol);
	return 0;
}