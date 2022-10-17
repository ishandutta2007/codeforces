#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 200200;
int a[MAXN], n, pos[MAXN];
bool vis[MAXN];

vector <int> v[MAXN]; int top;
vector < pair<int, int> > ans;

int main () {
	int n = read(), i, j;
	for (i = 1; i <= n; i++) a[i] = read(), pos[a[i]] = i;
	for (i = 1; i <= n; i++) if (a[i] != i && !vis[i]) {
		int now = a[i]; vis[i] = 1; v[++top].push_back(i);
		while (now != i) {
			vis[now] = 1;
			v[top].push_back(now);
			now = a[now];
		}
	}
	if (top & 1) {
		if (v[top].size() == 2) {
			int tmp = 1;
			if (v[top][0] == 1 || v[top][1] == 1) {
				++tmp;
				if (v[top][0] == 2 || v[top][1] == 2) ++tmp;
			}
			ans.push_back(make_pair(v[top][0], tmp));
			ans.push_back(make_pair(v[top][1], tmp));
			ans.push_back(make_pair(v[top][0], tmp));
		}
		else {
			for (i = 2; i < v[top].size(); i++) ans.push_back(make_pair(v[top][0], v[top][i - 1]));
			ans.push_back(make_pair(v[top][1], v[top].back()));
			ans.push_back(make_pair(v[top][0], v[top].back()));
			ans.push_back(make_pair(v[top][0], v[top][1]));
		}
	}
	for (i = 1; i + 1 <= top; i += 2) {
		for (auto j: v[i + 1]) ans.push_back(make_pair(v[i][0], j));
		for (j = 1; j < v[i].size(); j++) ans.push_back(make_pair(v[i + 1][0], v[i][j]));
		ans.push_back(make_pair(v[i + 1][0], v[i][0]));
	}
	printf("%d\n", ans.size());
	for (auto i: ans) printf("%d %d\n", i.first, i.second);
	return 0;
}