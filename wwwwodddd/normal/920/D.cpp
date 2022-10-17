#include <bits/stdc++.h>
using namespace std;
bitset<5020> f[5020];
int n, k, v;
long long a[5020];
vector<int> p, np;
void solve(int x, int y) {
//	printf("%d %d\n", x, y);
	assert(f[x][y]);
	if (x == 0) {
		return;
	}
	if (f[x - 1][y]) {
		solve(x - 1, y);
		np.push_back(x - 1);
	} else {
		solve(x - 1, (y + k - a[x - 1] % k) % k);
		p.push_back(x - 1);
	}
}
int main() {
	f[0] = 1;
	scanf("%d%d%d", &n, &k, &v);
	int vk = v % k;
	long long sm = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		sm += a[i];
		int ak = a[i] % k;
		f[i + 1] = f[i] | (f[i] << ak) | (f[i] >> (k - ak));
	}
	if (f[n][vk] && sm >= v) {
		printf("YES\n");
		solve(n, vk);
		for (int i = 1; i < p.size(); i++) {
			printf("%d %d %d\n", (int)1e9, p[i] + 1, p[0] + 1);
			a[p[0]] += a[p[i]];
			a[p[i]] = 0;
		}
		for (int i = 1; i < np.size(); i++) {
			printf("%d %d %d\n", (int)1e9, np[i] + 1, np[0] + 1);
			a[np[0]] += a[np[i]];
			a[np[i]] = 0;
		}
		int final = -1, other = -1;
		if (p.size() == 0) {
			final = np[1];
			other = np[0];
		} else if (np.size() == 0) {
			final = p[0];
			other = p[1];
		} else {
			final = p[0];
			other = np[0];
		}
		assert((a[final] - vk) % k == 0);
		if (a[final] > v) {
			int cnt = (a[final] - v) / k;
			printf("%d %d %d\n", cnt, final + 1, other + 1);
		} else if (a[final] < v) {
			int cnt = (v - a[final]) / k;
			printf("%d %d %d\n", cnt, other + 1, final + 1);
		}
	} else {
		printf("NO\n");
	}
}