#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n;
ll gcd(ll a,ll b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
ll solve(ll n)
{
	ll x=n,ans=n;
	for(ll i=2;i*i<=n;++i)if(n%i==0)
	{
		while(x%i==0)x/=i;
		ans=gcd(ans,i);
	}
	if(x>1)ans=gcd(ans,x);
	return ans;
}
int main()
{
	cin>>n;
	cout<<solve(n)<<endl;
	return 0; 
}