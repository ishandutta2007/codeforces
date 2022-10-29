#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int maxn = 1000, maxdeep = 62;
typedef long long ll;
int q, type;
ll h[65], w, u, v;
map<ll, ll> M;
int H(ll x) {
	return lower_bound(h, h + maxdeep, x) - h;
}
void modify(ll u, ll v, ll w) {
	if (H(u) < H(v)) swap(u, v);
	int hu = H(u), hv = H(v);
	while (hu > hv) {
		M[u] += w;
		u = u / 2;
		--hu;
	}
	while (u != v) {
		M[u] += w;
		M[v] += w;
		u = u / 2;
		v = v / 2;
	}
}
ll query(ll u, ll v) {
	ll ret = 0;
	if (H(u) < H(v)) swap(u, v);
	int hu = H(u), hv = H(v);
	while (hu > hv) {
		ret += M[u];
		u = u / 2;
		--hu;
	}
	while (u != v) {
		ret += M[u] + M[v];
		u = u / 2;
		v = v / 2;
	}
	return ret;
}
int main() {
	//freopen("C.in","r",stdin);
	scanf("%d", &q);
	h[0] = 1;
	for (int i = 0; i < maxdeep; ++i)
		h[i] = h[i - 1] * 2 + 1;
	for (int i = 1; i <= q; ++i) {
		cin >> type >> u >> v;
		if (type == 1) {
			cin >> w;
			modify(u, v, w);
		}
		else cout << query(u, v) << endl;
	}
}