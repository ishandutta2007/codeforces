#include<bits/stdc++.h>
using namespace std;
int a[25];
int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int tot=n/2;
	int ans=0;
	for(int i=1;i<=tot;i++)
	{
		if(a[i]!=a[n-i+1])
		{
			if(a[i]==2)
			{
				if(a[n-i+1]==0)
				{
					ans+=x;
				}
				else
				{
					ans+=y;
				}
			}
			else if(a[n-i+1]==2)
			{
				if(a[i]==0)
				{
					ans+=x;
				}
				else
				{
					ans+=y;
				}
			}
			else
			{
				cout<<"-1\n";
				return 0;
			}
		}
		else if(a[i]==2)
		{
			ans+=2*min(x,y);
		}
	}
	if(n%2==1)
	{
		if(a[n/2+1]==2)
		{
			ans+=min(x,y);
		}
	}
	cout<<ans<<endl;
	return 0;
}