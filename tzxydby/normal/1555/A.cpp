#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,x;
		scanf("%lld",&n);
		x=(n+1)/2*2;
		if(x<6)
			x=6;
		printf("%lld\n",x/2*5);
	}
	return 0;
}