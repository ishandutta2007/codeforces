#include<bits/stdc++.h>
using namespace std;
const int N=200005,mod=998244353;
long long dp[N][2],a[N],b[N],n,m,k,x,l,r,ans=1;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(i&1)
			a[i/2+1]=x;
		else
			b[i/2]=x;
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=(dp[i-1][0]*(k-2)%mod+dp[i-1][1])%mod;
		dp[i][1]=dp[i-1][0]*(k-1)%mod;
	}
	m=n/2;
	n-=m;
	l=1,r=n;
	while(a[l]==-1&&l<=n)
		l++;
	if(l==n+1)
	{
		for(int i=1;i<n;i++)
			ans=ans*(k-1)%mod;
		ans=ans*k%mod;	
	}
	else
	{
		for(int i=1;i<l;i++)
			ans=ans*(k-1)%mod;
		while(a[r]==-1&&r>=1)
			r--;
		for(int i=n;i>r;i--)
			ans=ans*(k-1)%mod;
		for(int i=l;i<=r;i++)
		{
			if(a[i]==-1)
			{
				int j=i;
				while(a[j]==-1&&j<=n)
					j++;
				if(a[i-1]==a[j])
					ans=ans*dp[j-i][1]%mod;
				else
					ans=ans*dp[j-i][0]%mod;
				i=j;
			}
			else if(a[i]==a[i-1])
				ans=0;
		}
	}
	l=1,r=m;
	while(b[l]==-1&&l<=m)
		l++;
	if(l==m+1)
	{
		for(int i=1;i<m;i++)
			ans=ans*(k-1)%mod;
		ans=ans*k%mod;	
	}
	else
	{
		for(int i=1;i<l;i++)
			ans=ans*(k-1)%mod;
		while(b[r]==-1&&r>=1)
			r--;
		for(int i=m;i>r;i--)
			ans=ans*(k-1)%mod;
		for(int i=l;i<=r;i++)
		{
			if(b[i]==-1)
			{
				int j=i;
				while(b[j]==-1&&j<=n)
					j++;
				if(b[i-1]==b[j])
					ans=ans*dp[j-i][1]%mod;
				else
					ans=ans*dp[j-i][0]%mod;
				i=j;
			}
			else if(b[i]==b[i-1])
				ans=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}