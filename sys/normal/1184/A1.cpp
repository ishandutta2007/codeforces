#include <bits/stdc++.h>
using namespace std;
long long r;
long long check(long long x)
{
	if(x>1e9) return 0;
	long long tmp=r-x*x-x;
	if(tmp<0) return 0;
	if(tmp%(2*x)) return 0;
	return tmp/(2*x);
}
int main()
{
	scanf("%lld",&r);
	r--;
	int maxi=sqrt(r);
	for(int i=1;i<=maxi;i++)
	{
		if(r%i==0&&check(i))
		{
			printf("%d %lld",i,check(i));
			return 0;
		}
		if(r%i==0&&check(r/i))
		{
			printf("%lld %lld",r/i,check(r/i));
			return 0;
		}
	}
	printf("NO");
	return 0;
}