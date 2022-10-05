#include<bits/stdc++.h>
#define ll long long

ll n, m, k;

ll sum(int mid, int length){
	ll ans = 0;
	if (length > mid){
		ans += length - mid;
		length = mid;
	}
	ans += 1ll * length * (2 * mid - length + 1) >> 1;
	return ans;
}

bool check(int mid){
	ll ret = sum(mid, k) + sum(mid, n - k + 1) - mid;
	return ret <= m;
}

int main(){
	scanf("%I64d%I64d%I64d", &n, &m, &k);
	int left = 1, right = m;
	while (left < right){
		int mid = left + right + 1 >> 1;
		if (check(mid)){
			left = mid;
		}
		else{
			right = mid - 1;
		}
	}
	return printf("%d\n", left), 0;
}