#include <stdio.h>
#define ll long long
const int L=63;
ll sz[L];
int main()
{
	int i;ll l,r;
	sz[0]=1;for(i=1;i<L;i++) sz[i]=sz[i-1]*2;
	scanf("%lld %lld",&l,&r);
	ll sol=0;
	for(i=L-2;~i;i--)
	{
		if(l%sz[i+1]<sz[i] && r%sz[i+1]>=sz[i])
		{
			sol=sz[i+1]-1;
			break;
		}
	}
	printf("%lld\n",sol);
	return 0;
}