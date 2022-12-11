#include <bits/stdc++.h>
using namespace std;
int n,k;
long long ans=1;
int main()
{
	scanf("%d%d",&n,&k);
	if (k>=2) ans+=(1LL*n*(n-1))/2;
	if (k>=3) ans+=(1LL*n*(n-1)*(n-2))/3;
	if (k>=4) ans+=(3LL*n*(n-1)*(n-2)*(n-3))/8;
	printf("%lld\n",ans);
	return 0;
}