#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int t;scanf("%i",&t);
	while(t--)
	{
		int s,a,b,c;
		scanf("%i %i %i %i",&s,&a,&b,&c);
		ll sum=(ll)s/c+(ll)s/c/a*b;
		printf("%lld\n",sum);
	}
	return 0;
}