#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
void solve(ll n,ll&a,ll&b)
{
	if(n==0)return;
	if(n&1)
	{
		a++;
		solve(n-1,b,a);
		return;
	}
	if(n%4==0&&n!=4)
	{
		a++;
		solve(n-1,b,a);
		return;
	}
	a+=n/2;
	solve(n/2,b,a);
}
int t;
ll n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		ll a=0,b=0;
		solve(n,a,b);
		printf("%lld\n",a);
	}
	return 0;
}