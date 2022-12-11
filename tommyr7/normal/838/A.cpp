#include <bits/stdc++.h>
#define Maxn 5007
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m;
int s[Maxn][Maxn];
char a[Maxn];
int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		scanf("%s",a+1);
		for (int j=1;j<=m;j++)
			if (a[j]=='1') s[i][j]=1; else s[i][j]=0;
	}
	for (int i=1;i<=5000;i++)
		for (int j=1;j<=5000;j++)
		{
			if (i>1) s[i][j]+=s[i-1][j];
			if (j>1) s[i][j]+=s[i][j-1];
			if (i>1&&j>1) s[i][j]-=s[i-1][j-1];
		}
	int ans=n*m;
	for (int k=2;k<=n||k<=m;k++)
	{
		int cnt=0;
		for (int i=1;i<=(n+k-1)/k;i++)
			for (int j=1;j<=(m+k-1)/k;j++)
			{
				int r=s[i*k][j*k]-s[(i-1)*k][j*k]-s[i*k][(j-1)*k]+s[(i-1)*k][(j-1)*k];
				cnt+=min(r,k*k-r);
			}
		ans=min(ans,cnt);
	}
	printf("%d\n",ans);
	return 0;
}