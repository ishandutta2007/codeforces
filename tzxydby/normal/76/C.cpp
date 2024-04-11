#include<bits/stdc++.h>
using namespace std;
const int N=22;
int n,k,t,c[N],a[N][N],ans,p[N],m;
long long dp[1<<N];
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k>>t>>s;
	for(int i=0;i<k;i++)
	{
		cin>>c[i];
		dp[1<<i]=c[i];
		p[i]=-1;
	}
	for(int i=0;i<k;i++)
		for(int j=0;j<k;j++)
			cin>>a[i][j];
	for(int i=0;i<n;i++)
	{
		int x=s[i]-'A';
		m|=(1<<x);
		for(int j=0;j<k;j++)
		{
			if(p[j]==-1)
				continue;
			if(p[j]&(1<<j))
				continue;
			if(p[j]&(1<<x))
				continue;
			dp[p[j]]+=a[j][x];
			dp[p[j]|(1<<j)]-=a[j][x];
			dp[p[j]|(1<<x)]-=a[j][x];
			dp[p[j]|(1<<j)|(1<<x)]+=a[j][x];
			p[j]|=(1<<x);
		}
		p[x]=0;
	}
	for(int i=0;i<k;i++)
		for(int j=0;j<(1<<k);j++)
			if(j&(1<<i))
				dp[j]+=dp[j^(1<<i)];
	for(int i=0;i<(1<<k);i++)
		if((i&m)==i&&i!=m&&dp[i]<=t)
			ans++;
	cout<<ans<<endl;
	return 0;
}