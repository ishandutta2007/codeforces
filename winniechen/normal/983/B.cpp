#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define N 5005
int a[N],n,Q,f[N][N],sum[N][N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i][i]=f[i][i]=a[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;i+j<=n;j++)
		{
			sum[j][i+j]=sum[j][i+j-1]^sum[j+1][i+j];
			f[j][i+j]=max(max(sum[j][i+j],f[j][i+j-1]),f[j+1][i+j]);
		}
	}
	scanf("%d",&Q);
	while(Q--)
	{
		int x,y;scanf("%d%d",&x,&y);
		printf("%d\n",f[x][y]);
	}
	return 0;
}