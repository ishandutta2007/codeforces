#include <cstdio>
#include <algorithm>

typedef long long lli;
int main() {
	int n,val;
	scanf("%d",&n);
	while(n--) {
		scanf("%d",&val);
		if(val==1) {
			puts("0");
			continue;
		}
		lli lo=0,up=val-1;
		while(up-lo>1) {
			lli md=(lo+up)/2;
			if((val-md)*(val-md-1)/2>md) lo=md;
			else up=md;
		}
		lli max=lo*2;
		lo++;
		if(lo>=val) up=val-1;
		lli rem=(val-lo)*(val-lo-1)/2;
		if(rem>lo) rem=lo;
		if(max<rem+lo) max=rem+lo;
		printf("%lld\n",max);
	}

	return 0;
}