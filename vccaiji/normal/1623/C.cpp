#include<bits/stdc++.h>//fuck_cnm
using namespace std;
int n;
long long h[210000];
long long a[210000];
bool check(int x)
{
	for(int i=1;i<=n;i++) a[i]=h[i];
	for(int i=n;i>=3;i--)
	{
		if(a[i]<x) return false;
		long long t=min((a[i]-x)/3,h[i]/3);
		a[i-1]+=t;
		a[i-2]+=2*t;
	}
	if((a[1]<x)||(a[2]<x)) return false;
	return true;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int jj=1;jj<=t;jj++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&h[i]);
		long long l=1,r=1000000000;
		for(;l<r;)
		{
			long long mid=(l+r)/2;
			if(check(mid+1)) l=mid+1;
			else r=mid;
		}
		printf("%lld\n",l);
	}
	return 0;
}