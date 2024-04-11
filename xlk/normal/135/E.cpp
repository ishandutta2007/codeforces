#include<iostream>
using namespace std;
typedef long long ll;
int v[1000020],n,m;
ll p=1000000007;
ll pw(ll x,ll y)
{
	ll _=1;
	for(;y;y>>=1,x=x*x%p)
		y&1?_=_*x%p:0;
	return _;
}
ll F(int x)
{
	ll z=0,s=pw(n,x);
	for(int i=0;i<n;i++)
		z=(z+s)%p,s=s*v[n+min(0,x-i-2)]%p*(n-i-1)%p*(n-i-1)%p;
	return z;
}
int main()
{
	cin>>n>>m;
	v[1]=1;
	for(int i=2;i<=n;i++)
		v[i]=v[p%i]*(p-p/i)%p;
	cout<<(F(m+1)-F(m)+pw(n,m)+p)%p;
	return 0;
}