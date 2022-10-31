#include <cstdio>
#include <cmath>

typedef long long lli;

long long sq(long long val) {
	lli lo=0,up=1e9;
	while(up-lo>1) {
		lli md=(lo+up)>>1;
		if(md*md <= val) lo=md;
		else up=md;
	}
	return lo;
}
int main() {
	int test;
	scanf("%d",&test);
	while(test--) {
		lli n,k,x;
		scanf("%lld",&x);
		if(x==0) {
			puts("1 1");
			continue;
		}
		int f=1;
		for(n=1;n*n - (n/2)*(n/2) <= x; n++) {
			if(n*n - x <= 0) continue;
			k = n / sq(n*n - x);
			if(k>0 && n*n - (n/k)*(n/k) == x) {
				printf("%lld %lld\n",n,k);
				f=0;
				break;
			}
		}
		if(f) puts("-1");
	}
	return 0;
}