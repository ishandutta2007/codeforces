#include<bits/stdc++.h>

typedef long long ll;

int main(){
	ll k, d, t;
	scanf("%I64d%I64d%I64d", &k, &d, &t);
	ll period = ((k - 1) / d + 1) * d;
	ll off = period - k;
	ll total = t << 1;
	ll once = k * 2 + off;
	ll time = total / once * period * 2;
	ll left = total % once;
	if (left <= k << 1){
		time += left;
	}
	else{
		time += k * 2 + (left - k * 2) * 2;
	}
	printf("%I64d.%I64d\n", time >> 1, 5 * (time & 1));
	return 0;
}