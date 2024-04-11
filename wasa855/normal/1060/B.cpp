#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n;
	cin>>n;
	if(n<10)
	{
		cout<<n<<endl;
		return 0;
	}
	ll sum=0;
	ll now=0;
	for(;now<n;)
	{
		sum++;
		now=10*now+9;
	}
	sum--;
	now/=10;
	ll k=n-now;
	ll ans=sum*9;
	while(k>0)
	{
		ans+=k%10;
		k/=10;
	}
	cout<<ans<<endl;
	return 0;
}