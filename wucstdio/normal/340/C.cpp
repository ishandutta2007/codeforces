#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n,a[100005],ans;
ll gcd(ll x,ll y)
{
	if(x==0)return y;
	if(x>y)return gcd(y,x);
	return gcd(y%x,x);
}
int main()
{
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	  a[i]-=a[i-1];
	for(int i=1;i<=n;i++)
	  ans+=(2*i-1)*(n-i+1)*a[i];
	ll d=gcd(ans,n);
	printf("%I64d %I64d\n",ans/d,n/d);
	return 0;
}