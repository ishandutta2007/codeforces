#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<utility>
using namespace std;

const int N = 100000;
int n, m, x[N][2], y[N][2], z[N], px[N], py[N], ans[N];
vector<int> values;

bool by_z(int i, int j) {
	return z[i] < z[j];
}

int root[N << 1];

int getID(const int l, const int r) {
	return l + r | l != r;
}

const int LOG = 18;
pair<int, int> key[N * LOG];
int treapCount, weight[N * LOG], minY[N * LOG], maxY[N * LOG], minID[N * LOG], children[N * LOG][2];

void update(int x) {
	minY[x] = children[x][0] ? minY[children[x][0]] : key[x].first;
	maxY[x] = children[x][1] ? maxY[children[x][1]] : key[x].first;
	minID[x] = min(key[x].second, min(minID[children[x][0]], minID[children[x][1]]));
}

void rotate(int &x, int t) {
	int y = children[x][t];
	children[x][t] = children[y][1 ^ t];
	children[y][1 ^ t] = x;
	update(x);
	update(y);
	x = y;
}

void treapInsert(int &x, pair<int, int> k) {
	if (x) {
		int t = key[x] < k;
		treapInsert(children[x][t], k);
		if (weight[children[x][t]] < weight[x]) {
			rotate(x, t);
		}
	} else {
		x = treapCount++;
		key[x] = k;
		weight[x] = rand();
	}
	update(x);
}

void treapDelete(int &x, pair<int, int> k) {
	if (key[x] == k) {
		if (children[x][0] || children[x][1]) {
			rotate(x, weight[children[x][0]] > weight[children[x][1]]);
			treapDelete(x, k);
		} else {
			x = 0;
			return;
		}
	} else {
		treapDelete(children[x][key[x] < k], k);
	}
	update(x);
}

int treapQuery(int x, int y1, int y2) {
	if (!x || y2 < minY[x] || maxY[x] < y1) {
		return INT_MAX;
	}
	if (y1 <= minY[x] && maxY[x] <= y2) {
		return minID[x];
	}
	int ret = min(treapQuery(children[x][0], y1, y2), treapQuery(children[x][1], y1, y2));
	if (y1 <= key[x].first && key[x].first <= y2) {
		ret = min(ret, key[x].second);
	}
	return ret;
}

void segInsert(int l, int r, int x, int y, int w) {
	if (x < values[l] || values[r] < x) {
		return;
	}
	treapInsert(root[getID(l, r)], make_pair(y, w));
	if (l < r) {
		int m = l + r >> 1;
		segInsert(l, m, x, y, w);
		segInsert(m + 1, r, x, y, w);
	}
}

void segDelete(int l, int r, int x, int y, int w) {
	if (x < values[l] || values[r] < x) {
		return;
	}
	treapDelete(root[getID(l, r)], make_pair(y, w));
	if (l < r) {
		int m = l + r >> 1;
		segDelete(l, m, x, y, w);
		segDelete(m + 1, r, x, y, w);
	}
}

int segQuery(int l, int r, int x1, int x2, int y1, int y2) {
	if (x2 < values[l] || values[r] < x1) {
		return INT_MAX;
	}
	if (x1 <= values[l] && values[r] <= x2) {
		return treapQuery(root[getID(l, r)], y1, y2);
	}
	int m = l + r >> 1;
	return min(segQuery(l, m, x1, x2, y1, y2), segQuery(m + 1, r, x1, x2, y1, y2));
}

int main() {
	treapCount = 1;
	weight[0] = INT_MAX;
	minY[0] = INT_MAX;
	maxY[0] = INT_MIN;
	minID[0] = INT_MAX;
	vector<int> ord;
	memset(children, 0, sizeof(children));

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d%d%d", &x[i][0], &x[i][1], &y[i][0], &y[i][1], z + i);
		ord.push_back(i);
	}
	sort(ord.begin(), ord.end(), by_z);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", px + i, py + i);
		values.push_back(px[i]);
	}
	sort(values.begin(), values.end());
	values.erase(unique(values.begin(), values.end()), values.end());
	memset(ans, -1, sizeof(ans));
	for (int i = 0; i < m; ++i) {
		segInsert(0, values.size() - 1, px[i], py[i], i);
	}
	for (int _ = 0; _ < n; ++_) {
		int i = ord[_];
		int ret = segQuery(0, values.size() - 1, x[i][0], x[i][1], y[i][0], y[i][1]);
		if (ret != INT_MAX) {
			ans[ret] = i;
			segDelete(0, values.size() - 1, px[ret], py[ret], ret);
		}
	}
	for (int i = 0; i < m; ++i) {
		printf("%d\n", ans[i] + 1);
	}
	return 0;
}