#include <cstdio>

typedef long long lli;

int main() {
	lli n,k;
	scanf("%lld %lld",&n,&k);
	lli lo=0,up=1e12/k;
	while(up-lo>1) {
		lli md=(lo+up)>>1;
		if((k+1)*md<=n/2) lo=md;
		else up=md;
	}
	printf("%lld %lld %lld\n",lo,lo*k,n-(k+1)*lo);
	return 0;
}