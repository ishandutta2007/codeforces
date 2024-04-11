#include<stdio.h>
int s[1000020],ss;
int a[1000020],n,t=2,x;
int l[1000020];
int r[1000020];
long long z[1000020];
void R(int x,int y,int w)
{
	z[1]+=w,z[x+1]-=w,z[y+1]-=w,z[x+y+1]+=w;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;s[++ss]=i++)
	{
		for(;a[s[ss]]>a[i];)
			ss--;
		l[i]=s[ss];
	}
	s[ss=0]=n+1;
	for(int i=n;i>0;s[++ss]=i--)
	{
		for(;a[s[ss]]>=a[i];)
			ss--;
		R(i-l[i],s[ss]-i,a[i]);
	}
	for(;t--;)
		for(int i=1;i<=n;i++)
			z[i]+=z[i-1];
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&x);
		printf("%.15f\n",z[x]/(n-x+1.));
	}
	return 0;
}