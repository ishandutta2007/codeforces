#include<bits/stdc++.h>
using namespace std;
int ans[200005];
int main()
{
	int n,k;
	cin>>n>>k;
	if(n<k)
	{
		cout<<"NO\n";
		return 0;
	}
	int cnt=0;
	for(int i=0;i<=30;i++)
	{
		if(n&(1<<i))
		{
			ans[++cnt]=(1<<i);
		}
	}
	if(cnt>k)
	{
		cout<<"NO\n";
		return 0;
	}
	while(1)
	{
		for(int i=1;i<=cnt;i++)
		{
			if(cnt==k)
			{
				break;
			}
			if(ans[i]>1)
			{
				ans[i]/=2;
				ans[++cnt]=ans[i];
			}
		}
		if(cnt==k)
		{
			break;
		}
	}
	cout<<"YES\n";
	for(int i=1;i<=cnt;i++)
	{
		printf("%d ",ans[i]);
	}
	cout<<"\n";
	return 0;
}