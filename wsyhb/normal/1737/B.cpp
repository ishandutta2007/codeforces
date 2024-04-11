#include<bits/stdc++.h>
using namespace std;
inline int my_sqrt(long long x)
{
	int s=sqrt(x);
	while((s+1ll)*(s+1)<=x)
		++s;
	while(1ll*s*s>x)
		--s;
	return s;
}
inline long long calc(long long v)
{
	if(!v)
		return 0;
	int k=my_sqrt(v);
	long long res=3ll*(k-1)+1;
	if(1ll*k*k+k<=v)
		++res;
	if(1ll*k*k+2*k<=v)
		++res;
	return res;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",calc(r)-calc(l-1));
	}
	return 0;
}