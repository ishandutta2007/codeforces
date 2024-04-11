#include<bits/stdc++.h>
#define ll unsigned long long

const int N = 20;

ll n, s;
ll power[N], digit[N];

ll calc(ll n){
	ll ret = 0, cnt = 0;
	for ( ; n; n /= 10){
		ret += (power[cnt ++] - 1) * (n % 10);
	}
	return ret;
}

int main(){
	power[0] = 1;
	for (int i = 1; i < N; ++ i){
		power[i] = power[i - 1] * 10;
	}
	scanf("%I64u%I64u", &n, &s);
	ll left = 0, right = n;
	while (left < right){
		ll mid = left + right + 1 >> 1;
		if (calc(mid) >= s){
			right = mid - 1;
		}
		else{
			left = mid;
		}
	}
	return printf("%I64u", n - left), 0;
}