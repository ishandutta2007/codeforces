#include <bits/stdc++.h>

typedef long long ll;

const int N = 300;
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

std::vector<int>G[N + 5]; int n;
void adde(int u, int v) {
	G[u].push_back(v), G[v].push_back(u);
}

int d;
int f[N + 5][N + 5], g[N + 5][N + 5];
int sf[N + 5][N + 5], sg[N + 5][N + 5];
void dfs(int x, int fa) {
	for (int i = 0; i <= d; i++) f[x][i] = g[x][i] = 0;

	sf[x][d] = f[x][d] = g[x][0] = 1;
	for (int i = 0; i < d; i++) sf[x][i] = 0;
	for (int i = 0; i <= d; i++) sg[x][i] = 1;
	for (auto to : G[x]) if (to != fa) {
		dfs(to, x);

		static int tg[N + 5], tf[N + 5];
		static int stg[N + 5], stf[N + 5];
		for (int i = 0; i <= d; i++) {
			tf[i] = f[x][i], f[x][i] = 0, tg[i] = g[x][i], g[x][i] = 0;
			stf[i] = sf[x][i], stg[i] = sg[x][i];
		}
		
		for (int i = 0; i <= d; i++) {
			add(f[x][i], (ll)tf[i] * sf[to][i] % P);
			add(g[x][i], (ll)tg[i] * sf[to][i] % P);
			if (!i) continue;

			add(g[x][i], (ll)stf[i - 1] * g[to][i - 1] % P);
			add(g[x][i], (ll)stg[i - 1] * g[to][i - 1] % P);

			add(f[x][i], (ll)tf[i] * sg[to][i - 1] % P);
			add(g[x][i], (ll)tg[i] * sg[to][i - 1] % P);

			add(f[x][i - 1], (ll)stf[i - 1] * f[to][i] % P);
			add(f[x][i - 1], (ll)stg[i - 1] * f[to][i] % P);
		}

		for (int i = 0; i <= d; i++) {
			sf[x][i] = i ? norm(sf[x][i - 1] + f[x][i]) : f[x][i];
			sg[x][i] = i ? norm(sg[x][i - 1] + g[x][i]) : g[x][i];
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++)
		scanf("%d%d", &u, &v), adde(u, v);
	
	int sum = 0;
	for (d = 0; d <= n; d++) {
		dfs(1, 0), sub(sum, sf[1][d]);
		// printf("%d : %d\n", d, sf[1][d]);
	}
	printf("%lld\n", (n + (ll)sum * mpow(2, P - 1 - n)) % P);
}