#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n;
int main()
{
	scanf("%lld",&n);
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			while(n%i==0)n/=i;
			if(n!=1)
			{
				printf("1\n");
				return 0;
			}
			else
			{
				printf("%lld\n",i);
				return 0;
			}
		}
	}
	printf("%lld\n",n);
	return 0;
}