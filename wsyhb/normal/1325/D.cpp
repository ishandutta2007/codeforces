#include<bits/stdc++.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long ll;
int main()
{
	ll u,v;
	scanf("%lld%lld",&u,&v);
	if((v-u)&1||u>v)
	{
		printf("-1");
		return 0;
	}
	if(!u&&!v)
	{
		printf("0");
		return 0;
	}
	ll x=(v-u)>>1;
	if(!x)
	{
		printf("1\n");
		printf("%lld\n",u);
	}
	else if(u&x)
	{
		printf("3\n");
		printf("%lld %lld %lld\n",u,x,x);
	}
	else
	{
		printf("2\n");
		printf("%lld %lld\n",u|x,x);
	}
	return 0;
}