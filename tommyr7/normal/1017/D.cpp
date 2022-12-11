#include <bits/stdc++.h>
using namespace std;
int n,m,q;
int w[17],p[17];
int cnt[5007];
int sum[5007][107];
int calc(int x,int y)
{
	int res=0;
	for (int i=1;i<=n;i++)
	{
		if (x%2==y%2) res+=w[i];
		x/=2;
		y/=2;
	}
	return res;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for (int i=1;i<=m;i++)
	{
		int x=0;
		for (int i=1;i<=n;i++)
		{
			char ch=getchar();
			while (ch!='0'&&ch!='1') ch=getchar();
			p[i]=ch-'0';
		}
		for (int i=n;i;i--)
			x=x*2+p[i];
		++cnt[x];
	}
	for (int i=0;i<4096;i++)
		for (int j=0;j<4096;j++)
		{
			int t=calc(i,j);
			if (t<=100) sum[j][t]+=cnt[i];
		}
	for (int i=0;i<4096;i++)
		for (int j=1;j<=100;j++)
			sum[i][j]=sum[i][j-1]+sum[i][j];
	while (q--)
	{
		int x=0;
		for (int i=1;i<=n;i++)
		{
			char ch=getchar();
			while (ch!='0'&&ch!='1') ch=getchar();
			p[i]=ch-'0';
		}
		for (int i=n;i;i--)
			x=x*2+p[i];
		int k;
		scanf("%d",&k);
		printf("%d\n",sum[x][k]);
	}
	return 0;
}