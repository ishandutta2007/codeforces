#include <bits/stdc++.h>
#define Maxn 5007
using namespace std;
int n;
int a[Maxn];
int f[Maxn][Maxn][2];
int calc(int x,int y)
{
	if (x<y) return 0;
	return x-y+1;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++)
			for (int k=0;k<=1;k++)
				f[i][j][k]=1000000000;
	f[1][1][1]=0;
	f[1][0][0]=0;
	for (int i=2;i<=n;i++)
		for (int j=0;j<=(i+1)/2;j++)
		{
			f[i][j][0]=min(f[i-1][j][0],f[i-1][j][1]+calc(a[i],a[i-1]));
			if (j>0)
			{
				if (i==2) f[i][j][1]=calc(a[1],a[2]); else f[i][j][1]=min(f[i-2][j-1][0]+calc(a[i-1],a[i]),f[i-2][j-1][1]+calc(a[i-1],a[i-2])+calc(min(a[i-2]-1,a[i-1]),a[i]));
			}
		}
	for (int i=1;i<=(n+1)/2;i++)
		printf("%d ",min(f[n][i][0],f[n][i][1]));
	printf("\n");
	return 0;
}