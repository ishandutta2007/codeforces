#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1500;
int n, ans[N], size[N];
vector<int> edge[N], ch[N];
vector<pair<int, pair<int, int> > > p;

bool by_x(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
	return a.second.first < b.second.first || a.second.first == b.second.first && a.second.second < b.second.second;
}

pair<int, int> cur;

bool by_r(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
	long long x1 = a.second.first - cur.first, y1 = a.second.second - cur.second, x2 = b.second.first - cur.first, y2 = b.second.second - cur.second;
	return x1 * y2 - x2 * y1 < 0;
}

void dfs(int u, int fa) {
	size[u] = 1;
	for (int j = 0; j < (int)edge[u].size(); ++j) {
		int v = edge[u][j];
		if (v == fa) {
			continue;
		}
		ch[u].push_back(v);
		dfs(v, u);
		size[u] += size[v];
	}
}

void solve(int u, vector<pair<int, pair<int, int> > > p) {
	for (int i = 0 ; i < (int)p.size(); ++i) {
		if (by_x(p[i], p.back())) {
			swap(p[i], p[p.size() - 1]);
		}
	}
	cur = p.back().second;
	ans[p.back().first] = u;
	p.pop_back();
	sort(p.begin(), p.end(), by_r);
	for (int i = 0; i < (int)ch[u].size(); ++i) {
		vector<pair<int, pair<int, int> > > tmp;
		int v = ch[u][i];
		for (int j = 0; j < size[v]; ++j) {
			tmp.push_back(p.back());
			p.pop_back();
		}
		solve(v, tmp);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(0, -1);
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		p.push_back(make_pair(i, make_pair(x, y)));
	}
	solve(0, p);
	for (int i = 0; i < n; ++i) {
		printf("%d%c", ans[i] + 1, i == n - 1 ? '\n' : ' ');
	}
	return 0;
}