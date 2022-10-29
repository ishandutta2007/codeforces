#include <bits/stdc++.h>
using namespace std;
const int maxn = 300010;
typedef pair<int, int> pii;
int n, m, pos[maxn], p[maxn], g[maxn];
long long ans;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", p + i);
		pos[p[i]] = i;
	}
	for (int i = 1; i <= m; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		l = pos[l]; r = pos[r];
		if (l > r) swap(l, r);
		g[r] = max(g[r], l);
	}
	int l = 0;
	for (int i = 1; i <= n; ++i) {
		l = max(l, g[i]);
		ans += i - l;
	}
	cout << ans << endl;
}