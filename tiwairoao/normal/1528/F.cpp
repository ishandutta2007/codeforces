#include <bits/stdc++.h>

typedef long long ll;

const int K = 100000;
const int P = 998244353;

inline int norm(int x) {if (x >= P) x -= P; return x;}
inline int reduce(int x) {if (x < 0) x += P; return x;}
inline void add(int &x, int y) {if ((x += y) >= P) x -= P;}
inline void sub(int &x, int y) {if ((x -= y) < 0) x += P;}
int mpow(int b, int p) {
	int r = 1;
	for (; p; p >>= 1, b = (ll)b * b % P)
		if (p & 1) r = (ll)r * b % P;
	return r;
}

int n, k;

struct mint{
	int a, z;
	friend mint operator * (const mint &a, const mint &b) {
		return (mint){(ll)a.a * b.a % P, a.z + b.z};
	}
}pro[K + 5], ipro[K + 5];

int fct[K + 5], ifct[K + 5];
int binom(int i, int j) { // binom(n - i, j)
	mint p = pro[i + j] * ipro[i]; assert (p.z >= 0);
	return p.z ? 0 : (ll)p.a * ifct[j] % P;
}

int pwa[K + 5], pwk[K + 5];
int main() {
	scanf("%d%d", &n, &k);

	fct[0] = 1, pro[0] = (mint){1, 0};
	for (int i = 1; i <= k; i++) {
		fct[i] = (ll)fct[i - 1] * i % P;
		if (n - i + 1 == 0) pro[i] = pro[i - 1] * (mint){1, 1};
		else pro[i] = pro[i - 1] * (mint){reduce(n - i + 1), 0};
	}
	ifct[k] = mpow(fct[k], P - 2);
	ipro[k].a = mpow(pro[k].a, P - 2), ipro[k].z = -pro[k].z;
	for (int i = k; i >= 1; i--) {
		ifct[i - 1] = (ll)ifct[i] * i % P;
		if (n - i + 1 == 0) ipro[i - 1] = ipro[i] * (mint){1, 1};
		else ipro[i - 1] = ipro[i] * (mint){reduce(n - i + 1), 0};
	}
	
	int a = mpow(n + 1, P - 2);
	pwa[0] = 1; for (int i = 1; i <= k; i++) pwa[i] = (ll)pwa[i - 1] * a % P;
	for (int i = 0; i <= k; i++) pwk[i] = mpow(i, k);

	int ans = 0, tmp = 0;
	for (int i = 0; i <= k; i++) {
		int del = (ll)binom(0, i) * pwa[i] % P;
		if (i & 1) sub(tmp, del); else add(tmp, del);
	}
	for (int i = 1, iva = mpow(1 + P - a, P - 2); i <= k; i++) {
		if ((k - i + 1) & 1)
			add(tmp, (ll)binom(i - 1, k - i + 1) * pwa[k - i + 1] % P);
		else sub(tmp, (ll)binom(i - 1, k - i + 1) * pwa[k - i + 1] % P);
		if ((k - i + 1) & 1)
			sub(tmp, (ll)binom(i, k - i) * pwa[k - i + 1] % P);
		else add(tmp, (ll)binom(i, k - i) * pwa[k - i + 1] % P);
		tmp = (ll)tmp * iva % P;

/*
		tmp = 0;
		for (int j = 0; j <= k - i; j++) {
			int del = (ll)binom(i, j) * pwa[j] % P;
			if (j & 1) sub(tmp, del); else add(tmp, del);
		}
*/
		ans = (ans + (ll)tmp * binom(0, i) % P * pwk[i] % P * pwa[i]) % P;
	}
	printf("%lld\n", (ll)ans * mpow(n + 1, n) % P);
}