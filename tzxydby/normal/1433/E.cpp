#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=25;
int f[N]={1},c[N][N];
signed main()
{	
	c[0][0]=1;
	for(int i=1;i<=20;i++)
	{
		f[i]=f[i-1]*i;
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	int n;
	cin>>n;
	n/=2;
	int ans=f[n-1];
	ans*=f[n-1];
	ans*=c[2*n][n];
	ans/=2;
	cout<<ans<<endl;
	return 0;
}