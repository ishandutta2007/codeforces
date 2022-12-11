#include<bits/stdc++.h>
#define maxn 505
using namespace std;
int n,m;
int a[maxn][maxn],b[maxn][maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)scanf("%d",&a[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)scanf("%d",&b[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)if(a[i][j]!=b[i][j])
		{
			int x=0,y=0;
			for(int k=i+1;k<=n;++k)if(a[k][j]!=b[k][j])
			{
				x=k;break;
			}
			for(int k=j+1;k<=m;++k)if(a[i][k]!=b[i][k])
			{
				y=k;break;
			}
			if(!x||!y)
			{
				puts("NO");
				return 0;
			}
			a[i][j]^=1;a[x][j]^=1;a[i][y]^=1;a[x][y]^=1;
		}
	puts("YES");
	return 0;
}