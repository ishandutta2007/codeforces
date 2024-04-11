#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,x,t,s=0;
		scanf("%lld%lld%lld",&n,&x,&t);
		x=t/x,n--;
		long long k=min(n,x);
		s+=k*(k+1)/2;
		n-=k;
		s+=n*x;
		printf("%lld\n",s);
	}
	return 0;
}