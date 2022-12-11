#include<bits/stdc++.h>
using namespace std;
const int max_n=1e3+5;
int a[max_n][max_n];
bool mark[max_n][max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				scanf("%d",&a[i][j]);
		int ans=0;
		for(int i=2;i<=n;++i)
			for(int j=1;j<=n;++j)
			{
				if(!mark[i-1][j])
				{
					ans^=a[i][j];
					mark[i-1][j]^=1;
					mark[i+1][j]^=1;
					mark[i][j-1]^=1;
					mark[i][j+1]^=1;
				}
			}
		for(int j=1;j<=n;++j)
			assert(mark[n][j]);
		printf("%d\n",ans);
		for(int i=0;i<=n+1;++i)
			for(int j=0;j<=n+1;++j)
				a[i][j]=0,mark[i][j]=false;
	}
	return 0;
}