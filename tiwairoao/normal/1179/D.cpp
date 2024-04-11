#include <bits/stdc++.h>

typedef long long ll;

const int N = 500000;

std::vector<int>G[N + 5]; int n; ll ans;
void adde(int u, int v) {G[u].push_back(v), G[v].push_back(u);}

struct point{
	int x; ll y;
	friend bool operator < (const point &a, const point &b) {
		return (a.x == b.x) ? (a.x < b.x) : (a.y < b.y);
	}
}a[N + 5], b[N + 5]; int m;

void solve() {
	std::sort(a + 1, a + m + 1);
	
	int tp = 0;
	for(int i=1;i<=m;i++) {
		while( tp > 1 && b[tp].y + 2ll * a[i].x * b[tp].x > b[tp - 1].y + 2ll * a[i].x * b[tp - 1].x )
			tp--;
		if( tp ) ans = std::min(ans, a[i].y + b[tp].y + 2ll * a[i].x * b[tp].x);
		
		while( tp > 1 && (b[tp].y - b[tp - 1].y) * (a[i].x - b[tp].x) > (a[i].y - b[tp].y) * (b[tp].x - b[tp - 1].x) )
			tp--;
		b[++tp] = a[i];
	}
}

int s[N + 5]; ll f[N + 5];
ll pw2(ll x) {return x * x;}
void dfs(int x, int fa) {
	s[x] = 1; for(auto to : G[x]) if( to != fa ) dfs(to, x), s[x] += s[to];
	
	f[x] = pw2(s[x]), m = 0;
	for(auto to : G[x]) if( to != fa ) {
		ll t = f[to] + pw2(s[to]) - 2ll * n * s[to];
		a[++m] = (point){s[to], t}, ans = std::min(ans, t);
		
		f[x] = std::min(f[x], f[to] + pw2(s[x] - s[to]));
	}
	solve();
}

int read() {
	int x = 0, ch = getchar();
	while( ch < '0' || ch > '9' ) ch = getchar();
	while( '0' <= ch && ch <= '9' ) x = 10 * x + ch - '0', ch = getchar();
	return x;
}

int main() {
	n = read();
	for(int i=1,u,v;i<n;i++) u = read(), v = read(), adde(u, v);
	dfs(1, 0), printf("%lld\n", (pw2(n) - n - ans) / 2);
}