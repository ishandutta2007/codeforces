#include<bits/stdc++.h>
using namespace std;
#define N 40
#define int long long
int f[N][N];
signed main()
{
	int n,h;
	cin>>n>>h;
	for(int i=0;i<=n;i++) f[0][i]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=i;k++)
			{
				f[i][j]+=f[k-1][j-1]*f[i-k][j-1];
			}
		}
	}
	cout<<f[n][n]-f[n][h-1]<<endl;
	return 0;
}