#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int mid=(n/2)+1;
	long long ans=0;
	for(int i=1;i<=mid;i++)
	{
		if(a[i]>m)
		{
			ans+=a[i]-m;
		}
	}
	for(int i=mid;i<=n;i++)
	{
		if(a[i]<m)
		{
			ans+=m-a[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}