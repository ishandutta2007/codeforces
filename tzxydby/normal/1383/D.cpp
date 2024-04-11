#include<bits/stdc++.h>
using namespace std;
const int N=305;
int n,m,a[N][N],rm[N*N],cm[N*N],b[N][N],r,c;
queue<int>qx,qy;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	{
		int x=0;
		for(int j=1;j<=m;j++)
			x=max(x,a[i][j]);
		rm[x]=1;
	}
	for(int j=1;j<=m;j++)
	{
		int x=0;
		for(int i=1;i<=n;i++)
			x=max(x,a[i][j]);
		cm[x]=1;
	}
	for(int i=n*m;i>=1;i--)
	{
		if(rm[i]&&cm[i])
		{
			r++;
			c++;
			b[r][c]=i;
			for(int j=c-1;j>=1;j--)
				qx.push(r),qy.push(j);
			for(int j=r-1;j>=1;j--)
				qx.push(j),qy.push(c);
		}
		else if(rm[i])
		{
			r++;
			b[r][c]=i;
			for(int j=c-1;j>=1;j--)
				qx.push(r),qy.push(j);
		}
		else if(cm[i])
		{
			c++;
			b[r][c]=i;
			for(int j=r-1;j>=1;j--)
				qx.push(j),qy.push(c);
		}
		else
		{
			b[qx.front()][qy.front()]=i;
			qx.pop(),qy.pop();
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			printf("%d%c",b[i][j]," \n"[j==m]);
	return 0;
}