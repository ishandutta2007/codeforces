#include<stdio.h>
#define N 200020
int n,m,k,z,a[N],b[N],pa[N],pb[N],l[N],r[N],p[N],s[N],v[N];
inline int cmp(int *a,int x,int y)
{
	return (!p[x]||a[y]>a[y-x+p[x]])&&(!s[x]||a[y]<a[y-x+s[x]]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",pa+i),a[pa[i]]=i;
	for(int i=1;i<=m;i++)
		scanf("%d",pb+i),b[pb[i]]=i;
	for(int i=1;i<=n;i++)
		l[i]=i-1,r[i]=i+1;
	for(int i=n;i>0;i--)
	{
		p[i]=pa[l[a[i]]],s[i]=pa[r[a[i]]];
		r[l[a[i]]]=r[a[i]],l[r[a[i]]]=l[a[i]];
	}
	for(int i=2,k=0;i<=n;i++)
	{
		while(k&&!cmp(a,k+1,i))
			k=v[k];
		v[i]=++k;
	}
	for(int i=1,k=0;i<=m;i++)
	{
		while(k&&!cmp(b,k+1,i))
			k=v[k];
		if(++k==n)
		{
			z++;
			k=v[k];
		}
	}
	printf("%d",z);
	return 0;
}