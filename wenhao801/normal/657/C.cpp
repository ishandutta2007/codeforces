#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

int n, K, b, c;

using ll = long long;
using pii = pair <int, int>;
#define fr first
#define se second
vector <pii> vec[5];

priority_queue <ll> pq;
int main() {
	n = read(), K = read(), b = read(), c = read();
	int i, j;
	b = min(b, 5 * c);
	for (i = 1; i <= n; i++) {
		int x = read() + 1e9, ex = 0;
		for (j = 0; j < 5; j++, ex += c) {
			vec[((x + j) % 5 + 5) % 5].push_back({(x + j) / 5, ex});
		}
	}
	ll ans = 1e18;
	for (i = 0; i < 5; i++) {
		sort(vec[i].begin(), vec[i].end());
		ll cur = 0;
		for (auto j: vec[i]) {
			pq.push(j.se - 1ll * j.fr * b); cur += j.se - 1ll * j.fr * b;
			if (pq.size() > K) cur -= pq.top(), pq.pop();
			if (pq.size() >= K) ans = min(ans, cur + 1ll * j.fr * b * K);
		}
		while (!pq.empty()) pq.pop();
	}
	printf("%lld\n", ans);
	return 0;
}