#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++)
	{
		ll a,b,c;
		scanf("%I64d %I64d %I64d",&b,&c,&a);
		if(b>c)
		{
			swap(b,c);
		}
		if(a<c)
		{
			cout<<"-1\n";
			continue;
		}
		else if(b%2!=c%2)
		{
			cout<<a-1<<"\n";
		}
		else
		{
			if(a%2!=b%2)
			{
				cout<<a-2<<"\n";
			}
			else
			{
				cout<<a<<"\n";
			}
		}
	}
	return 0;
}