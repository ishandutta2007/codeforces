#include<stdio.h>
int f[1000020];
int d[1000020];
int c[1000020];
int n,m,x,y,z;
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		f[i]=i;
	d[1]=2;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		d[x]++,d[y]++;
		f[F(x)]=F(y);
	}
	for(int i=1;i<=n;i++)
		z+=d[i]&1,c[F(i)]|=d[i]&1;
	for(int i=1;i<=n;i++)
		if(f[i]==i&&d[i]&&!c[i])
			z+=2;
	if(c[f[1]]==0&&z==2)
		z=0;
	printf("%d",z/2);
	return 0;
}