#include<stdio.h>
#define fr(i,n) for(int i=0;i<n;i++)
int f[120],x[120],y[120],n,z;
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
int U(int x,int y)
{
	f[F(x)]=F(y);
}
int main() 
{
	scanf("%d",&n);
	fr(i,n)
		f[i]=i;
	fr(i,n)
		scanf("%d %d",x+i,y+i);
	fr(i,n)
		fr(j,n)
			if(x[i]==x[j]||y[i]==y[j])
				U(i,j);
	fr(i,n)
		if(F(i)==i)
			z++;
	printf("%d",z-1);
	return 0;
}