#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t,a[20],dp[300005][105][2],f[20]={1},s[10],zh=1;
signed main()
{
	for(int i=1;i<20;i++)
		f[i]=f[i-1]*i;
	cin>>n>>m;
	while(n)
	{
		a[t++]=n%10;
		s[n%10]++;
		n/=10;
	}
	for(int i=0;i<10;i++)
		zh*=f[s[i]];
	dp[0][0][0]=1;
	for(int i=0;i<(1<<t);i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<2;k++)
			{
				if(!dp[i][j][k])
					continue;
				for(int x=0;x<t;x++)
				{
					if(i&(1<<x))
						continue;
					int v=a[x];
					if(v==0&&k==0)
						continue;
					dp[i|(1<<x)][(j*10+v)%m][k|(v!=0)]+=dp[i][j][k];
				}
			}
		}
	}	
	cout<<dp[(1<<t)-1][0][1]/zh<<endl;
	return 0;
}