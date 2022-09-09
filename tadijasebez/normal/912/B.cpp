#include <stdio.h>
#define ll long long
ll n,k;
int main()
{
	scanf("%lld %lld",&n,&k);
	ll sol=n;
	ll tmp=n;
	int bit=0;
	while(tmp) tmp>>=1,bit++;
	if(k==1) return printf("%lld\n",sol),0;
	for(int i=bit-1;~i;i--)
	{
	
		//if(!k) break;
		if(!((n>>i)&1)) k--,sol+=1ll<<i;
	}
	printf("%lld\n",sol);
	return 0;
}