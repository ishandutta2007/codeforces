#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n,i;ll b;
	scanf("%i",&n);
	vector<ll> a(n,0);
	ll l=0,r=9e18;
	for(i=0;i<n/2;i++)
	{
		scanf("%lld",&b);
		a[i]=max(l,b-r);
		a[n-i-1]=b-a[i];
		l=a[i];r=a[n-i-1];
	}
	for(i=0;i<n;i++) printf("%lld ",a[i]);
	return 0;
}