#include <bits/stdc++.h>
#define Maxn 100007
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int sum[107][107][17];
int n,q,c;
int x[Maxn],y[Maxn],s[Maxn];
int main()
{
	n=read(),q=read(),c=read();
	memset(sum,0,sizeof(sum));
	for (int i=1;i<=n;i++)
	{
		x[i]=read(),y[i]=read(),s[i]=read();
		++sum[x[i]][y[i]][s[i]];
	}
	for (int i=1;i<=100;i++)
		for (int j=1;j<=100;j++)
		{
			if (i>1)
			{
				for (int k=0;k<=c;k++)
					sum[i][j][k]+=sum[i-1][j][k];
			}
			if (j>1)
			{
				for (int k=0;k<=c;k++)
					sum[i][j][k]+=sum[i][j-1][k];
			}
			if (i>1&&j>1)
			{
				for (int k=0;k<=c;k++)
					sum[i][j][k]-=sum[i-1][j-1][k];
			}
		}
	while (q--)
	{
		int t=read(),x1=read(),y1=read(),x2=read(),y2=read();
		int ans=0;
		for (int i=0;i<=c;i++)
		{
			int cnt=sum[x2][y2][i]-sum[x1-1][y2][i]-sum[x2][y1-1][i]+sum[x1-1][y1-1][i];
			ans+=cnt*((t+i)%(c+1));
		}
		printf("%d\n",ans);
	}
	return 0;
}