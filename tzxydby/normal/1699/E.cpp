#include<bits/stdc++.h>
using namespace std;
const int N=5000005,mx=5000000;
int n,m,a[N],b[N],dp[N],ans,p;
void chk(int u,int v)
{
	if(dp[u]<v)
		return;
	if(a[u])
		b[dp[u]]--;
	dp[u]=v;
	if(a[u])
		b[dp[u]]++;
	while(p&&!b[p])
		p--;
}
void sol()
{
	cin>>n>>m;
	for(int i=0;i<=m+1;i++)
		a[i]=b[i]=0,dp[i]=m+1;
	ans=m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a[x]=1;
	}
	for(int i=1;i<=m;i++)
		if(a[i])
			b[m+1]++;
	p=m+1;
	for(int i=m;i>=1;i--)
	{
		chk(i,i);
		for(int j=i+i;j<=m;j+=i)
			chk(j,max(i,dp[j/i]));
		if(p<=m)
			ans=min(ans,p-i);
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
		sol();
	return 0;
}