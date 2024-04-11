#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int n=a+b,ans=0;
	for(int l=1,r;l<=n;l=r+1)
	{
		int g=n/l;
		r=n/g;
		if(a<g||b<g)
			continue;
		int a_low=(a+g)/(g+1);
		int a_high=a/g;
		int b_low=(b+g)/(g+1);
		int b_high=b/g;
		if(a_low<=a_high&&b_low<=b_high)
			ans+=max(0,min(a_high+b_high,r)-max(a_low+b_low,l)+1);
	}
	printf("%d\n",ans);
	return 0;
}