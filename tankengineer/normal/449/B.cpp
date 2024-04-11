#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const long long INF = 1ll << 60;

const int N = 100005;

vector<pair<int, int> > edge[N];

long long dis[N];

bool train[N];

int n, m, k;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		--u, --v;
		edge[u].push_back(make_pair(v, w));
		edge[v].push_back(make_pair(u, w));
	}
	for (int i = 0; i < n; ++i) {
		dis[i] = INF;
	}
	dis[0] = 0;
	for (int i = 0; i < k; ++i) {
		int v, x;
		scanf("%d%d", &v, &x);
		--v;
		dis[v] = min(dis[v], (long long)x);
		train[v] = true;
	}
	priority_queue<pair<long long, int> > heap;
	for (int i = 0; i < n; ++i) {
		if (dis[i] != INF) {
			heap.push(make_pair(-dis[i], i));
		}
	}
	while (heap.size()) {
		int u = heap.top().second;
		long long d = -heap.top().first;
		heap.pop();
		if (d != dis[u]) {
			continue;
		}
		for (int i = 0; i < (int)edge[u].size(); ++i) {
			int v = edge[u][i].first;
			long long nd = d + edge[u][i].second;
			if (nd <= dis[v] && train[v]) {
				train[v] = false;
			}
			if (nd < dis[v]) {
				dis[v] = nd;
				heap.push(make_pair(-dis[v], v));
			}
		}
	}
	
	int ans = k;
	for (int i = 0; i < n; ++i) {
		ans -= train[i];
	}
	printf("%d\n", ans);
	return 0;
}