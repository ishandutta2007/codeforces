#include <stdio.h>
const int N=100050;
const int M=10*N;
const int mod=1e9+7;
int BIT[M];
void Set(int i, int x){ for(;i<M;i+=i&-i) BIT[i]=(BIT[i]+x)%mod;}
int Get(int i){ int ret=0;for(;i>0;i-=i&-i) ret=(ret+BIT[i])%mod;return ret;}
int sol;
int main()
{
	int n,i,x,y;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		y=1ll*(Get(x)+1)*x%mod;
		Set(x,(0ll+y-Get(x)+Get(x-1)+mod)%mod);
	}
	printf("%i\n",Get(M-1));
	return 0;
}