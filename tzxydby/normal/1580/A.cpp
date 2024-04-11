#include<bits/stdc++.h>
using namespace std;
const int N=405;
int n,m,x[N][N],y[N][N],a[N][N],z,s[N],p[N];
char rd[N];
void sol()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",rd+1);
		for(int j=1;j<=m;j++)
			a[i][j]=rd[j]-'0';
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			x[i][j]=x[i-1][j]+(a[i][j]^1);
			y[i][j]=y[i-1][j]+a[i][j];
		}
	}
	z=n*m;
	for(int i=2;i<n;i++)
	{
		for(int j=i+2;j<n;j++)
		{
			p[0]=n*m;
			for(int k=1;k<=m;k++)
			{
				int f=y[j][k]-y[i-1][k]+!a[j+1][k]+!a[i-1][k];
				s[k]=s[k-1]+f;
				p[k]=min(p[k-1],x[j][k]-x[i-1][k]-s[k]);
			}
			for(int k=4;k<=m;k++)
				z=min(z,p[k-3]+s[k-1]+x[j][k]-x[i-1][k]);
		}
	}
	printf("%d\n",z);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}