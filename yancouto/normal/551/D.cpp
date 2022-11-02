#ifndef ONLINE_JUDGE
#define debug(...) {fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, __VA_ARGS__);}
#else
#define debug(...) //
#endif
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define mod(x) ((x) % modn)
typedef unsigned long long ull;
ull modn;

ull poww(ull x, ull n) {
	x = mod(x); 
	ull tot = 1;
	for(ull i = 1; i <= n; i <<= 1) {
		//debug("x: %I64u i & n: %I64u\n", x, i & n);
		if(i & n) tot = mod(tot * x);
		x = mod(x * x);
		//debug("tot: %I64u\n", tot);
	}
	return tot;
}

void cp(ull x[2][2], ull y[2][2]) {
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			y[i][j] = x[i][j];
}

void mult(ull x[2][2], ull y[2][2], ull z[2][2]) {
	z[0][0] = mod(mod(x[0][0] * y[0][0]) + mod(x[0][1] * y[1][0]));
	z[0][1] = mod(mod(x[0][0] * y[0][1]) + mod(x[0][1] * y[1][1]));
	z[1][0] = mod(mod(x[1][0] * y[0][0]) + mod(x[1][1] * y[1][0]));
	z[1][1] = mod(mod(x[1][0] * y[0][1]) + mod(x[1][1] * y[1][1]));
}

void poww(ull x[2][2], ull n, ull c[2][2]) {
	c[0][0] = 1; c[0][1] = 0;
	c[1][0] = 0; c[1][1] = 1;
	ull aux[2][2];
	for(ull i = 1; i <= n; i <<= 1) {
		if(i & n) {
			mult(c, x, aux);
			cp(aux, c);
		}
		mult(x, x, aux);
		cp(aux, x);
	}
}

int main() {
	ull n, k;
	int l, i;
	scanf("%I64u %I64u %d %I64u", &n, &k, &l, &modn);
	if((l < 64 && k >= (1ull << l)) || modn == 1) { puts("0"); return 0; }
	ull m_fib[2][2] = {{0, 1}, {1, 1}};
	ull fin[2][2];
	poww(m_fib, n - 1, fin);
	ull all_0 = mod(fin[0][0] + fin[0][1] + fin[1][0] + fin[1][1]);
	ull all_any = poww(2ull, n);
	debug("n: %I64u all_0: %I64u  all_any: %I64u\n", n, all_0, all_any);

	ull total = 1;
	for(i = 0; i < l; i++) {
		bool kk = ((k & (1ull << i)) > 0);
		if(kk) total = mod(total * mod(all_any - all_0 + modn));
		else total = mod(total * all_0);
	}
	printf("%I64u\n", total);
	return 0;
}