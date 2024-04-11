#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int n;
long long a[N],v=LLONG_MAX;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	auto sol=[&](long long x)
	{
		long long s=max(0ll,(long long)sqrt(a[1]+x)-2);
		while((s+1)*(s+1)<=a[1]+x)
			s++;
		for(long long i=s;;i++)
		{
			int p=lower_bound(a+1,a+n+1,i*(i+1)-x+1)-a;
			if(p>n) return 1;
			if(a[p]+x<(i+1)*(i+1)) return 0;
		}
	};
	if(sol(0))
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			for(long long j=1;;j++)
			{
				long long x=j*j-a[i];
				if(x>=0&&sol(x))
				{
					v=min(v,x);
					break;
				}
			}
		}
		else
		{
			for(long long j=1;j<=a[i]-a[i-1]+1;j++)
			{
				long long x=j*j-a[i];
				if(x>=0&&sol(x))
				{
					v=min(v,x);
					break;
				}
			}
		}
	}
	printf("%lld\n",v);
	return 0;
}