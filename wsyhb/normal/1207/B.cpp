#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int mx=50+5,mx1=2500+5;
int a[mx][mx],ans[mx1][4];
bool M[mx][mx];
int main()
{
	int n,m,cnt=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			if(!a[i][j]) M[i][j]=true;
		}
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			if(a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1])
			{
				ans[++cnt][1]=i,ans[cnt][2]=j;
				M[i][j]=M[i+1][j]=M[i][j+1]=M[i+1][j+1]=true;
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!M[i][j])
			{
				printf("-1");
				return 0;
			}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++) printf("%d %d\n",ans[i][1],ans[i][2]);
	return 0;
}