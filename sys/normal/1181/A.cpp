#include <bits/stdc++.h>
using namespace std;
long long x,y,z,tot,ans;
int main()
{
	scanf("%lld%lld%lld",&x,&y,&z);
	tot=(x+y)/z;
	long long a=x-x/z*z,b=y-y/z*z;
	if(tot!=x/z+y/z) ans=min(z-a,z-b);
	printf("%lld %lld",tot,ans);
	return 0;
}