#include<bits/stdc++.h>

const int N = 100010;
const int MAX = 1 << 17;

int seg[MAX << 1], a[N];
int n, k;

void build(){
	for (int i = 0; i < MAX << 1; ++ i){
		seg[i] = 1;
	}
}

void add(int sit, int value){
	seg[sit += MAX] = std::__gcd(value, k);
	for (sit >>= 1; sit; sit >>= 1){
		seg[sit] = std::__gcd(1ll * seg[sit << 1] * seg[sit << 1 | 1], 1ll * k);
	}
}

int query(int l, int r){
	int ret = 1;
	for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
		if (l & 1){
			ret = std::__gcd(1ll * ret * seg[l ++], 1ll * k);
		}
		if (r & 1){
			ret = std::__gcd(1ll * ret * seg[-- r], 1ll * k);
		}
	}
	return ret;
}

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		add(i, a[i]);
	}
	long long ans = 0;
	for (int i = 0, j = 0; i < n; ++ i){
		while (j < n && query(i, j) != k){
			++ j;
		}
		ans += n - j;
		if (j == i){
			++ j;
		}
	}
	return printf("%I64d\n", ans), 0;
}