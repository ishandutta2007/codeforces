#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int DEP = 61;
const LL INF = 1000000000000000000;
struct matrix {
	int v[502][502];
} ret, retf, retg, tmp, now, s, f[DEP], g[DEP];
bitset<502> R[502], C[502];
int n, m;
LL ans;
matrix merge(const matrix& lhs, const matrix& rhs) {
	matrix m;
	memset(m.v, 0, sizeof m.v);
	for (int i = 1; i <= n; ++i) R[i].reset(), C[i].reset();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			if (lhs.v[i][j]) R[i].set(j);
			if (rhs.v[i][j]) C[j].set(i);
		}
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			bitset<502> tmp = R[i] & C[j];
			if (tmp.any()) m.v[i][j] = 1; 
		}
	
	return m;
}
void prepare() {
	for (int i = 1; i < DEP; ++i) 
		f[i] = merge(f[i - 1], g[i - 1]),
		g[i] = merge(g[i - 1], f[i - 1]);
}
bool check(const matrix x) {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (x.v[i][j]) return true;
	return false;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v, t;
		scanf("%d%d%d", &u, &v, &t);
		if (!t) f[0].v[u][v] = 1;
		else g[0].v[u][v] = 1;
	}
	
	prepare();
	
	int maxdep = -1;
	for (int i = DEP; i >= 0; --i)
		if (check(f[i])) {
			maxdep = i;
			break;
		}
	if (maxdep == -1) cout << 0 << endl;
	else {
		s = f[maxdep];
		ans = 1LL << maxdep;
		for (int i = maxdep - 1, j = 0; i >= 0; --i) {
			if (j == 0) now = g[i];
			else now = f[i];
			tmp = merge(s, now);
			if (check(tmp)) {
				s = tmp;
				j ^= 1;
				ans += 1LL << i;
			}
		}
		if (ans > INF) cout << -1 << endl;
		else cout << ans << endl;
	}
}