#include <bits/stdc++.h>
using namespace std;

unsigned long long n, k, cnt, rem, cnt2, lo, hi;
int main(){
	scanf("%llu",&n);
	lo = 1; hi = 1e18;
	while(lo<hi){
		unsigned long long m=lo+hi>>1;
		cnt = 0, rem = n, cnt2=0;
		while(rem>0){
			cnt += min(rem, m);
			rem -= min(rem, m);
			if(rem==0) break;
			cnt2 += (rem/10);
			rem -= (rem/10);
		}
		if(cnt>=cnt2) hi=m;
		else lo=m+1;
	}
	printf("%lld\n",hi);
	getchar(); getchar();
}