#include<queue>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 100005;

int n, m;

vector<pair<int, int> > edge[N];

long long dis[N];

int fa[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v, l;
		scanf("%d%d%d", &u, &v, &l);
		--u, --v;
		edge[u].push_back(make_pair(v, l));
		edge[v].push_back(make_pair(u, l));
	}
	for (int i = 0; i < n; ++i) {
		dis[i] = -1;
	}
	priority_queue<pair<long long, int>,
				   vector<pair<long long, int> >,
				   greater<pair<long long, int> > > heap;
	dis[0] = 0;
	heap.push(make_pair(dis[0], 0));
	while (heap.size() > 0) {
		long long d = heap.top().first;
		int u = heap.top().second;
		heap.pop();
		if (d > dis[u]) {
			continue;
		}
		for (int i = 0; i < (int)edge[u].size(); ++i) {
			int v = edge[u][i].first, l = edge[u][i].second;
			long long nd = d + l;
			if (dis[v] == -1 || nd < dis[v]) {
				dis[v] = nd;
				fa[v] = u;
				heap.push(make_pair(nd, v));
			}
		}
	}
	if (dis[n - 1] == -1) {
		printf("-1\n");
	} else {
		vector<int> path;
		{
			int u = n - 1;
			while (u != 0) {
				path.push_back(u);
				u = fa[u];
			}
			path.push_back(u);
			reverse(path.begin(), path.end());
		}
		for (int i = 0; i < (int)path.size(); ++i) {
			printf("%d%c", path[i] + 1, i == (int)path.size() - 1 ? '\n' : ' ');
		}
	}
	return 0;
}