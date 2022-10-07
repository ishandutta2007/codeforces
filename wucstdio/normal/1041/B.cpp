#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll a,b,x,y;
ll gcd(ll x,ll y)
{
	if(x>y)return gcd(y,x);
	if(x==0)return y;
	return gcd(y%x,x);
}
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&a,&b,&x,&y);
	ll d=gcd(x,y);
	x/=d,y/=d;
	printf("%I64d\n",min(a/x,b/y));
	return 0;
}