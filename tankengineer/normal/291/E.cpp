#include<queue>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005, L = 300005;
int n, m, ans, fa[N], st[N], next[N];
char tmp[L], t[L];
string s[N];
vector<int> edge[N];

void getFail(char *t) {
	next[0] = -1;
	for (int i = 1; i <= m; ++i) {
		next[i] = next[i - 1];
		while (next[i] != -1 && t[next[i]] != t[i - 1]) {
			next[i] = next[next[i]];
		}
		++next[i];
	}
}

void cal(int u) {
	int p = st[fa[u]];
	for (int i = 0; i < s[u].size(); ++i) {
		++p;
		while (p != -1 && s[u][i] != t[p]) {
			p = next[p];
		}
		if (p == m - 1) {
			++ans;
		}
	}
	st[u] = p;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf("%d%s", fa + i, tmp);
		--fa[i];
		edge[fa[i]].push_back(i);
		s[i] = tmp;
	}
	scanf("%s", t);
	m = strlen(t);
	getFail(t);
	st[0] = -1;
	ans = 0;
	queue<int> q;
	for (int i = 0; i < (int)edge[0].size(); ++i) {
		q.push(edge[0][i]);
	}
	while (q.size()) {
		int i = q.front();
		cal(i);
		q.pop();
		for (int j = 0; j < (int)edge[i].size(); ++j) {
			q.push(edge[i][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}