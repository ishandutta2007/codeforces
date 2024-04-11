#include<bits/stdc++.h>
using namespace std;
const int N=20;
long long dp[N][1<<N],e[N][N],n,m,ans;
int get(int mask)
{
	for(int i=0;i<n;i++)
		if(mask&(1<<i))
			return i;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		a--,b--;
		e[a][b]=e[b][a]=1;
	}
	for(int i=0;i<n;i++)
		dp[i][1<<i]=1;
	for(int mask=0;mask<(1<<n);mask++)
	{
		int be=get(mask);
		for(int i=be;i<n;i++)
		{
			if(!dp[i][mask])
				continue;
			for(int j=be;j<n;j++)
			{
				if(!e[i][j])
					continue;
				if(j==be)
					ans+=dp[i][mask];
				if(!(mask&(1<<j)))
					dp[j][mask|(1<<j)]+=dp[i][mask];
			}
		} 
	}
	cout<<(ans-m)/2<<endl;
	return 0;
}