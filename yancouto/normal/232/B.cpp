#include <cstdio>
typedef unsigned long long ull;
const int modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
int n, k;
ull m;

ull fexp(ull a, ull x) {
	ull resp = 1;
	for(ull e = 1; e <= x; e <<= 1) {
		if(e & x) resp = mod(resp * a);
		a = mod(a * a);
	}
	return resp;
}

ull fat[105];

ull m3[103][103];
ull comb(int i, int j) {
	if(m3[i][j]) return m3[i][j] - 1;
	m3[i][j] = mod(fat[j] * fexp(mod(fat[i] * fat[j - i]), modn - 2)) + 1;
	return m3[i][j] - 1;
}

ull m2[104][104];
ull coisa(int i, int kk) {
	if(m2[i][kk]) return m2[i][kk] - 1;
	m2[i][kk] = fexp(comb(kk, n), (m / n) + (i < (m % n))) + 1;
	return m2[i][kk] - 1;
}

ull memo[103][10003];
ull solve(int i, int sum) {
	if(i == n) return sum == k;
	if(memo[i][sum]) return memo[i][sum] - 1;
	ull resp = 0;
	for(int ii = sum; ii <= k; ii++) { // O(n)
		int kk = ii - sum; // quantos
		if(kk > n) break;
		resp = mod(resp + mod(coisa(i, kk) * solve(i + 1, sum + kk)));
	}
	memo[i][sum] = resp + 1;
	return resp;
}

int main() {
	int i;
	fat[0] = 1;
	for(i = 1; i < 103; i++)
		fat[i] = mod(fat[i - 1] * i);
	scanf("%d %I64u %d", &n, &m, &k);
	printf("%I64u\n", solve(0, 0));
	return 0;
}