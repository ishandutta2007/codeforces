#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,m,x,a[N];
long long f[N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>x;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=0;i<N;i++)
		fill(f[i],f[i]+N,-1);
	f[0][0]=0;
	for (int i=1;i<=x;i++)
	{
		for (int j=1;j<=n;j++)
		{
			for (int k=max(0,j-m);k<j;k++)
			{
				if (f[i-1][k]==-1) 
					continue;
				f[i][j]=max(f[i-1][k]+a[j],f[i][j]);
			}
		}
	}
	long long ans=-1;
	for (int i=n;i>n-m;i--)
		ans=max(ans,f[x][i]);
	cout<<ans;
	return 0;
}
//