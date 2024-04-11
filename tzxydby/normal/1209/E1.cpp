#include<bits/stdc++.h>
using namespace std;
int f[1<<12][1005],n,m,a[30][1005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			for(int r=1;r<=m;r++)
				scanf("%d",&a[i][r]);
		for(int i=1;i<=m;i++)
		{
			for(int r=0;r<(1<<n);r++)
			{
				for(int p=0;p<n;p++)
				{
					for(int k=0;k<(1<<n);k++)
					{
						if(k+r!=(k|r))continue;
						int sum=0;
						for(int l=0;l<n;l++)if(k&(1<<l))sum+=a[(l+p)%n][i];
						f[i][k+r]=max(f[i][k+r],f[i-1][r]+sum);
					}
				}
			}
			for(int r=0;r<(1<<n);r++)
				f[i][r]=max(f[i][r],f[i-1][r]);
		}
		printf("%d\n",f[m][(1<<n)-1]);
	}
	return 0;
}