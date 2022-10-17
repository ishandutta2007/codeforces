#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

#define ll long long
int n, K;
map <int, int> vis;

ll d (ll x) { return x * (x - 1) / 2; }
ll cost (ll cnt) { if (cnt <= 2) return 0; if (cnt & 1) return d(cnt >> 1) + d((cnt + 1) >> 1); else return 2 * d(cnt >> 1); }

int main () {
	vis[0] = 1; int i, j;
	n = read(), K = read(); int U = (1 << K) - 1;
	ll ans = 1ll * n * (n + 1) / 2; int pre = 0;
	for (i = 1; i <= n; i++) {
		int x = read(); pre ^= x;
		int id = pre; if ((id ^ U) < id) id ^= U;
		ans += cost(vis[id]); ans -= cost(++vis[id]);
	}
	cout << ans;
	return 0;
}