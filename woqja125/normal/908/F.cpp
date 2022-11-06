#include<cstdio>
#include<vector>
using namespace std;
vector<int> r, g, b;
char t[10];
int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%s", &x, t);
		if (t[0] == 'R') r.push_back(x);
		if (t[0] == 'G') g.push_back(x);
		if (t[0] == 'B') b.push_back(x);
	}
	long long ans = 0;
	if (g.size() == 0) {
		if (r.size() != 0) ans += r[r.size() - 1] - r[0];
		if (b.size() != 0) ans += b[b.size() - 1] - b[0];
		printf("%lld\n", ans);
		return 0;
	}
	
	int ri = 0, bi = 0;
	for (; ri < r.size() && r[ri] < g[0]; ri++);
	for (; bi < b.size() && b[bi] < g[0]; bi++);
	if (r.size() != 0 && r[0] < g[0]) ans += g[0] - r[0];
	if (b.size() != 0 && b[0] < g[0]) ans += g[0] - b[0];

	for (int i = 1; i < g.size(); i++) {
		long long a = (g[i] - g[i - 1]);
		long long x = 3ll * a;
		
		int bf = g[i - 1];
		int max = 0;
		for (; ri < r.size() && r[ri] <= g[i]; ri++) {
			if (r[ri] - bf > max) max = r[ri] - bf;
			bf = r[ri];
		}
		if (g[i] - bf > max) max = g[i] - bf;
		x -= max;

		bf = g[i - 1];
		max = 0;
		for (; bi < b.size() && b[bi] <= g[i]; bi++) {
			if (b[bi] - bf > max) max = b[bi] - bf;
			bf = b[bi];
		}
		if (g[i] - bf > max) max = g[i] - bf;
		x -= max;
		if (x >= a * 2) x = a * 2;
		if (x >= a && (r.size() == 0 || b.size() == 0)) x = a;
		ans += x;
	}
	
	int lg = g[g.size() - 1];
	if (r.size() != 0 && r[r.size()-1] > lg) ans += r[r.size()-1] - lg;
	if (b.size() != 0 && b[b.size()-1] > lg) ans += b[b.size()-1] - lg;

	printf("%lld\n", ans);
	return 0;
}