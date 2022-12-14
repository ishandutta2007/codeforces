#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;
int n;
long long p,q,b;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lld%lld%lld",&p,&q,&b);
		if(!p){printf("Finite\n");continue;}
		long long t=__gcd(p,q);bool vis=0;
		p=p/t,q=q/t;
		while(1)
		{
			long long u=__gcd(b,q);
			if(u==1)break;
			while(!(q%u))q=q/u;
		}
		if(q!=1&&b!=1)puts("Infinite");
		else puts("Finite");
	}
	return 0;
}