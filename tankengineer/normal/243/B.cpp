#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;
int n, m, h, t, d[N];
vector<int> edge[N];

int merge(int u, int v) {
	vector<int> &a = edge[u], &b = edge[v];
	int ret = 0, i = 0, j = 0;
	while (ret < h + t + 2 && i < a.size() && j < b.size()) {
		++ret;
		if (a[i] < b[j]) {
			++i;
		} else if (a[i] > b[j]) {
			++j;
		} else {
			++i;
			++j;
		}
	}
	ret += a.size() - i + b.size() - j;
	return ret;
}

map<int, int> full;

void makeAnswer(int u, int v) {
	printf("YES\n");
	printf("%d %d\n", u + 1, v + 1);
	vector<int> head, tail, mid;
	for (int i = 0; i < (int)edge[u].size(); ++i) {
		if (edge[u][i] != v) {
			full[edge[u][i]] = -1;
		}
	}
	for (int i = 0; i < (int)edge[v].size(); ++i) {
		if (edge[v][i] != u) {
			full[edge[v][i]] += 1;
		}
	}
	for (map<int, int>::iterator it = full.begin(); it != full.end(); ++it) {
		if (it->second == -1) {
			head.push_back(it->first);
		} else if (it->second == 1) {
			tail.push_back(it->first);
		} else {
			mid.push_back(it->first);
		}
	}
	while (head.size() < h) {
		head.push_back(mid.back());
		mid.pop_back();
	}
	while (tail.size() < t) {
		tail.push_back(mid.back());
		mid.pop_back();
	}
	for (int i = 0; i < h; ++i) {
		printf("%d%c", head[i] + 1, i == h - 1 ? '\n' : ' ');
	}
	for (int i = 0; i < t; ++i) {
		printf("%d%c", tail[i] + 1, i == t - 1 ? '\n' : ' ');
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &h, &t);
	for (int i = 0; i < m; ++i) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		--t1, --t2;
		++d[t1], ++d[t2];
		edge[t1].push_back(t2);
		edge[t2].push_back(t1);
	}
	for (int i = 0; i < n; ++i) {
		sort(edge[i].begin(), edge[i].end());
	}
	for (int i = 0; i < n; ++i) {
		int u = i;
		if (d[u] < h + 1) {
			continue;
		}
		for (int j = 0; j < (int)edge[u].size(); ++j) {
			int v = edge[u][j];
			if (d[v] < t + 1) {
				continue;
			}
			if (max(d[u], d[v]) >= h + t + 2 || merge(u, v) >= h + t + 2) {
				makeAnswer(u, v);
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}