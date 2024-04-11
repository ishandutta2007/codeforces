#include<bits/stdc++.h>
#define ll long long
const int N = 100;

ll power[N], n, k, a[N];

int main(){
	power[0] = 1;
	for (int i = 1; i <= 9; ++ i){
		power[i] = power[i - 1] * 10;
	}
	scanf("%I64d%I64d", &n, &k);
	if (!n){
		return printf("0\n"), 0;
	}
	int len = 0;
	while (n){
		a[len ++] = n % 10;
		n /= 10;
	}
	int ans = INT_MAX;
	for (int i = 1; i < 1 << len; ++ i){
		int cnt = 0, sit = 0;
		ll x = 0;
		bool flag = false;
		for (int j = len - 1; j >= 0; -- j){
			if (i >> j & 1){
				if (!cnt && !a[j]){
					flag = true;
					sit = j;
				}
				++ cnt;
				x = x * 10 + a[j];
			}
		}
		if (flag && cnt > 1){
			continue;
		}
		if (flag && a[sit]){
			continue;
		}
		if (!(x % power[k])){
			ans = std::min(ans, len - cnt);
		}
	}
	return printf("%d", ans), 0;
}