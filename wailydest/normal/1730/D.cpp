#include <cstdio>
#include <utility>
#include <cstring>

const int N = 100005;
const int A = 26;
int tt, cnt[A][A], n;
char s[N], t[N];

int main() {
	scanf("%d", &tt);
	while (tt--) {
		memset(cnt, 0, sizeof cnt);
		scanf("%d%s%s", &n, s, t);
		for (int i = 0; i < n; ++i) {
			int x = s[i] - 'a', y = t[n - i - 1] - 'a';
			if (x > y) std::swap(x, y);
			++cnt[x][y];
		}
		int r = 0, rr = 0;
		for (int i = 0; i < A; ++i) for (int j = 0; j < A; ++j) {
			r += cnt[i][j] & 1;
			rr += cnt[i][j] & 1 && i == j;
		}
		printf("%s\n", r > 1 || r == 1 && (!rr || n & 1 ^ 1) ? "NO" : "YES");
	}
	return 0;
}