#include <bits/stdc++.h>

#define MAXN (1000000)
#define MAXM (6)
#define mod (1000000007)
#define ll long long

int n;
int a[MAXN], b[MAXN], c[MAXN], f[MAXN], pow10[MAXM + 2];

void FWT(int *a, int length, int len){
	for(int i = 1; i <= len; ++ i){
		for(int j = 0; j < length; j += pow10[i]){
			for(int k = j, sz = pow10[i - 1]; k < j + sz; ++ k){
				for(int p = 8; p >= 0; -- p){
					int &x = a[k + p * sz];
					x = (x + a[k + (p + 1) * sz]) % mod;
				}
			}
		}
	}
}

void UFWT(int *a, int length, int len){
	for(int i = 1; i <= len; ++ i){
		for(int j = 0; j < length; j += pow10[i]){
			for(int k = j, sz = pow10[i - 1]; k < j + sz; ++ k){
				for(int p = 0; p <= 8; ++ p){
					int &x = a[k + p * sz];
					x = (x - a[k + (p + 1) * sz] + mod) % mod;
				}
			}
		}
	}
}

int powmod(int a, int b){
	int ret = 1;
	while(b){
		if(b & 1) ret = 1ll * ret * a % mod;
		b >>= 1;
		a = 1ll * a * a % mod;
	}
	return ret;
}

int main(){
	pow10[0] = 1;
	for(int i = 1; i <= MAXM; ++ i){
		pow10[i] = pow10[i - 1] * 10;
	}
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i){
		int x;
		scanf("%d", &x);
		a[x] = (a[x] + 1) % mod;
		b[x] = (b[x] + x) % mod;
		c[x] = (c[x] + 1ll * x * x) % mod;
	}
	FWT(a, MAXN, MAXM);
	FWT(b, MAXN, MAXM);
	FWT(c, MAXN, MAXM);
	
	for(int i = 0; i < MAXN; ++ i){
		if(!a[i]) continue;
		if(a[i] == 1){
			f[i] = c[i];
			continue;
		}
		f[i] = (1ll * b[i] * b[i] + c[i]) % mod * powmod(2, a[i] - 2) % mod;
	}
	
	UFWT(f, MAXN, MAXM);
	
	ll ans = 0;
	for(int i = 0; i < MAXN; ++ i){
		ans ^= 1ll * f[i] * i;
	}
	printf("%I64d\n", ans);
	return 0;
}