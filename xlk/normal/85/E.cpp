#include<stdio.h>
#include<iostream>
using namespace std;
int n,l,r,u,d,z,x[10020],y[10020],p=1e9+7,a,b,w;
int main()
{
	scanf("%d",&n);
	l=d=1e9,r=u=-1e9;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		x[i]=a+b,y[i]=a-b;
		l=min(l,x[i]),r=max(r,x[i]);
		d=min(d,y[i]),u=max(u,y[i]);
	}
	for(int i=a=b=0;i<n;i++)
	{
		a=max(a,min(max(x[i]-l,y[i]-d),max(r-x[i],u-y[i])));
		b=max(b,min(max(x[i]-l,u-y[i]),max(r-x[i],y[i]-d)));
	}
	w=min(a,b),z=2;
	for(int i=0;i<n;i++)
		if(max(max(x[i]-l,y[i]-d),max(r-x[i],u-y[i]))<=w)
			z=z*2%p;
	if(a==b&&r-l>w&&u-d>w)
		z=z*2%p;
	printf("%d\n%d",w,z);
	return 0;
}