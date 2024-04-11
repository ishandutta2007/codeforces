#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
	int n,m;
	cin>>n>>m;
	int t;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int per=0;
	int ans=0;
	if(m>=n)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				cout<<1<<endl;
				return 0;
			}
		}
		cout<<-1;
		return 0;
	}
	for(int i=m;i<=n;)
	{
		if(a[i]==1)
		{
			ans++;
			per=i;
			i=i+m+m-1;
			continue;
		}
		bool ok=false;
		for(int j=i;j>per;j--)
		{
			if(a[j]==1)
			{
				ok=true;
				per=j;
				ans++;
				i=j+m+m-1;
				break;
			}
		}
		if(ok==false)
		{
			cout<<"-1\n";
			return 0;
		}
	}
	if(per+m<=n)
	{
		bool ok=false;
		for(int i=n;i>n-m;i--)
		{
			if(a[i]==1)
			{
				ok=true;
				ans++;
				break;
			}
		}
		if(ok==false)
		{
			cout<<"-1\n";
			return 0;
		}
	}
	cout<<ans<<endl;
	return 0;
}