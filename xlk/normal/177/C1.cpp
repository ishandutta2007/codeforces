#include<stdio.h>
#include<algorithm>
using namespace std;
int f[2020];
int c[2020];
int v[2020];
int n,m,x,y;
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		f[i]=i;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d %d",&x,&y),f[F(x)]=F(y);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d %d",&x,&y),v[F(x)]|=F(x)==F(y);
	for(int i=1;i<=n;i++)
		if(!v[F(i)])
			c[f[i]]++;
	printf("%d\n",*max_element(c,c+n+1));
	return 0;
}