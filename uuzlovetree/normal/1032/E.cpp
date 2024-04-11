#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int n;
int a[maxn];
int f[maxn][maxn*maxn];
int has[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)has[a[i]]++;
	for(int i=1;i<=100;++i)
	{
		for(int j=i+1;j<=100;++j)
		{
			if(has[i]+has[j]==n&&i*has[i]!=j*has[j])
			{
				printf("%d\n",n);
				return 0;
			}
		}
	}
	f[0][0]=1;
	for(int i=1;i<=100;++i)if(has[i])
	{
		for(int j=n;j>=0;--j)
		{
			for(int k=10000;k>=0;--k)
			{
				for(int l=has[i];l;--l)if(k+i*l<=10000&&j+l<=n)
				{
					f[j+l][k+i*l]=min(2,f[j+l][k+i*l]+f[j][k]);
				}
			}
		}
	}
	int ans=0; 
	for(int i=1;i<=100;++i)
	{
		for(int j=1;j<=has[i];++j)if(f[j][j*i]==1)ans=max(ans,j);
	}
	printf("%d\n",ans);
	return 0;
}