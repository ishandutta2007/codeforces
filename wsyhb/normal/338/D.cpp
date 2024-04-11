#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
	return b?gcd(b,a%b):a;
}
long long x,y;
long long exgcd(long long a,long long b)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	long long d=exgcd(b,a%b);
	long long p=y,q=x-a/b*y;
	x=p,y=q;
	return d;
}
const int max_k=1e4+5;
long long a[max_k];
int main()
{
	long long n,m;
	int k;
	scanf("%lld%lld%d",&n,&m,&k);
	long long L=1;
	for(int i=1;i<=k;++i)
	{
		scanf("%lld",a+i);
		long long d=gcd(L,a[i]);
		L/=d;
		if(n/a[i]<L)
		{
			puts("NO");
			return 0;
		}
		L*=a[i];
	}
	long long a1=0,p1=a[1];
	for(int i=2;i<=k;++i)
	{
		long long a2=-(i-1),p2=a[i];
		long long d=exgcd(p1,p2);
		if((a2-a1)%d)
		{
			puts("NO");
			return 0;
		}
		x*=(a2-a1)/d;
		x%=p2/d;
		a1+=x*p1;
		p1*=p2/d;
		a1=(a1%p1+p1)%p1;
	}
	if(!a1)
		a1=p1;
	if(a1>m-k+1)
	{
		puts("NO");
		return 0;
	}
	for(int i=1;i<=k;++i)
	{
		if(gcd(L,a1+i-1)!=a[i])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}