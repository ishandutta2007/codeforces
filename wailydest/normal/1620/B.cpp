#include <cstdio>
#include <algorithm>

const int N = 200000;
int t, w, h, s[4], p[4][N];

std::pair<int, int> f(int i, int x) 
{
	if (!i) return std::make_pair(x, 0);
	if (i == 1) return std::make_pair(x, h);
	if (i == 2) return std::make_pair(0, x);
	return std::make_pair(w, x);
}

long long g(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c) 
{
	long long r = (long long)(a.first - b.first) * (c.second - b.second) - (long long)(a.second - b.second) * (c.first - b.first);
	if (r < 0) r = -r;
	return r;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &w, &h);
		for (int i = 0; i < 4; ++i) {
			scanf("%d", s + i);
			for (int j = 0; j < s[i]; ++j) scanf("%d", p[i] + j);
		}
		long long ans = 0;
		for (int i = 0; i < 4; ++i) {
			std::pair<int, int> p1 = f(i, p[i][0]), p2 = f(i, p[i][s[i] - 1]);
			for (int j = 0; j < 4; ++j) if (j != i) for (int k = 0; k < s[j]; ++k) ans = std::max(ans, g(p1, p2, f(j, p[j][k])));
		}
		printf("%lld\n", ans);
	}
	return 0;
}