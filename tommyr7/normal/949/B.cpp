#include <bits/stdc++.h>
using namespace std;
long long n,x;
int q;
long long solve(long long n,long long x)
{
	if (x%2==1) return (x+1)/2;
	if (n==2&&x==2) return 2;
	if (n==3&&x==2) return 3;
	if (n==4&&x==2) return 3;
	if (n==4&&x==4) return 4;
	if (n%2==0) return solve(n/2,x/2)+n/2;
	if (n%2==1)
	{
		if (x==2) return solve(n/2,n/2)+n/2+1;
		return solve(n/2,x/2-1)+n/2+1;
	}
}
int main()
{
	scanf("%lld%d",&n,&q);
	while (q--)
	{
		scanf("%lld",&x);
		printf("%lld\n",solve(n,x));
	}
	return 0;
}