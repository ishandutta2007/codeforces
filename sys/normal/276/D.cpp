#include <bits/stdc++.h>
using namespace std;
long long l,r,now;
int main()
{
	scanf("%lld%lld",&l,&r);
	for(int i=62;i>=0;i--)
		if(l/(1LL<<i)!=r/(1LL<<i))
		{
			printf("%lld",(1LL<<i+1)-1);
			return 0;
		}
	printf("0");
	return 0;
}