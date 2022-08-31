#include<stdio.h>
typedef unsigned u;
u a[3003],b[3003],c[3003],d[3003];
u max(u p,u q){return p>q?p:q;}
int main()
{
	u i=0,n,x;
	for(scanf("%u",&n);i<n;i++)
	{
		scanf("%u",&x);
		a[i]=x;
	}
	for(i=0;i<n;i++)
	{
		scanf("%u",&x);
		b[i]=c[i]=x;
	}
	for(i=0;i<n;i++)
	{
		scanf("%u",&x);
		d[i]=x;
	}
	b[0]=0;d[0]=0;
	for(i=0;++i<n;)
	{
		a[i]+=max(c[i-1],d[i-1]);
		b[i]+=max(a[i-1],b[i-1]);
		c[i]+=max(c[i-1],d[i-1]);
		d[i]+=max(a[i-1],b[i-1]);
	}
	printf("%u\n",max(a[n-1],b[n-1]));
	return 0;
}