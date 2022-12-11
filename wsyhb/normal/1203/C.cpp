#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	ll s,x;
	scanf("%lld",&s);
	while(--n)
	{
		scanf("%lld",&x);
		s=__gcd(s,x);
	}
	for(ll i=1;i<=sqrt(s);i++)
		if(s%i==0)
		{
			ans++;
			if(i!=s/i) ans++;
		}
	printf("%d",ans);
	return 0;
}