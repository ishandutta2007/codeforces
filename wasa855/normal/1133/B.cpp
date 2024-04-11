#include<bits/stdc++.h>
using namespace std;
int sum[105];
int main()
{
	int n,k;
	cin>>n>>k;
	int x;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		sum[x%k]++;
	}
	int ans=0;
	ans+=sum[0]/2*2;
	if(k%2==0)
	{
		ans+=sum[k/2]/2*2;
	}
	for(int i=1;i<=k/2;i++)
	{
		if(i+i!=k)
		{
			ans+=min(sum[i],sum[k-i])*2;
		}
	}
	cout<<ans<<endl;
	return 0;
}