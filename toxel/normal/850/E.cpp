#include<bits/stdc++.h>

const int moder = 1e9 + 7;
const int inv2 = 5e8 + 4;

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

void FWT_XOR(int *a, int length, int type){
	int len = -1;
	for (int x = length; x; ++ len, x >>= 1);
	for (int i = 1; i <= len; ++ i){
		for (int j = 0; j < length; j += 1 << i){
			for (int k = j, szk = 1 << i - 1; k < j + szk; ++ k){
				int s = a[k], t = a[k + szk];
				a[k] = s + t >= moder ? s + t - moder : s + t;
				a[k + szk] = s - t < 0 ? s - t + moder : s - t;
			}
		}
	}
	if (type == 1) return;
	int inv = powermod(length, moder - 2);
	for (int i = 0; i < length; ++ i){
		a[i] = 1ll * a[i] * inv % moder;
	}
}

const int N = 1 << 21;

char s[N];
int a[N], bitcnt[N];

int main(){
	int n;
	scanf("%d", &n);
	gets(s);
	gets(s);
	for (int i = 0; i < 1 << n; ++ i){
		a[i] = s[i] - '0';
	}
	FWT_XOR(a, 1 << n, 1);
	for (int i = 0; i < 1 << n; ++ i){
		a[i] = 1ll * a[i] * a[i] % moder;
	}
	FWT_XOR(a, 1 << n, -1);
	int ans = 0;
	for (int i = 1; i < 1 << n; ++ i){
		bitcnt[i] = bitcnt[i ^ (i & (-i))] + 1;
	}
	for (int i = 0; i < 1 << n; ++ i){
		ans = (ans + 1ll * powermod(2, n - bitcnt[i]) * a[i]) % moder;
	}
	ans = 3ll * ans % moder;
	return printf("%d\n", ans), 0;
}