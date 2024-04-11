#include <bits/stdc++.h>
using namespace std;
#define x first
#define p second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 212345;

int nx[N]; pii g[N];

int main() {
	ll d, n;
	int i, m;
	scanf("%I64d %I64d %d", &d, &n, &m);
	for(i = 0; i < m; i++)
		scanf("%d %d", &g[i].x, &g[i].p);
	g[m].x = d; g[m++].p = 0;
	sort(g, g + m);
	ll cur = n - g[0].x; ll tot = 0;
	for(i = m - 2; i >= 0; i--) {
		if(g[i + 1].p < g[i].p) { nx[i] = i + 1; continue; }
		nx[i] = nx[i + 1];
		while(g[nx[i]].p >= g[i].p)
			nx[i] = nx[nx[i]];
	}
	for(i = 0; i < m; i++) {
		if(cur < 0) { puts("-1"); return 0; }
		if(i == m - 1) { printf("%I64d\n", tot); return 0; }
		ll tof = min(max(ll(g[nx[i]].x - g[i].x) - cur, 0ll), n - cur);
		tot += tof * ll(g[i].p);
		cur += tof;
		cur -= ll(g[i + 1].x - g[i].x);
	}
}