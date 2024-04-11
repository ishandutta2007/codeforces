#include <cstdio>
#include <utility>
#include <algorithm>

int ask(int i, int j, int k) {
	printf("? %d %d %d\n", i + 1, j + 1, k + 1);
	fflush(stdout);
	int re;
	scanf("%d", &re);
	return re;
}

int t, n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		std::pair<int, int> mx(-1, 0);
		bool same = 1;
		for (int i = 2; i < n; ++i) {
			int k = ask(0, 1, i);
			if (mx.first != -1 && k != mx.first) same = 0;
			mx = std::max(mx, std::make_pair(k, i));
		}
		std::pair<int, int> mx1 = std::make_pair(ask(0, 1, mx.second), -1);
		bool eq = 1;
		for (int i = 2; i < n; ++i) if (i != mx.second) {
			int k = ask(0, i, mx.second);
			if (k != mx1.first) eq = 0;
			mx1 = std::max(mx1, std::make_pair(k, i));
		}
		if (same && mx1.first <= mx.first) printf("! 1 2\n");
		else printf("! %d %d\n", mx.second + 1, mx1.second == -1 ? 2 : (eq ? 1 : mx1.second + 1));
		fflush(stdout);
	}
	return 0;
}