#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n,m;
	cin>>n>>m;
	ll k=(m-n+1)/2;
	if(n==m)
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	for(ll i=1;i<=k;i++)
	{
		printf("%lld %lld\n",n+(i*2)-2,n+(i*2)-1);
	}
	return 0;
}