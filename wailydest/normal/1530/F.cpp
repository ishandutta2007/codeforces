#include <cstdio>

const int md = 31607;
int inv[md];

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
	return a * b % md;
}

inline int po(int a, int b) 
{
	int r = 1;
	while (b) {
		if (b & 1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}

inline int Inv(int a) 
{
	return po(a, md - 2);
}

inline int di(int a, int b) 
{
	return mul(a, inv[b]);
}

const int N = 21;
int n, pp[N][N], d[N + 1][2], in[N][N], prob[N], total;

void init() 
{
	for (int i = 1; i < md; ++i) inv[i] = Inv(i);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		scanf("%d", pp[i] + j);
		pp[i][j] = di(pp[i][j], 10000);
	}
}

void reset() 
{
	total = 1;
	for (int i = 0; i < n; ++i) {
		prob[i] = 1;
		for (int j = 0; j < n; ++j) {
			in[i][j] = 0;
			prob[i] = mul(prob[i], pp[i][j]);
		}
	}
}

void use(int i, int j) 
{
	if (!in[i][j]) {
		total = mul(total, pp[i][j]);
		prob[i] = di(prob[i], pp[i][j]);
	}
	++in[i][j];
}

void unuse(int i, int j) 
{
	--in[i][j];
	if (!in[i][j]) {
		total = di(total, pp[i][j]);
		prob[i] = mul(prob[i], pp[i][j]);
	}
}

int main() 
{
	init();
	int ans = 0;
	for (int dg = 0; dg < 4; ++dg) {
		reset();
		if (dg & 1) for (int i = 0; i < n; ++i) use(i, i);
		if (dg >> 1 & 1) for (int i = 0; i < n; ++i) use(i, n - i - 1);
		int cur = 0;
		for (int it = 0; it < 1 << n; ++it) {
			d[0][0] = d[0][1] = 0;
			d[0][__builtin_popcount(dg) + __builtin_popcount(cur) & 1] = 1;
			for (int i = 1; i <= n; ++i) {
				d[i][0] = add(d[i - 1][0], mul(d[i - 1][1], prob[i - 1]));
				d[i][1] = add(mul(d[i - 1][0], prob[i - 1]), d[i - 1][1]);
			}
			d[n][0] = mul(d[n][0], total);
			d[n][1] = mul(d[n][1], total);
			ans = add(ans, d[n][1]);
			ans = sub(ans, d[n][0]);
			if (it + 1 < 1 << n) {
				int next = __builtin_ctz(it + 1);
				for (int i = 0; i < n; ++i) {
					if (cur >> next & 1) unuse(i, next);
					else use(i, next);
				}
				cur ^= 1 << next;
			}
		}
	}
	printf("%d\n", add(ans, 1));
	return 0;
}