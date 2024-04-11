#include <cstdio>
#include <vector>
#include <utility>

const int N = 1005;
int t, n, m, pr[N];
char s[N];
std::pair<int, std::pair<int, int> > ln[2][N];

int two(char *s, int p) 
{
	return ((int)s[p] - '0') * 10 + s[p - 1] - '0';
}

int three(char *s, int p) 
{
	return ((int)s[p] - '0') * 100 + ((int)s[p - 1] - '0') * 10 + s[p - 2] - '0';
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < N; ++i) ln[0][i].first = ln[1][i].first = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%s", s);
			for (int j = 0; s[j]; ++j) {
				if (j >= 1) ln[0][two(s, j)] = std::make_pair(i + 1, std::make_pair(j - 1, j));
				if (j >= 2) ln[1][three(s, j)] = std::make_pair(i + 1, std::make_pair(j - 2, j));
			}
		}
		scanf("%s", s);
		pr[0] = 1;
		for (int i = 1; i <= m; ++i) {
			pr[i] = 0;
			if (i >= 2 && pr[i - 2] && ln[0][two(s, i - 1)].first) pr[i] = 1;
			if (i >= 3 && pr[i - 3] && ln[1][three(s, i - 1)].first) pr[i] = 2;
		}
		if (pr[m]) {
			std::vector<std::pair<int, std::pair<int, int> > > ans;
			for (int i = m; i; i -= pr[i] + 1) ans.push_back(ln[pr[i] - 1][pr[i] == 1 ? two(s, i - 1) : three(s, i - 1)]);
			printf("%d\n", (int)ans.size());
			for (int i = (int)ans.size() - 1; i >= 0; --i) printf("%d %d %d\n", ans[i].second.first + 1, ans[i].second.second + 1, ans[i].first);
		} else printf("-1\n");
	}
	return 0;
}