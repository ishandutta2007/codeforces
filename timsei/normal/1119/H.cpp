#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 19) + 1;
const int mod = 998244353;
const int I2 = (mod + 1) >> 1;

namespace {
	int add(int x) {return (x >= mod) ? x - mod : x;}
	int sub(int x) {return (x < 0) ? x + mod : x;}
	void Add(int &x, int y) {x = add(x + y);}
	void Sub(int &x, int y) {x = sub(x - y);}
	int Pow(int x, int y = mod - 2) {
		int res = 1;
		for(; y; y >>= 1, x = 1LL * x * x % mod)
		if(y & 1)
		res = 1LL * res * x % mod;
		return res;
	}
}

int A[N], B[N], C[N], S1[N], S2[N], S3[N], x, y, z, T[N], k, n;

void FWT(int *A) {
	for(int i = 0; i < k; ++ i) {
		for(int j = 0; j < (1 << k); j += (1 << (i + 1))) {
			for(int l = j; l < j + (1 << i); ++ l) {
				int L = A[l], R = A[l + (1 << i)];
				A[l] = add(L + R);
				A[l + (1 << i)] = sub(L - R);
			}
		}
	}
}

void IFWT(int *A) {
	for(int i = 0; i < k; ++ i) {
		for(int j = 0; j < (1 << k); j += (1 << (i + 1))) {
			for(int l = j; l < j + (1 << i); ++ l) {
				int L = A[l], R = A[l + (1 << i)];
				A[l] = 1LL * add(L + R) * I2 % mod;
				A[l + (1 << i)] = 1LL * sub(L - R) * I2 % mod;
			}
		}
	}
}

int main() {
	cin >> n >> k;
	scanf("%d%d%d", &x, &y, &z);
	int Base = 0;
	for(int i = 1; i <= n; ++ i) {
		scanf("%d%d%d", &A[i], &B[i], &C[i]);
		Base ^= A[i];
		B[i] ^= A[i];
		C[i] ^= A[i];
	}
	for(int i = 1; i <= n; ++ i) {
		++ S1[B[i]]; ++ S2[C[i]]; ++ S3[B[i] ^ C[i]];
	}
	FWT(S1); FWT(S2); FWT(S3);
	for(int i = 0; i < (1 << k); ++ i) {
		int abcd = n, cd_ab = S1[i], bd_ac = S2[i], ad_bc = S3[i];
		int ab = 1LL * sub(n - S1[i]) * I2 % mod, ac = 1LL * sub(n - S2[i]) * I2 % mod, 
		ad = 1LL * (n + S3[i]) * I2 % mod;
		int a = 1LL * sub((ab + ac + ad - abcd) % mod) * I2 % mod , b = sub(ab - a), c = sub(ac - a), d = sub(ad - a);
		T[i] = 1LL * Pow(sub((x - y - z) % mod), a) * Pow(sub(x - y + z) % mod, b) % mod
		* Pow(sub(x + y - z) % mod, c) % mod * Pow((0LL + x + y + z) % mod, d) % mod;
	}
	IFWT(T);
	for(int i = 0; i < (1 << k); ++ i) {
		printf("%d ", T[i ^ Base]);
	}
}