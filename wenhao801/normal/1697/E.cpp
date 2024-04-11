#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int mod = 998244353;
union mint {
	int x;
	mint () { x = 0; }
	mint (int _x) { x = _x % mod; if (x < 0) x += mod; }
	mint operator + (const mint &t) const { return mint{x + t.x >= mod ? (x + t.x - mod) : (x + t.x)}; }
	mint operator - (const mint &t) const { return mint{x < t.x ? (x - t.x + mod) : (x - t.x)}; }
	mint operator * (const mint &t) const { return mint{1ll * x * t.x % mod}; }
	mint operator -() const { return x ? (mod - x) : x; }
	void operator += (const mint &t) { x += t.x; if (x >= mod) x -= mod; }
	void operator -= (const mint &t) { x -= t.x; if (x < 0) x += mod; }
	void operator *= (const mint &t) { x = 1ll * x * t.x % mod; }
	bool operator == (const mint &t) const { return x == t.x; }
	bool operator != (const mint &t) const { return x != t.x; }
	explicit operator int() const { return x; }
};
mint qpow (mint x, int y) { mint ret = 1; for (; y; x *= x, y >>= 1) if (y & 1) ret *= x; return ret; }
mint inv (mint x) { return qpow(x, mod - 2); }

#define pii pair <int, int>
#define fr first
#define se second

const int MAXN = 110;
int n; pii a[MAXN];

struct Edge { int u, v, w; } edge[MAXN * MAXN]; int top;
bool ban[MAXN];
mint f[MAXN], ex[MAXN], fac[MAXN], ifac[MAXN];

vector <int> E[MAXN];
vector <int> block; int ec; bool vis[MAXN];
void dfs (int x) {
	if (!vis[x]) {
		vis[x] = 1; block.push_back(x);
		for (auto i: E[x]) dfs(i), ++ec;
	}
}

int main () {
	n = read(); int i, j;
	for (i = 1; i <= n; i++) a[i].fr = read(), a[i].se = read();
	for (i = 1; i <= n; i++) for (j = 1; j < i; j++) {
		edge[++top] = {i, j, abs(a[i].fr - a[j].fr) + abs(a[i].se - a[j].se)};
	}
	sort(edge + 1, edge + top + 1, [](Edge u, Edge v) { return u.w < v.w; });
	f[0] = 1;
	for (i = 1; i <= top; i = j) {
		for (j = i; j <= top && edge[j].w == edge[i].w; j++);
		for (int k = 1; k <= n; k++) E[k].clear(), vis[k] = 0;
		for (int k = i; k < j; k++) E[edge[k].u].push_back(edge[k].v), E[edge[k].v].push_back(edge[k].u);
		for (int k = 1; k <= n; k++) if (!vis[k]) {
			block.clear(); ec = 0;
			dfs(k);
			if (block.size() == 1) continue;
			if (ec == block.size() * (block.size() - 1)) {
				bool ok = 1;
				for (auto t: block) ok &= !ban[t];
				if (ok) {
					for (int t = n; t >= 0; t--)
						ex[t] = (t >= 1 ? f[t - 1] : 0);
				}
			}
			for (auto t: block) if (!ban[t]) {
				ban[t] = 1;
				for (int u = n; u >= 0; u--) f[u] = u >= 1 ? f[u - 1] : 0;
			}
			for (int t = 0; t <= n; t++) f[t] += ex[t], ex[t] = 0;
		}
	}
	fac[0] = ifac[0] = 1;
	for (i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;
	ifac[n] = inv(fac[n]); for (i = n - 1; i >= 1; i--) ifac[i] = ifac[i + 1] * (i + 1);
	mint ans = 0;
	for (i = 0; i <= n; i++) ans += fac[n] * ifac[n - i] * f[i];
	printf("%d\n", ans);
	return 0;
}