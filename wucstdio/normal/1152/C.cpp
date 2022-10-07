#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll a,b,k,ans=1000000000000000000;
int main()
{
	scanf("%I64d%I64d",&a,&b);
	if(a>b)swap(a,b);
	ll v=b-a;
	for(ll i=1;i*i<=v;i++)
	{
		if(v%i)continue;
		ll x=i;
		ll nowk=(x-a%x)%x;
		ll nowans=(a+nowk)/__gcd(a+nowk,b+nowk)*(b+nowk);
		if(nowans<ans)
		{
			ans=nowans;
			k=nowk;
		}
		x=v/i;
		nowk=(x-a%x)%x;
		nowans=(a+nowk)/__gcd(a+nowk,b+nowk)*(b+nowk);
		if(nowans<ans)
		{
			ans=nowans;
			k=nowk;
		}
	}
	printf("%I64d\n",k);
	return 0;
}