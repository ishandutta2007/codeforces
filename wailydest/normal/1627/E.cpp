#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

const int N = 100000;
int t, n, m, k, x[N], a[N], b[N], c[N], d[N], h[N];
std::vector<std::pair<int, int> > vec[N];
std::vector<std::pair<long long, int> > next[N];
bool u[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < n; ++i) {
			scanf("%d", x + i);
			vec[i].clear();
			next[i].clear();
		}
		for (int i = 0; i < k; ++i) {
			scanf("%d%d%d%d%d", a + i, b + i, c + i, d + i, h + i);
			--a[i];
			--b[i];
			--c[i];
			--d[i];
			vec[a[i]].push_back(std::make_pair(b[i], i));
		}
		for (int i = 0; i < n; ++i) std::sort(vec[i].begin(), vec[i].end());
		next[0].push_back(std::make_pair(0, 0));
		for (int i = 0; i < n - 1; ++i) {
			std::priority_queue<std::pair<long long, int> > pq;
			for (int j = 0; j < (int)next[i].size(); ++j) pq.push(next[i][j]);
			while (!pq.empty()) {
				std::pair<long long, int> cur = pq.top();
				pq.pop();
				int pos = std::lower_bound(vec[i].begin(), vec[i].end(), std::make_pair(cur.second, 0)) - vec[i].begin(), ri = pos;
				if (pos != vec[i].size() && vec[i][pos].first == cur.second) {
					if (u[pos]) continue;
					u[pos] = 1;
					do {
						int id = vec[i][ri].second;
						next[c[id]].push_back(std::make_pair(cur.first + h[id], d[id]));
						++ri;
					} while (ri < (int)vec[i].size() && vec[i][ri].first == vec[i][ri - 1].first);
				}
				--pos;
				if (pos >= 0 && pos < (int)vec[i].size()) pq.push(std::make_pair(cur.first - (long long)x[i] * (cur.second - vec[i][pos].first), vec[i][pos].first));
				if (ri >= 0 && ri < (int)vec[i].size()) pq.push(std::make_pair(cur.first - (long long)x[i] * (vec[i][ri].first - cur.second), vec[i][ri].first));
			}
			memset(u, 0, vec[i].size());
		}
		long long ans = (long long)1 << 63;
		for (int i = 0; i < (int)next[n - 1].size(); ++i) ans = std::max(ans, next[n - 1][i].first - (long long)(m - 1 - next[n - 1][i].second) * x[n - 1]);
		if (next[n - 1].empty()) printf("NO ESCAPE\n");
		else printf("%lld\n", -ans);
	}
	return 0;
}