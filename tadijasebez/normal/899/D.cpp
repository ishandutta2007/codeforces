#include <stdio.h>
#define ll long long
int main()
{
	ll n,k,tmp=1,cnt=0,eh=1;
	scanf("%lld",&n);
	k=n*2;
	while(k>0) cnt++,tmp*=10,k/=10,eh*=10;
	tmp/=10;eh/=10;
	tmp--;
	ll sol=0,ans=0;
	//printf("%i\n",tmp);
	while(tmp<n*2)
	{
		ans=0;
		if(tmp>n)
		{
			ans=n-(tmp-n);
			ans++;
			ans/=2;
		}
		else ans=(tmp-1)/2;
		sol+=ans;
		//printf("%i\n",sol);
		tmp+=eh;
	}
	printf("%lld\n",sol);
	return 0;
}