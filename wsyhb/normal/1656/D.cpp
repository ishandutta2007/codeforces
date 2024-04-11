#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		int a=0;
		long long b=n;
		while(b%2==0)
			++a,b>>=1;
		long long k;
		if(b>=(1ll<<(a+1))+1)
			k=1ll<<(a+1);
		else
			k=b>1?b:-1;
		printf("%lld\n",k);
	}
	return 0;
}