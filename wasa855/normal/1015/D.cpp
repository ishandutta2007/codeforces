#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n,k,s;
	cin>>n>>k>>s;
	if(s<k||k*(n-1)<s)
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	ll ans=s/k;
	ll up=s%k;
	int i;
	for(i=1;i<=up;i++)
	{
		if(i%2==1)
		{
			printf("%d ",ans+2);
		}
		else
		{
			printf("1 ");
		}
	}
	if(i%2==1)
	{
		for(;i<=k;i++)
		{
			if(i%2==1)
			{
				printf("%d ",ans+1);
			}
			else
			{
				printf("1 ");
			}
		}
	}
	else
	{
		for(;i<=k;i++)
		{
			if(i%2==1)
			{
				printf("%d ",ans+2);
			}
			else
			{
				printf("2 ");
			}
		}
	}
	return 0;
}