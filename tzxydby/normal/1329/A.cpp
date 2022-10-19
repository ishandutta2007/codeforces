#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int a[N],n,m,ans[N],s[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	if(s[m]<n)
	{
		puts("-1");
		return 0;
	}
	ans[1]=1;
	for(int i=2;i<=m;i++)
	{
		int l=ans[i-1]+1,r=ans[i-1]+a[i-1];
		int sum=s[m]-s[i];
		if(sum>=n-l-a[i]+1)
			ans[i]=l;
		else
			ans[i]=n-sum-a[i]+1;
		if(ans[i]+a[i]-1>n)
		{
			puts("-1");
			return 0;
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}