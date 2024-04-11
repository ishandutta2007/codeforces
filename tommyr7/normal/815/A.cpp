#include <bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,cnt=0;
int a[107][107];
int ans[50007],anss[50007];
int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			a[i][j]=read();
if (m>=n)
{
	for (int i=1;i<=n;i++)
	{
		int mn=507;
		for (int j=1;j<=m;j++)
			mn=min(mn,a[i][j]);
		for (int j=1;j<=m;j++)
			a[i][j]-=mn;
		while (mn--) ans[++cnt]=1,anss[cnt]=i;
	}
	for (int j=1;j<=m;j++)
	{
		int mn=507;
		for (int i=1;i<=n;i++)
			mn=min(mn,a[i][j]);
		for (int i=1;i<=n;i++)
			a[i][j]-=mn;
		while (mn--) ans[++cnt]=2,anss[cnt]=j;
	}
	bool check=true;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]>0) check=false;
	if (!check) printf("%d\n",-1); else
	{
		printf("%d\n",cnt);
		for (int i=1;i<=cnt;i++)
			if (ans[i]==1) printf("row %d\n",anss[i]); else printf("col %d\n",anss[i]);
	}
} else
{
	for (int j=1;j<=m;j++)
	{
		int mn=507;
		for (int i=1;i<=n;i++)
			mn=min(mn,a[i][j]);
		for (int i=1;i<=n;i++)
			a[i][j]-=mn;
		while (mn--) ans[++cnt]=2,anss[cnt]=j;
	}	
	for (int i=1;i<=n;i++)
	{
		int mn=507;
		for (int j=1;j<=m;j++)
			mn=min(mn,a[i][j]);
		for (int j=1;j<=m;j++)
			a[i][j]-=mn;
		while (mn--) ans[++cnt]=1,anss[cnt]=i;
	}
	bool check=true;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]>0) check=false;
	if (!check) printf("%d\n",-1); else
	{
		printf("%d\n",cnt);
		for (int i=1;i<=cnt;i++)
			if (ans[i]==1) printf("row %d\n",anss[i]); else printf("col %d\n",anss[i]);
	}
}
	return 0;
}