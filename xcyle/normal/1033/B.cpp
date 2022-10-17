#include <iostream>
#include <cstdio>
using namespace std;
long long a, b;
int t;
int main()
{
	scanf("%d", &t);
	while(t--)
	{
	scanf("%lld%lld", &a, &b);
	if(a - b != 1ll) printf("NO\n");
	else
	{
		if(a == 1 || a == 2)
		{
			printf("YES\n");
			continue;
		}
		int type = 0;
		for (long long i = 2; i * i < 2 * (a + b); i++)
		{
			if((a + b) % i == 0) type = 1;
		}
		if(type) printf("NO\n");
		else printf("YES\n"); 
	}
	}	
	return 0;
}