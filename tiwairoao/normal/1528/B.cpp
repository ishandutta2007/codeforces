#include <bits/stdc++.h>

typedef long long ll;

const int N = 1000000;
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

int f[N + 5], n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j += i)
			f[j]++;
	
	int s = 0;
	for (int i = 1; i <= n; i++)
		add(f[i], s), add(s, f[i]);
	printf("%d\n", f[n]);
}