#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(ll x)
{
	if(x==1||x==4)
	{
		return false;
	}
	if(x==2||x==3)
	{
		return true;
	}
	ll l=sqrt(x)+1;
	for(ll i=2;i<=l;i++)
	{
		if(x%i==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int t;
	cin>>t;
	ll a,b;
	for(int i=1;i<=t;i++)
	{
		cin>>a>>b;
		if(a-b==1&&cmp(a+b)==true)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	return 0;
}