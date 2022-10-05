#include<bits/stdc++.h>

template <typename T>
T read(){
	char ch;
	ch = getchar();
	while (ch < '0' || ch > '9'){
		ch = getchar();
	}
	T ret = 0;
	while (ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret;
}

const int MAX = 17;
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

void FWT_AND(int *a, int length, int type){
	int len = -1;
	for (int x = length; x; ++ len, x >>= 1);
	for (int i = 1; i <= len; ++ i){
		for (int j = 0; j < length; j += 1 << i){
			for (int k = j, szk = 1 << i - 1; k < j + szk; ++ k){
				a[k] = (a[k] + 1ll * type * a[k + szk] + moder) % moder;
			}
		}
	}
}

void FWT_OR(int *a, int length, int type){
	int len = -1;
	for (int x = length; x; ++ len, x >>= 1);
	for (int i = 1; i <= len; ++ i){
		for (int j = 0; j < length; j += 1 << i){
			for (int k = j, szk = 1 << i - 1; k < j + szk; ++ k){
				a[k + szk] = (a[k + szk] + 1ll * type * a[k] + moder) % moder;
			}
		}
	}
}

typedef long long ll;

int s[1 << MAX];
ll zzh[1 << MAX];
int a[1 << MAX], b[1 << MAX], f[1 << MAX], ans[1 << MAX];
int digit[MAX + 10];

int main(){
	int n = read <int>();
	for (int i = 0, x; i < n; ++ i){
		x = read <int>();
		++ s[x];
	}
	zzh[0] = 1ll * s[0] * s[0] % moder;
	for (int i = 1; i < 1 << MAX; ++ i){
		int cnt = 0;
		for (int j = 0; j < MAX; ++ j){
			if (i >> j & 1){
				digit[cnt ++] = j;
			}
		}
		for (int j = 0; j < 1 << cnt - 1; ++ j){
			int x = 0;
			for (int k = 0; k < cnt; ++ k){
				if (j >> k & 1){
					x |= 1 << digit[k];
				}
			}
			zzh[i] += 2ll * s[x] * s[i ^ x];
		}
	}
	for (int i = 0; i < 1 << MAX; ++ i){
		a[i] = zzh[i] % moder;
	}
	FWT_XOR(s, 1 << MAX, 1);
	for (int i = 0; i < 1 << MAX; ++ i){
		b[i] = 1ll * s[i] * s[i] % moder;
	}
	FWT_XOR(s, 1 << MAX, -1);
	FWT_XOR(b, 1 << MAX, -1);
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i < 1 << MAX; ++ i){
		f[i] = (f[i - 2] + f[i - 1]) % moder;
	}
	for (int i = 0; i < 1 << MAX; ++ i){
		a[i] = 1ll * a[i] * f[i] % moder;
		b[i] = 1ll * b[i] * f[i] % moder;
		s[i] = 1ll * s[i] * f[i] % moder;
	}
	FWT_AND(a, 1 << MAX, 1);
	FWT_AND(b, 1 << MAX, 1);
	FWT_AND(s, 1 << MAX, 1);
	for (int i = 0; i < 1 << MAX; ++ i){
		ans[i] = 1ll * a[i] * b[i] % moder * s[i] % moder;
	}
	FWT_AND(ans, 1 << MAX, -1);
	int ret = 0;
	for (int i = 0; i < MAX; ++ i){
		ret = (ret + ans[1 << i]) % moder;
	}
	printf("%d\n", ret);
	return 0;
}