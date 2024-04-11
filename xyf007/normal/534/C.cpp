#include<bits/stdc++.h>
using namespace std;
long long n,A,d[200001],sum;
int main()
{
	scanf("%lld%lld",&n,&A);
	for(int i=1;i<=n;i++)
	  {
	  	scanf("%lld",&d[i]);
	  	sum+=d[i];
	  }
	for(int i=1;i<=n;i++)
	  {
	  	long long ans=0;
	  	if(d[i]>A-(n-1))
	  	  ans+=d[i]-(A-(n-1));
	  	if(A-sum+d[i]>0)
	  	  ans+=d[i]+A-sum-1;
	  	printf("%lld ",ans);
	  }
	return 0;
}