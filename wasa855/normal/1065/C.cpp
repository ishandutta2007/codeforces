#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	int n,m;
	cin>>n>>m;
	int t;
	int maxn=0;
	int minn=200005;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		if(maxn<t)
		{
			maxn=t;
		}
		if(minn>t)
		{
			minn=t;
		}
		a[t]++;
	}
	int sum=0;
	int ans=0;
	for(int i=maxn;i>minn;i--)
	{
		if(sum+a[i]>m)
		{
			sum=a[i];
			ans++;
		}
		else if(sum+a[i]==m)
		{
			sum=0;
			ans++;
		}
		else
		{
			sum+=a[i];
		}
		a[i-1]+=a[i];
	}
	if(sum!=0)
	{
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}