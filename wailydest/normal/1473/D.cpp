#include <cstdio>
#include <algorithm>

const int N = 200000;
int t, a[N + 2], n, m, smn[N + 2], smx[N + 2], pmn[N + 2], pmx[N + 2];
char s[N + 2];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%s", &n, &m, s + 1);
		for (int i = 1; i <= n; ++i) {
			a[i] = a[i - 1] + (s[i] == '+' ? 1 : -1);
			pmn[i] = std::min(a[i], pmn[i - 1]);
			pmx[i] = std::max(a[i], pmx[i - 1]);
		}
		smn[n + 1] = smx[n + 1] = a[n];
		for (int i = n; i >= 0; --i) {
			smn[i] = std::min(smn[i + 1], a[i]);
			smx[i] = std::max(smx[i + 1], a[i]);
		}
		while (m--) {
			int l, r;
			scanf("%d%d", &l, &r);
			int mn, mx;
			mn = std::min(pmn[l - 1], smn[r + 1] - a[r] + a[l - 1]);
			mx = std::max(pmx[l - 1], smx[r + 1] - a[r] + a[l - 1]);
			printf("%d\n", mx - mn + 1);
		}
	}
	return 0;
}