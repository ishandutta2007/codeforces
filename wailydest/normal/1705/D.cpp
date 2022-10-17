#include <cstdio>
#include <cstdlib>
#include <vector>

const int N = 200005;
int tc, n;
char s[N], t[N];

std::vector<std::pair<int, int> > get(char *s) {
	std::vector<std::pair<int, int> > res;
	for (int i = 0; i < n; ++i) if (s[i] == '1') {
		int fi = i;
		do {
			++i;
		} while (i < n && s[i] == '1');
		res.push_back(std::make_pair(fi, i));
	}
	return res;
}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%s%s", &n, s, t);
		std::vector<std::pair<int, int> > x = get(s), y = get(t);
		if (s[0] != t[0] || s[n - 1] != t[n - 1] || x.size() != y.size()) printf("-1\n");
		else {
			long long ans = 0;
			for (int i = 0; i < (int)x.size(); ++i) ans += abs(x[i].first - y[i].first) + abs(y[i].second - x[i].second);
			printf("%lld\n", ans);
		}
	}
	return 0;
}