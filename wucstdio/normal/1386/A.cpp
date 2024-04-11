#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#define ll long long
using namespace std;
ll val[65],n;
int ask(ll v)
{
	printf("? %lld\n",v);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
ll solve(ll n)
{
	if(n==1)return 1;
	int top=1;
	val[1]=n/2;
	while(val[top]<n-1)val[++top]=(val[top-1]+n)/2;
	ll cur=n;
	bool flag=0;
	while(top)
	{
		if(flag)cur+=val[top];
		else cur-=val[top];
		top--;
		flag^=1;
	}
	ask(cur);
	ll l=1,r=n;
	while(l<r)
	{
		ll mid=(l+r-1)>>1;
		if(flag)cur+=mid;
		else cur-=mid;
		if(ask(cur))r=mid;
		else l=mid+1;
		flag^=1;
	}
	return l;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("= %lld\n",solve(n));
		fflush(stdout);
	}
	return 0;
}