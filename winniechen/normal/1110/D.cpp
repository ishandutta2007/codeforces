#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <set>
using namespace std;
#define N 1000005
int n,m,a[N],b[N],ans,f[N][6][6];
int main()
{
	scanf("%d%d",&n,&m);memset(f,-0x3f,sizeof(f));
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[a[i]]++;
	for(int i=0;i<3&&i<=b[1];i++)
		for(int j=0;j<6&&j<=b[2];j++)
			f[2][i][j]=(b[1]-i)/3+(b[2]-j)/3;
	for(int i=3;i<=m;i++)
	{
		for(int j=0;j<3;j++)
			for(int k=0;k<6;k++)
				for(int l=0;l<6&&l<=b[i];l++)
				{
					int tmp=min(b[i]-l,min(j,k));
					f[i][k-tmp][l]=max(f[i-1][j][k]+tmp+(b[i]-l-tmp)/3,f[i][k-tmp][l]);
				}
	}
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
			ans=max(ans,f[m][i][j]);
	printf("%d\n",ans);
}