#include<bits/stdc++.h>

const int N = 400010;
const int moder = 1e9 + 7;

int fac[N], inv[N];
char s[N];

int power_mod(int a, int index){
	int ret = 1;
	while (index){
		if (index & 1){
			ret = 1ll * ret * a % moder;
		}
		a = 1ll * a * a % moder;
		index >>= 1;
	}
	return ret;
}

int calc(int x, int y){
	return 1ll * fac[x + y - 1] * inv[y - 1] % moder * inv[x] % moder;
}

int main(){
	fac[0] = 1;
	for (int i = 1; i < N; ++ i){
		fac[i] = 1ll * fac[i - 1] * i % moder;
	}
	inv[N - 1] = power_mod(fac[N - 1], moder - 2);
	for (int i = N - 2; i >= 0; -- i){
		inv[i] = 1ll * inv[i + 1] * (i + 1) % moder;
	}
	scanf("%s", s);
	int cnt2 = 0, len = strlen(s);
	for (int i = 0; i < len; ++ i){
		if (s[i] == ')'){
			++ cnt2;
		}
	}
	int cnt1 = 0, ans = 0;
	for (int i = 0; i < len; ++ i){
		if (s[i] == ')'){
			-- cnt2;
			continue;
		}
		++ cnt1;
		ans = (ans + calc(cnt1, cnt2)) % moder;
	}
	return printf("%d\n", ans), 0;
}