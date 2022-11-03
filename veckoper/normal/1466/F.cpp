#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int p = 1e9 + 7;
int Case;
int n, m, fa[N];
inline int Qpow(int x, int y = p - 2) {
	int ans = 1;
	for (; y; y >>= 1, x = 1ll * x * x % p) if (y & 1) ans = 1ll * ans * x % p;
	return ans;
}
inline int Ask(int x) {
	return fa[x] < 0 ? x : fa[x] = Ask(fa[x]);
}
int main() {
	scanf("%d%d", &n, &m);
	vector<int> ans;
	memset(fa, -1, sizeof fa);
	for (int i = 1, k, x, y; i <= n; ++i) {
		scanf("%d", &k);
		if (k == 1) {
			scanf("%d", &x);
			x = Ask(x);
			if (fa[x] == -1) ans.push_back(i);
			fa[x] = -2;
		} else {
			scanf("%d%d", &x, &y);
			x = Ask(x); y = Ask(y);
			if (x == y) continue;
			if (fa[x] == -2 && fa[y] == -2) continue;
			ans.push_back(i);
			fa[x] = min(fa[x], fa[y]);
			fa[y] = x;
		}
	}
	printf("%d %d\n", Qpow(2, ans.size()), (int)ans.size());
	for (auto x: ans) printf("%d ", x);
	puts("");
	return 0;
}