#include <cstdio>
#include <vector>

const int N = 200005;
int t, n, a[N];
char s[N + 1];

struct bit {
	std::vector<int> b;
	void add(int i) {
		while (i <= n * 2) {
			++b[i];
			i |= i + 1;
		}
	}

	int get(int i) {
		int s = 0;
		while (i >= 0) {
			s += b[i];
			i = (i & i + 1) - 1;
		}
		return s;
	}
} b[3];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%s", &n, s);
		long long ans = 0;
		int r = 0;
		for (int i = 0; i < 3; ++i) b[i].b.assign(n * 2 + 1, 0);
		b[n % 3].add(n);
		for (int i = 0; s[i]; ++i) {
			if (s[i] == '+') --r;
			else ++r;
			ans += b[(n + r) % 3].get(n + r);
			b[(n + r) % 3].add(n + r);
		}
		printf("%lld\n", ans);
	}
	return 0;
}