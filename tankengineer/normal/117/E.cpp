#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 100005;

int n, col[N], fa[N], size[N], depth[N];
vector<int> edge[N], c;
bool vis[N], oncycle[N];

vector<int> queue;

void dfs(const int i, int &cycle) {
	queue.push_back(i);
	depth[i] = depth[fa[i]] + 1;
	size[i] = 1;
	vis[i] = true;
	for (int j = 0; j < (int)edge[i].size(); ++j) {
		int v = edge[i][j];
		if (!vis[v]){
			fa[v] = i;
			int tmpcyc = -1;
			dfs(v, tmpcyc);
			if (tmpcyc != -1) {
				cycle = tmpcyc;
			}
		} else if (v != fa[i] && depth[v] < depth[i]) {
			cycle = v;
		}
	}
	if (cycle != -1) {
		c.push_back(i);
		oncycle[i] = true;
		if (i == cycle) {
			cycle = -1;
		}
	}
	size[fa[i]] += size[i];
}

void dye(const int i, const int color) {
	vis[i] = true;
	col[i] = color;
	for (int j = 0; j < (int)edge[i].size(); ++j) {
		int v = edge[i][j];
		if (vis[v] || oncycle[v]) {
			continue;
		}
		dye(v, color);
	}
}

int path_count, belongs[N], head[N], length[N];

void divide() {
	memset(length, 0, sizeof(length));
	path_count = 0;
	belongs[1] = -1;
	for (int i = 0; i < n; ++i) {
		int u = queue[i];
		if (belongs[u] == -1) {
			head[belongs[u] = path_count++] = fa[u];
		}
		length[belongs[u]] ++;
		for (int iter = 0; iter != (int)edge[u].size(); ++iter) {
			int v = edge[u][iter];
			if (fa[v] == u) {
				belongs[v] = size[v] * 2 > size[u] - 1 ? belongs[u] : -1;
			}
		}
	}
}

int get_lca(int u, int v) {
	while (belongs[u] != belongs[v]) {
		int &w = depth[head[belongs[u]]] > depth[head[belongs[v]]] ? u : v;
		w = head[belongs[w]];
	}
	return depth[u] < depth[v] ? u : v;
}

struct Node {
	bool flag;
	int data;
	Node *left, *right;

	Node(Node *left, Node *right) : flag(false), data(0), left(left), right(right) {}

	void covern(const int l, const int r) {
		flag ^= 1;
		data = (r - l) - data;
	}

	void push_down(const int l, const int r) {
		if (flag) {
			int m = (l + r) >> 1;
			left->covern(l, m);
			right->covern(m, r);
			flag = false;
		}
	}

	void update() {
		data = left->data + right->data;
	}

	void cover(const int l, const int r, const int a, const int b) {
		if (b <= l || r <= a) {
			return ;
		}
		if (a <= l && r <= b) {
			covern(l, r);
		} else {
			push_down(l, r);
			int m = l + r >> 1;
			left->cover(l, m, a, b);
			right->cover(m, r, a, b);
			update();
		}
	}

	int query(const int l, const int r, const int a, const int b) {
		if (a <= l && r <= b) {
			return data;
		}
		push_down(l, r);
		int m = l + r >> 1;
		if (b <= m) {
			return left->query(l, m, a, b);
		}
		if (m <= a) {
			return right->query(m, r, a, b);
		}
		return left->query(l, m, a, b) + right->query(m, r, a, b);
	}

};

Node* build(int n) {
	return new Node(n == 1 ? NULL : build(n >> 1), n == 1 ? NULL : build(n + 1 >> 1));
}

Node *trees[N];

void coverp(int a, int d) {
	while (d > 0) {
		int p = belongs[a];
		int i = depth[a] - depth[head[p]];
		trees[p]->cover(0, length[p], max(i - d, 0), i);
		d -= i;
		a = head[p];
	}
}

void cover(int a, int b) {
	int c = get_lca(a, b);
	coverp(a, depth[a] - depth[c]);
	coverp(b, depth[b] - depth[c]);
}

int queryp(int a, int d) {
	int ret = 0;
	while (d > 0) {
		int p = belongs[a];
		int i = depth[a] - depth[head[p]];
		ret += trees[p]->query(0, length[p], max(i - d, 0), i);
		d -= i;
		a = head[p];
	}
	return ret;
}

int query(int a, int b) {
	int c = get_lca(a, b);
	if (depth[a] - depth[c] <= 0) {
		return queryp(b, depth[b] - depth[c]);
	}
	if (depth[b] - depth[c] <= 0) {
		return queryp(a, depth[a] - depth[c]);
	}
	return queryp(a, depth[a] - depth[c]) + queryp(b, depth[b] - depth[c]);
}

int edgesum = 0;

void reverse(const int x, const int y) {
	if (x == y) {
		return;
	}
	edgesum -= query(x, y);
	cover(x, y);
	edgesum += query(x, y);
}

int main() {
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		edge[t1].push_back(t2);
		edge[t2].push_back(t1);
	}
	depth[0] = 1;
	fa[1] = 0;
	int cycle = -1;
	dfs(1, cycle);
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < c.size(); ++i) {
		dye(c[i], i);
	}
	divide();
	for (int i = 0; i < path_count; ++i) {
		trees[i] = build(length[i]);
	}
	int extedge = 0;
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (col[x] == col[y]) {
			reverse(x, y);
		} else {
			int tx = x, ty = y;
			x = c[col[tx]], y = c[col[ty]];
			reverse(tx, x);
			reverse(ty, y);
			int dis = max(col[x], col[y]) - min(col[x], col[y]);
			int firsta = c[(col[x] + 1) % c.size()],
				firstb = c[(col[x] - 1 + c.size()) % c.size()];
			if (col[y] > col[x]) {
				swap(firsta, firstb);
			}
			if (dis < c.size() - dis || dis == c.size() - dis && firsta > firstb) {
				reverse(x, y);
			} else {
				if (col[x] > col[y]) {
					swap(x, y);
				}
				reverse(c[0], x);
				reverse(y, c.back());
				extedge ^= 1;
			}
		}
		printf("%d\n", n - edgesum - (query(c[0], c.back()) == c.size() - 1 ? 0 : extedge));
	}
	return 0;
}