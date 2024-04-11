#include <cstdio>
#include <algorithm>

const int N = 100000;
int t, n;
char s[2 * N + 1];

void apply(int l, int r) {
	std::reverse(s + l, s + r);
}

bool test() {
	int d = 0;
	for (int i = 0; s[i]; ++i) {
		d += s[i] == '(' ? 1 : -1;
		if (d < 0) return 0;
	}
	return 1;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%s", &n, s);
		if (test()) printf("0\n");
		else {
			int d = 0, mx = 0, p = -1, opt = 3;
			for (int i = 0; s[i] && d >= 0; ++i) {
				d += s[i] == '(' ? 1 : -1;
				if (d > mx) {
					mx = d;
					p = i;
				}
			}
			d = 0;
			int mx1 = 0, p1 = 2 * n;
			for (int i = 2 * n - 1; d >= 0; --i) {
				d += s[i] == ')' ? 1 : -1;
				if (d > mx1) {
					mx1 = d;
					p1 = i;
				}
			}
			apply(p + 1, p1);
			if (test()) printf("1\n%d %d\n", p + 2, p1);
			else {
				apply(p + 1, p1);
				int mx = 0, p = 0, d = 0;
				for (int i = 0; s[i]; ++i) {
					d += s[i] == '(' ? 1 : -1;
					if (d > mx) {
						mx = d;
						p = i;
					}
				}
				apply(0, p + 1);
				apply(p + 1, 2 * n);
				if (!test()) return 1;
				printf("2\n%d %d\n%d %d\n", 1, p + 1, p + 2, 2 * n);
			}
		}
	}
	return 0;
}