#include <cstdio>
#include <algorithm>

const int N = 100000;
int tt, n;
char s[N + 1], t[N + 1];

int main() 
{
	scanf("%d", &tt);
	while (tt--) {
		scanf("%d%s%s", &n, s, t);
		int amt1 = 0, amt2 = 0;
		for (int i = 0; i < n; ++i) amt1 += s[i] - '0';
		for (int i = 0; i < n; ++i) amt2 += t[i] - '0';
		int ans = ~(1 << 31);
		if (amt1 == amt2) {
			ans = 0;
			for (int i = 0; i < n; ++i) ans += s[i] != t[i];
		}
		amt1 = 0;
		for (int i = 0; i < n; ++i) {
			s[i] = '0' + !(s[i] - '0');
			amt1 += s[i] - '0';
		}
		if (amt1 + 1 == amt2) {
			int r = 0;
			for (int i = 0; i < n; ++i) r += s[i] != t[i];
			ans = std::min(ans, r);
		}
		if (ans == ~(1 << 31)) printf("-1\n");
		else printf("%d\n", ans);
	}
	return 0;
}