#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

ull fexp(ull x, ull p) {
	ull resp = 1;
	for(ull i = 1; i <= p; i <<= 1) {
		if(i & p) resp = mod(resp * x);
		x = mod(x * x);
	}
	return resp;
}

ull fat[1000009];

ull comb(int n, int p) {
	if(n < p) return 0;
	return mod(fat[n] * fexp(mod(fat[p] * fat[n - p]), modn - 2));
}

int n, k;
ull cmb[100009];
ull pot[100009];
void pre() {
	fat[0] = 1;
	for(ull i = 1; i < 100009; i++)
		fat[i] = mod(fat[i - 1] * i);
	ull h = 1; int i;
	for(i = n - 2; i >= 0; i--) {
		cmb[i] = mod(comb(i, k - 1) * h);
		cmb[i] = mod(cmb[i] + cmb[i + 1]);
		h = mod(h * 10ull);
	}
	pot[0] = 1;
	for(i = 1; i <= n + 1; i++)
		pot[i] = mod(pot[i - 1] * 10ull);
}

char str[100009];
int main() {
	int i;
	scanf("%d %d %s", &n, &k, str);
	pre();
	ull tot = 0;
	for(i = 0; i < n; i++) {
		ull val = mod((str[i] - '0') * (cmb[i] + mod(pot[n - (i + 1)] * comb(i, k))));
		tot = mod(tot + val);
	}
	printf("%I64u\n", tot);
}