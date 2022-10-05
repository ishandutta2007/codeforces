#include<bits/stdc++.h>

const int N = 1 << 20;
const int moder = 1e9 + 7;
const int inv2 = 5e8 + 4;

int f[N], g[N], a[20][100010];
int n, m;


void trans(int *a, int length){
	for(int i = 1, j = 0; i < length - 1; ++ i){
		for(int s = length; j ^= s >>= 1, ~j & s; );
		if(i < j){
			std::swap(a[i], a[j]);
		}
	}
}

void FWT_XOR(int *a, int length, int type){
	int len = -1;
	for (int x = length; x; ++ len, x >>= 1);
	trans(a, length);
	for (int i = 1; i <= len; ++ i){
		for (int j = 0; j < length; j += 1 << i){
			for (int k = j, sizk = 1 << i - 1; k < j + sizk; ++ k){
				int s = a[k], t = a[k + (1 << i - 1)];
				int x = type == 1 ? 1 : inv2;
				a[k] = 1ll * (s + t) * x % moder;
				a[k + (1 << i - 1)] = 1ll * (s - t + moder) * x % moder;
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < m; ++ j){
			scanf("%1d", &a[i][j]);
		}
	}
	for (int i = 0; i < m; ++ i){
		int x = 0;
		for (int j = 0; j < n; ++ j){
			x = x << 1 | a[j][i];
		}
		++ f[x];
	}
	for (int i = 0; i < 1 << n; ++ i){
		int cnt = 0;
		for (int j = 0; j < n; ++ j){
			if (i >> j & 1){
				++ cnt;
			}
		}
		g[i] = std::min(cnt, n - cnt);
	}
	FWT_XOR(f, 1 << n, 1);
	FWT_XOR(g, 1 << n, 1);
	for (int i = 0; i < 1 << n; ++ i){
		f[i] = 1ll * f[i] * g[i] % moder;
	}
	FWT_XOR(f, 1 << n, -1);
	int min = INT_MAX;
	for (int i = 0; i < 1 << n; ++ i){
		min = std::min(min, f[i]);
	}
	return printf("%d\n", min), 0;
}