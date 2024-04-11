#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <cstdlib>
using namespace std;
#define N 500005
#define ll long long
int n,k,a[N];ll sum;
ll check1(ll x)
{
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>x)sum+=a[i]-x;
	}
	return sum;
}
ll check2(ll x)
{
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<x)sum+=x-a[i];
	}
	return sum;
}
int main()
{
	// freopen("problem.in","r",stdin);
	// freopen("problem.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
	ll l=0,r=1ll<<60;
	while(l<r)
	{
		ll m=(l+r)>>1;
		if(check1(m)>k)l=m+1;
		else r=m;
	}
	ll left=l;
	l=0,r=sum/n+1;
	while(l<r)
	{
		int m=(l+r)>>1;
		if(check2(m)>k)r=m;
		else l=m+1;
	}
	printf("%lld\n",max(left-l+1,(sum%n)?1ll:0ll));
	return 0;
}