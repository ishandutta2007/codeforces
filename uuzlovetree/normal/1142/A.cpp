#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a,b;
ll gcd(ll a,ll b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
int main()
{
	cin>>n>>k>>a>>b;
	ll x=n*k,y=0;
	for(int i=1;i<=n;++i)
	{
		x=min(x,n*k/gcd(a+b+k*i,n*k));
		y=max(y,n*k/gcd(a+b+k*i,n*k));
		x=min(x,n*k/gcd(a-b+k*i,n*k));
		y=max(y,n*k/gcd(a-b+k*i,n*k));
		x=min(x,n*k/gcd(b-a+k*i,n*k));
		y=max(y,n*k/gcd(b-a+k*i,n*k));
		x=min(x,n*k/gcd(k-a-b+k*i,n*k));
		y=max(y,n*k/gcd(k-a-b+k*i,n*k));
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}