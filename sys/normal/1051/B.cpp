#include <bits/stdc++.h>
using namespace std;
long long l,r; 
int main()
{
	scanf("%lld%lld",&l,&r);
	printf("YES\n");
	long long cnt=l-1;
	for(int i=1;i<=(r-l+1)/2;i++)
	{
		printf("%lld %lld\n",cnt+1,cnt+2);
		cnt+=2;
	}
	return 0;
}