#include <cstdio>

const int N = 200000;
int t, n, a[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		bool ok = 1;
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		int last;
		for (last = n - 1; last >= 0 && !a[last]; --last);
		if (last >= 0) {
			--a[0];
			++a[last];
			long long next = 0;
			for (int i = 0; i < n; ++i) {
				if (next > a[i]) ok = 0;
				next = next - a[i];
			}
			if (next) ok = 0;
		}
		printf("%s\n", ok ? "Yes" : "No");
	}
	return 0;
}