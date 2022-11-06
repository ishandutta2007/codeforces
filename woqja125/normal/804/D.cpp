#include<stdio.h>
#include<vector>
#include<map>
#include<queue>
using namespace std;
vector<int> in[100001];
int d[100001], c[100001], s[100001], l[100001], l2[100001];
int C = 0;
vector<int> cc[100001];
vector<long long> ccs[100001];

int max(int a, int b) { return a > b ? a : b; }

int dfs1(int x, int C) {
	c[x] = C;
	s[C]++;
	int re = 0;
	priority_queue<int> H;
	H.emplace(0);
	H.emplace(0);
	for (auto xx : in[x]) {
		if (c[xx]) continue;
		re = max(re, dfs1(xx, C));
		H.emplace(l[xx] + 1);
	}
	l[x] = H.top();
	int t = H.top(); H.pop();
	re = max(re, t + H.top());
	return re;
}

void dfs2(int x, int p, int ul) {
	priority_queue<int> H;
	H.push(ul);
	for (auto xx : in[x]) {
		if (xx == p) continue;
		H.push(l[xx] + 1);
	}
	for (auto xx : in[x]) {
		if (xx == p) continue;
		if (H.top() == l[xx] + 1) {
			int t = l[xx] + 1;
			H.pop();
			dfs2(xx, x, H.top() + 1);
			H.push(t);
		}
		else {
			dfs2(xx, x, H.top() + 1);
		}
	}
	l2[x] = H.top();
	cc[c[x]][l2[x] - d[c[x]] / 2]++;
	ccs[c[x]][l2[x] - d[c[x]] / 2]+=l2[x];
}

map<pair<int, int>, double> ans;

double getans(int x, int y) {
	if (d[x] > d[y]) x ^= y ^= x ^= y;
	if (x == y) return -1;
	long long s = 0, S = ccs[y].back();
	for (int i = 0; i < cc[x].size(); i++) {
		int t = d[y] - (i + d[x] / 2) - 1 - (d[y]/2);
		int c = cc[x][i];
		if (i != 0) c -= cc[x][i - 1];
		if (t < 0) {
			s += 1ll * c * (ccs[y].back());
			s += 1ll * c * (i + d[x] / 2 + 1) * (cc[y].back());
		}
		else{
			if (t >= cc[y].size()) t = cc[y].size() - 1;
			s += 1ll * c * d[y] * cc[y][t];
			s += 1ll * c * (ccs[y].back() - ccs[y][t]);
			s += 1ll * c * (i + d[x] / 2 + 1) * (cc[y].back() - cc[y][t]);
		}
	}
	return s / (double)cc[x].back() / cc[y].back();
}

int main() {
	int n, m, q, a, b;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		in[a].push_back(b);
		in[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (c[i]) continue;
		C++;
		d[C] = dfs1(i, C);
		cc[C].resize(d[C] - d[C] / 2 + 1);
		ccs[C].resize(d[C] - d[C]/2 + 1);
		dfs2(i, C, 0);
		for (int i = 1; i < cc[C].size(); i++) cc[C][i] += cc[C][i - 1], ccs[C][i] += ccs[C][i-1];
	}
	for (int i = 1; i <= q; i++) {
		scanf("%d%d", &a, &b);
		a = c[a]; b = c[b];
		if (a > b) a ^= b ^= a ^= b;
		if (ans.count({ a, b }) == 0) printf("%.10f\n", ans[{a, b}] = getans(a, b));
		else printf("%.10f\n", ans[{a, b}]);
	}
	return 0;
}