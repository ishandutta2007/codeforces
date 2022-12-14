#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
// #define N 1000005
long long n,m,k,ans;
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&n,&m,&k);
		long long step=max(n,m);
		if(step==k)
		{
			if((abs(n-m))&1)printf("%lld\n",max(n,m)-1);
			else printf("%lld\n",max(n,m));
		}else if(step>k)puts("-1");
		else 
		{
			if((n+m)&1)ans=k-1;
			else if((k-step)&1)ans=k-2;
			else ans=k;
			printf("%lld\n",ans);
		} 
	}
}