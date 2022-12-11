#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[4];
int main()
{
	ll n,m;
	int q;
	scanf("%lld%lld%d",&n,&m,&q);
	ll g=__gcd(n,m);
	n/=g,m/=g;
	while(q--)
	{
		ll x,y;
		for(int i=1;i<=2;i++)
		{
			scanf("%lld%lld",&x,&y);
			if(x==1) s[i]=(y-1)/n;
			else s[i]=(y-1)/m;
		}
		if(s[1]==s[2]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}