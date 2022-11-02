#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000, M = 3 * 1000;
int n, m;

int top, head[N], to[M * 2], next[M * 2], l[M * 2], r[M * 2];

void addedge(int u, int v, int a, int b) {
	to[top] = v, next[top] = head[u], l[top] = a, r[top] = b, head[u] = top++;
}

int map[1000000 + 1];

int len[N][M + 1];

int main() {
	scanf("%d%d", &n, &m);
	vector<int> ord;
	ord.push_back(1);
	top = 0;
	memset(head, -1, sizeof(head));
	for (int i = 0; i < m; ++i) {
		int u, v, a, b;
		scanf("%d%d%d%d", &u, &v, &a, &b);
		--u, --v;
		addedge(u, v, a, b);
		addedge(v, u, a, b);
		ord.push_back(a);
	}
	sort(ord.begin(), ord.end());
	ord.erase(unique(ord.begin(), ord.end()), ord.end());	
	for (int i = 0; i < (int)ord.size(); ++i) {
		map[ord[i]] = i;
	}
	memset(len, 0, sizeof(len));
	priority_queue<pair<int, pair<int, int> > > heap;
	len[0][0] = 1000000;
	heap.push(make_pair(1000000, make_pair(0, 0)));
	while (heap.size()) {
		int lb = ord[heap.top().second.first], u = heap.top().second.second, rb = lb + heap.top().first - 1;
		heap.pop();
		if (len[u][map[lb]] != rb - lb + 1) {
			continue;
		}
		for (int j = head[u]; ~j; j = next[j]) {
			int v = to[j], nlb = max(lb, l[j]), nrb = min(rb, r[j]);
			if (nrb < nlb) {
				continue;
			}
			int nl = map[nlb], ll = nrb - nlb + 1;
			if (len[v][nl] < ll) {
				len[v][nl] = ll;
				heap.push(make_pair(ll, make_pair(nl, v)));
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < (int)ord.size(); ++i) {
		if (len[n - 1][i] > ans) {
			ans = len[n - 1][i];
		}
	}
	if (ans == 0) {
		puts("Nice work, Dima!");
	} else {
		printf("%d\n", ans);
	}
	return 0;
}