#include<bits/stdc++.h>
using namespace std;
const int max_m=2e5+5;
int a[2][max_m],suff[2][2][max_m];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m;
		scanf("%d",&m);
		for(int i=0;i<=1;++i)
			for(int j=1;j<=m;++j)
				scanf("%d",&a[i][j]);
		assert(!a[0][1]);
		--a[0][1];
		for(int i=0;i<=1;++i)
		{
			suff[0][i][m]=a[i][m]+m;
			for(int j=m-1;j>=1;--j)
				suff[0][i][j]=max(suff[0][i][j+1],a[i][j]+j);
		}
		for(int i=0;i<=1;++i)
		{
			suff[1][i][m]=a[i][m]-m;
			for(int j=m-1;j>=1;--j)
				suff[1][i][j]=max(suff[1][i][j+1],a[i][j]-j);
		}
		int ans=2e9,now=0;
		for(int i=1;i<=m;++i)
		{
			int y=i&1,x=y^1,k=m-i+1;
			ans=min(ans,max(now,max(suff[1][x][i]+(k+1)-(-m),suff[0][y][i]+k-m)));
			now=max(now,max(a[x][i]+2*k,a[y][i]+2*k-1));
		}
		ans=min(ans,now);
		printf("%d\n",ans);
	}
	return 0;
}