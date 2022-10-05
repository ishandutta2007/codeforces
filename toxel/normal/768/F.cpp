#include<bits/stdc++.h>
#define ll long long

const int N = 100010;
const int moder = 1e9 + 7;

int f, w, h;
int fac[N], inv[N];

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

int comb(ll n, int m){
	if (n < 0 || m < 0 || m > n){
		return 0;
	}
	return 1ll * fac[n] * inv[m] % moder * inv[n - m] % moder;
}

std::pair <int, int> solve(int n, int m){
	int x = comb(f - 1, n - 1), y = comb(w - 1, m - 1), z = comb(w - 1ll * h * m - 1, m - 1);
	return {1ll * x * z % moder, 1ll * x * y % moder};
}

int main(){
	fac[0] = 1;
	for (int i = 1; i < N; ++ i){
		fac[i] = 1ll * fac[i - 1] * i % moder;
	}
	inv[N - 1] = power_mod(fac[N - 1], moder - 2);
	for (int i = N - 1; i; -- i){
		inv[i - 1] = 1ll * inv[i] * i % moder;
	}
	scanf("%d%d%d", &f, &w, &h);
	if (!h){
		return printf("1\n"), 0;
	}
	if (!f){
		return printf("%d\n", w > h), 0;
	}
	if (!w){
		return printf("%d\n", 1), 0;
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= f; ++ i){
		std::pair <int, int> p = solve(i, i);
		ans1 = (ans1 + 2ll * p.first) % moder;
		ans2 = (ans2 + 2ll * p.second) % moder;
		p = solve(i, i + 1);
		ans1 = (ans1 + p.first) % moder;
		ans2 = (ans2 + p.second) % moder;
		if (i == 1){
			continue;
		}
		p = solve(i, i - 1);
		ans1 = (ans1 + p.first) % moder;
		ans2 = (ans2 + p.second) % moder;
	}
	return printf("%I64d\n", 1ll * ans1 * power_mod(ans2, moder - 2) % moder), 0;
}