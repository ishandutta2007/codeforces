#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k;
	scanf("%d",&k);
	while(k--)
	{
		int n,x,t;
		scanf("%d%d%d",&n,&x,&t);
		int p=t/x;
		long long ans;
		if(n-1<=p)
			ans=n*(n-1ll)/2;
		else
			ans=p*(p+1ll)/2+(n-p-1ll)*p;
		printf("%lld\n",ans);
	}
	return 0;
}