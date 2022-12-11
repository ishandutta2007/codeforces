#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T;
ll a,b,c,d;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(a>b*c)
		{
			puts("-1");
			continue;
		}
		else
		{
			ll k=a/(b*d);
			ll ans=(a+a-k*b*d)*(k+1)/2;
			printf("%lld\n",ans);
		}
	}
}