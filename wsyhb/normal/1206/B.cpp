#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,s=1;
	long long ans=0;
	bool f=false;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		if(!x) f=true;
		if(abs(x-1)<=abs(x+1)) ans+=abs(x-1);
		else ans+=abs(x+1),s*=-1;
	}
	if(f||s==1) printf("%lld",ans);
	else printf("%lld",ans+2);
	return 0;
}