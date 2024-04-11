#include<bits/stdc++.h>
#define ll long long

ll n, m;

int main(){
	scanf("%I64d%I64d", &n, &m);
	if (m >= n){
		return printf("%I64d\n", n), 0;
	}
	ll left = 0, right = INT_MAX;
	while (left < right){
		ll mid = left + right >> 1;
		if (mid * mid + mid >> 1 >= n - m){
			right = mid;
		}
		else{
			left = mid + 1;
		}
	}
	return printf("%I64d\n", m + left), 0;
}