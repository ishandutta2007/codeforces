#include<cmath>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MOD = 1000000007;

const double PI = acos(-1);

typedef complex<double> Complex;

const int N = 65536, L = 15, MASK = (1 << L) - 1;

Complex w[N];

void FFTInit() {
	for (int i = 0; i < N; ++i) {
		w[i] = Complex(cos(2 * i * PI / N), sin(2 * i * PI / N));
	}
}

void FFT(Complex p[], int n) {
	for (int i = 1, j = 0; i < n - 1; ++i) {
		for (int s = n; j ^= s >>= 1, ~j & s;);
		if (i < j) {
			swap(p[i], p[j]);
		}
	}
	for (int d = 0; (1 << d) < n; ++d) {
		int m = 1 << d, m2 = m * 2, rm = n >> (d + 1);
		for (int i = 0; i < n; i += m2) {
			for (int j = 0; j < m; ++j) {
				Complex &p1 = p[i + j + m], &p2 = p[i + j];
				Complex t = w[rm * j] * p1;
				p1 = p2 - t;
				p2 = p2 + t;
			}
		}
	}
}

Complex A[N], B[N], C[N], D[N];

void mul(int a[N], int b[N], int k = N) {
	for (int i = 0; i < k; ++i) {
		A[i] = Complex(a[i] >> L, a[i] & MASK);
		B[i] = Complex(b[i] >> L, b[i] & MASK);
	}
	for (int i = k; i < N; ++i) {
		A[i] = B[i] = Complex(0, 0);
	}
	FFT(A, N);
	FFT(B, N);
	for (int i = 0; i < N; ++i) {
		int j = (N - i) % N;
		Complex da = (A[i] - conj(A[j])) * Complex(0, -0.5),
				db = (A[i] + conj(A[j])) * Complex(0.5, 0),
				dc = (B[i] - conj(B[j])) * Complex(0, -0.5),
				dd = (B[i] + conj(B[j])) * Complex(0.5, 0);
		C[j] = da * dd + da * dc * Complex(0, 1);
		D[j] = db * dd + db * dc * Complex(0, 1);
	}
	FFT(C, N);
	FFT(D, N);
	for (int i = 0; i < N; ++i) {
		long long da = (long long)(C[i].imag() / N + 0.5) % MOD,
				  db = (long long)(C[i].real() / N + 0.5) % MOD,
				  dc = (long long)(D[i].imag() / N + 0.5) % MOD,
				  dd = (long long)(D[i].real() / N + 0.5) % MOD;
		a[i] = ((dd << (L * 2)) + ((db + dc) << L) + da) % MOD;
	}
}

const int K = 30005;

int fac[K], inv[K];

int inverse(int a) {
	return a == 1 ? a : (long long)(MOD - MOD / a) * inverse(MOD % a) % MOD;
}

int binom(int n, int m) {
	return (long long)fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int k;

int TA[N], TB[N];

int powMod(int a, int n) {
	int ret = 1;
	while (n) {
		if (n & 1) {
			ret = (long long)ret * a % MOD;
		}
		a = (long long)a * a % MOD;
		n >>= 1;
	}
	return ret;
}

void trans(int a[N], int b[N], int l) {
	for (int i = 0; i <= k; ++i) {
		TA[i] = (long long)a[i] * inv[i] % MOD * powMod(2, (long long)i * l % (MOD - 1)) % MOD;
		TB[i] = (long long)b[i] * inv[i] % MOD;
	}
	mul(TA, TB, k + 1);
	for (int i = 0; i <= k; ++i) {
		a[i] = (long long)TA[i] * fac[i] % MOD;
	}
}

int a[N], b[N];

int main() {
	FFTInit();
	long long n;
	cin >> n >> k;
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= k; ++i) {
		fac[i] = (long long)fac[i - 1] * i % MOD;
		inv[i] = inverse(fac[i]);
	}
	memset(a, 0, sizeof(a));
	a[0] = 1;
	memset(b, 0, sizeof(b));
	for (int i = 1; i <= k; ++i) {
		b[i] = 1;
	}
	long long l = 1;
	while (n) {
		if (n & 1) {
			trans(a, b, l);
		}
		trans(b, b, l);
		(l <<= 1) %= (MOD - 1);
		n >>= 1;
	}
	int ans = 0;
	for (int i = 0; i <= k; ++i) {
		(ans += (long long)a[i] * binom(k, i) % MOD) %= MOD;
	}
	printf("%d\n", ans);
}