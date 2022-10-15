#include<bits/stdc++.h>
using namespace std;
long long A,B,n,l,t,m;
long long calc(long long x)
{
	return A+(x-1)*B;
}
long long calcc(long long r)
{
	return (calc(l)+calc(r))*(r-l+1)/2;
}
int main()
{
	scanf("%lld%lld%lld",&A,&B,&n);
	for(int i=1;i<=n;i++)
	  {
	  	scanf("%lld%lld%lld",&l,&t,&m);
	  	if(calc(l)>t)
	  	  {
	  	  	printf("-1\n");
	  	  	continue;
		  }
		long long ll=l,rr=(t-A)/B+1;
		while(ll<=rr)
		  {
		  	long long mid=(ll+rr)>>1;
		  	if(calcc(mid)<=t*m)
		  	  ll=mid+1;
		  	else
		  	  rr=mid-1;
		  }
		printf("%lld\n",ll-1);
	  }
	return 0;
}