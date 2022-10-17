#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

const int N = 200005;
int t, n, m;
long long a[N];
std::pair<int, int> s[N];
std::vector<int> out[N];
bool u[N], rmd[N];

std::set<int> active;

void use(int i);

void rm(int i) {
	active.erase(i);
	rmd[i] = 1;
	for (int j = 0; j < (int)out[i].size(); ++j) if (!u[out[i][j]] && rmd[s[out[i][j]].first] && rmd[s[out[i][j]].second]) use(out[i][j]);
}

void use(int i) {
	u[i] = 1;
	std::set<int>::iterator it;
	while (it = active.lower_bound(s[i].first), it != active.end() && *it < s[i].second) rm(*it);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		active.clear();
		for (int i = 0; i <= n; ++i) {
			rmd[i] = 0;
			active.insert(i);
			out[i].clear();
		}
		for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
		for (int i = 1; i <= n; ++i) {
			int x;
			scanf("%d", &x);
			a[i] = a[i - 1] + a[i] - x;
		}
		for (int i = 0; i < m; ++i) {
			u[i] = 0;
			scanf("%d%d", &s[i].first, &s[i].second);
			--s[i].first;
			out[s[i].first].push_back(i);
			out[s[i].second].push_back(i);
		}
		for (int i = 0; i <= n; ++i) if (!a[i] && !rmd[i]) rm(i);
		printf("%s\n", active.empty() ? "YES" : "NO");
	}
	return 0;
}