#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n;
ll work(ll x)
{
	ll ans=0;
	while(x)
	{
		ans+=x%10;
		x/=10;
	}
	return ans;
}
int main()
{
	scanf("%I64d",&n);
	ll x;
	for(x=1;x-1<=n;x=x*10);
	x/=10;
	x--;
	ll y=n-x;
	printf("%I64d\n",work(y)+work(x));
}