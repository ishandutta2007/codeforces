# include <stdio.h>
# include <string.h>
# include <iostream>
# include <algorithm>
// # include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int M = 5e5 + 10;
const int mod = 1e9+7;

# define RG register
# define ST static

int n;
int head[M], nxt[M], to[M], w[M], tot=0;
inline void add(int u, int v, int _w) {
	++tot; nxt[tot] = head[u]; head[u] = tot; to[tot] = v;
	w[tot] = _w;
}
inline void adde(int u, int v, int _w) {
	add(u, v, _w), add(v, u, _w);
}

ll d[M];
inline void dfs(int x, int fa=0, ll di=0) {
	d[x] = di;
	for (int i=head[x]; i; i=nxt[i]) {
		if(to[i] == fa) continue;
		dfs(to[i], x, di + w[i]);
	}
}

int main() {
	cin >> n;
	for (int i=1, u, v, _w; i<n; ++i) {
		scanf("%d%d%d", &u, &v, &_w);
		++u, ++v;
		adde(u, v, _w);
	}
	ll ans = 0;
	dfs(1);
	for (int i=2; i<=n; ++i) ans = max(ans, d[i]);
	cout << ans << endl;
	return 0;
}