#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k;
ll gcd(ll x,ll y)
{
	if(x>y)
	{
		swap(x,y);
	}
	if(x==0)
	{
		return y;
	}
	return gcd(y%x,x);
}
int main()
{
	cin>>n>>m>>k;
	if(!(n*m%k==0||(k%2==0&&n*m%k==k/2)))
	{
		cout<<"NO\n";
		return 0;
	}
	if(n*m<n*m*2/k)
	{
		cout<<"NO\n";
		return 0;
	}
	ll nn=n<<1;
	ll mm=m;
	ll kk=k;
	ll t=gcd(nn,kk);
	nn/=t;
	kk/=t;
	if(mm%kk==0&&nn<=n)
	{
		cout<<"YES\n";
		printf("0 0\n%lld 0\n0 %lld",nn,mm/kk);
		return 0;
	}
	nn=n,mm=m<<1,kk=k;
	t=gcd(nn,kk);
	nn/=t;
	kk/=t;
	if(mm%kk==0&&nn<=n)
	{
		cout<<"YES\n";
		printf("0 0\n%lld 0\n0 %lld",nn,mm/kk);
		return 0;
	}
	cout<<"NO\n";
	return 0;
}