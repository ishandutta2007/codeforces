#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=505;
const int M=20050;
struct DSU
{
	int p[N],r[N];
	DSU(){ for(int i=0;i<N;i++) p[i]=i,r[i]=0;}
} tmp,base;
int Find(DSU &d, int x)
{
	if(d.p[x]!=x) d.p[x]=Find(d,d.p[x]);
	return d.p[x];
}
void Union(DSU &d, int x, int y)
{
	if(d.r[x]>d.r[y]) d.p[y]=x;
	if(d.r[x]<d.r[y]) d.p[x]=y;
	if(d.r[x]==d.r[y]) d.r[x]++,d.p[y]=x;
}
int Calc(DSU &d, int n)
{
	int ret=0,i;
	for(i=1;i<=n;i++) if(d.p[i]==i) ret++;
	return ret;
}
struct Query
{
	int l,r,i;
	Query(){}
	Query(int a, int b, int c){ l=a,r=b,i=c;}
	inline bool operator < (const Query &b) const
	{
		if(l==b.l) return r>b.r;
		return l<b.l;
	}
} Q[M];
int u[M],v[M],sol[M];
int main()
{
	int n,m,q,i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=m;i++) scanf("%i %i",&u[i],&v[i]);
	scanf("%i",&q);
	for(i=1;i<=q;i++) scanf("%i %i",&Q[i].l,&Q[i].r),Q[i].i=i;
	sort(Q+1,Q+1+q);
	Q[0].l=1,Q[0].r=m;
	for(i=1;i<=q;i++)
	{
		if(Q[i].l>Q[i-1].l)
		{
			for(j=Q[i-1].l;j<Q[i].l;j++)
			{
				int x=Find(base,u[j]);
				int y=Find(base,v[j]);
				if(x!=y) Union(base,x,y);
			}
			tmp=base;
			for(j=m;j>Q[i].r;j--)
			{
				int x=Find(tmp,u[j]);
				int y=Find(tmp,v[j]);
				if(x!=y) Union(tmp,x,y);
			}
			sol[Q[i].i]=Calc(tmp,n);
		}
		else
		{
			for(j=Q[i-1].r;j>Q[i].r;j--)
			{
				int x=Find(tmp,u[j]);
				int y=Find(tmp,v[j]);
				if(x!=y) Union(tmp,x,y);
			}
			sol[Q[i].i]=Calc(tmp,n);
		}
	}
	for(i=1;i<=q;i++) printf("%i\n",sol[i]);
	return 0;
}