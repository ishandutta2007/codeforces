#include <bits/stdc++.h>
using namespace std;
int w,h;
int main()
{
	scanf("%d%d",&w,&h);
	long long ans=1;
	for(int i=1;i<=w+h;i++) 
		ans=(ans*2)%998244353;
	printf("%lld",ans);
	return 0;
}