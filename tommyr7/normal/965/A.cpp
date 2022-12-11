#include <bits/stdc++.h>
using namespace std;
int k,n,s,p;
int main()
{
	scanf("%d%d%d%d",&k,&n,&s,&p);
	long long ans=1;
	ans=(n+s-1)/s;
	ans=(1LL*ans*k);
	if (ans%p==0) ans/=p; else ans=ans/p+1;
	printf("%lld\n",ans);
	return 0;
}