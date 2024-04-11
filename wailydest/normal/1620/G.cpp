#include <cstdio>
#include <algorithm>
#include <cstring>

const int md = 998244353;

inline int add(int a, int b) 
{
	a += b;
	if (a >= md) a -= md;
	return a;
}

inline int sub(int a, int b) 
{
	a -= b;
	if (a < 0) a += md;
	return a;
}

inline int mul(int a, int b) 
{
	return (long long)a * b % md;
}

const int N = 23;
const int L = 20000;
const int A = 26;
int n, a[N][A], f[1 << N], x[N + 1][A], d[1 << N][N + 1];
char s[L + 1];

void go(int ss, int l) 
{
	if (l == n) {
		if (ss) {
			f[ss] = 1;
			for (int i = 0; i < A; ++i) f[ss] = mul(f[ss], x[l][i] + 1);
			if (__builtin_popcount(ss) & 1 ^ 1) f[ss] = sub(0, f[ss]);
		}
	} else {
		memcpy(x[l + 1], x[l], A << 2);
		go(ss, l + 1);
		for (int i = 0; i < A; ++i) x[l + 1][i] = std::min(x[l + 1][i], a[l][i]);
		go(ss | 1 << l, l + 1);
	}
}

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		for (int j = 0, k = 0; s[j]; ++j) {
			while (k < s[j] - 'a') ++k;
			++a[i][k];
		}
	}
	memset(x[0], 0x3f, A << 2);
	go(0, 0);
	long long ov = 0;
	for (int i = 1; i < 1 << n; ++i) {
		int cnt = __builtin_popcount(i);
		d[i][cnt] = f[i];
		for (int j = n - 1; cnt; --j) {
			--cnt;
			while (i >> j & 1 ^ 1) --j;
			d[i][cnt] = add(d[i][cnt + 1], d[i & ~(1 << j)][cnt]);
		}
		int amt = 0, sum = 0;
		for (int j = 0; j < n; ++j) if (i >> j & 1) {
			++amt;
			sum += j + 1;
		}
		ov ^= (long long)amt * sum * d[i][0];
	}
	printf("%lld\n", ov);
	return 0;
}