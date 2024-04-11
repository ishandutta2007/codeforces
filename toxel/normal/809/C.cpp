#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))

const int N = 100;
const int moder = 1e9 + 7;

int test;

int powermod(int a, int exp){
	int ret = 1;
	for ( ; exp; exp >>= 1){
		if (exp & 1){
			ret = 1ll * ret * a % moder;
		}
		a = 1ll * a * a % moder;
	}
	return ret;
}

int sum(int x){
	return 1ll * x * (x + 1) / 2 % moder;
}

int solve(int x, int y, int k){
	int ret = 0;
	for (int x1 = x, lowx; x1; x1 -= lowx){
		lowx = lowbit(x1);
		for (int y1 = y, lowy; y1; y1 -= lowy){
			lowy = lowbit(y1);
			int max= std::max(lowx, lowy), min = std::min(lowx, lowy);
			int z1 = lowx ^ lowy ^ x1 ^ y1;
			z1 = z1 / max * max;
			int z2 = z1 + max - 1;
			if (k < z1){
				continue;
			}
			int kk = std::min(z2, k);
			ret = (ret + 1ll * (min % moder) * (sum(kk) - sum(z1 - 1) + moder)) % moder;
			ret = (ret + 1ll * (min % moder) * (kk - z1 + 1 + moder)) % moder;
		}
	}
	return ret;
}

int main(){
	scanf("%d", &test);
	while (test --){
		int x1, x2, y1, y2, k;
		scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
		-- k;
		int ans = (solve(x2, y2, k) + solve(x1 - 1, y1 - 1, k)) % moder;
		ans = (ans - solve(x2, y1 - 1, k) + moder) % moder;
		ans = (ans - solve(x1 - 1, y2, k) + moder) % moder;
		printf("%d\n", ans);
	}
	return 0;
}