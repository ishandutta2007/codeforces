#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = N * 2;
const int mod = 998244353;

int f[N], n, m, x, y, fir[N], ne[M], to[M], cnt = 1;

void add(int x, int y) {
	ne[++ cnt] = fir[x];
	fir[x] = cnt;
	to[cnt] = y;
}

void link(int x, int y) {
	add(x, y);
	add(y, x);
}

#define Foreachson(i, x) for(int i = fir[x]; i; i = ne[i])

int d[N];

bool dfs(int x, int f, int g) {
	d[x] = 0;
	Foreachson(i, x) {
		int V = to[i];
		if(V == f) continue;
		if(!dfs(V, x, g)) return 0;
	}
	if(d[x] % g == 0) {
		if(f) ++ d[f];
		return 1;
	} else if((d[x] + 1) % g == 0) {
		if(!f) return 0;
		return 1;
	}
	return 0;
}

int main() {
	int t;
	for(cin >> t; t --;) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++ i) fir[i] = 0;
		cnt = 0;
		for(int i = 1; i <= n; ++ i) f[i] = 0;
		for(int i = 1, x, y; i < n; ++ i) {
			scanf("%d%d", &x, &y);
			link(x, y);
		}
		f[1] = 1;
		for(int i = 1; i < n; ++ i)
		f[1] = 1LL * 2 * f[1] % mod;
		int s = 0;
		for(int i = n; i >= 2; -- i) if((n - 1) % i == 0) {
			f[i] = dfs(1, 0, i);
			for(int j = i + i; j <= n; j += i) {
				f[i] = (f[i] - f[j] + mod) % mod;
			}
			s = (s + f[i]) % mod;
		}
		f[1] = (f[1] - s + mod) % mod;
		for(int i = 1; i <= n; ++ i) {
			printf("%d ", f[i]);
		}
		puts("");
	}
}