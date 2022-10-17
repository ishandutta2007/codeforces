#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <random>
#include <ctime>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

mt19937 RND(12345);
#define pii pair<int, int>
#define ll long long
const ll lim = 2250000000000ll;

ll dis (pii x) { return 1ll * x.first * x.first + 1ll * x.second * x.second; }

int n; pii a[100100]; int out[100100];
pii add (pii x, pii y) { return make_pair(x.first + y.first, x.second + y.second); }
pii dec (pii x, pii y) { return make_pair(x.first - y.first, x.second - y.second); }
int p[100100];

int main () {
	n = read(); int i, j;
	clock_t start = clock();
	for (i = 1; i <= n; i++) a[i].first = read(), a[i].second = read(), p[i] = i;
	while (1) {
		if (1.0 * (clock() - start) / CLOCKS_PER_SEC >= 1.8) break;
		shuffle(p + 1, p + n + 1, RND);
		pii ans = make_pair(0, 0);
		for (i = 1; i <= n; i++) {
			if (dis(add(ans, a[p[i]])) <= dis(dec(ans, a[p[i]]))) ans = add(ans, a[p[i]]), out[p[i]] = 1; else ans = dec(ans, a[p[i]]), out[p[i]] = -1;
		}
		if (dis(ans) <= lim) {
			for (i = 1; i <= n; i++) cout << out[i] << ' ';
			cout << endl;
			break;
		}
	}
	return 0;
}