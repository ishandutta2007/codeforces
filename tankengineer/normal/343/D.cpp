#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 500005, M = N << 1;
int n, in[N], out[N], fa[N];
vector<int> edge[N];
vector<pair<int, int> > stack;

void getdfs() {
	fa[0] = -1;
	in[0] = 0;
	stack.push_back(make_pair(0, 0));
	int cnt = 0;
	while (stack.size()) {
		pair<int, int> tp = stack.back();
		stack.pop_back();
		int u = tp.first, i = tp.second;
		if (i == edge[u].size()) {
			out[u] = cnt;
		} else {
			stack.push_back(make_pair(u, i + 1));
			int v = edge[u][i];
			if (v != fa[u]) {
				fa[v] = u;
				stack.push_back(make_pair(v, 0));
				in[v] = ++cnt;
			}
		}
	}
}

int data1[M], data2[M];

int getID(int l, int r) {
	return l + r | l != r;
}

void mark1(int l, int r, int t) {
	int i = getID(l, r);
	data1[i] = max(data1[i], t);
}

void pushdown1(int l, int r) {
	int i = getID(l, r), k = l + r >> 1;
	if (data1[i]) {
		mark1(l, k, data1[i]);
		mark1(k + 1, r, data1[i]);
	}
}

void segSetmax(int l, int r, int a, int b, int t) {
	if (b < a) {
		return ;
	}
	if (b < l || r < a) {
		return ;
	}
	if (a <= l && r <= b) {
		data1[getID(l, r)] = t;
		return ;
	}
	int k = l + r >> 1;
	pushdown1(l, r);
	segSetmax(l, k, a, b, t);
	segSetmax(k + 1, r, a, b, t);
	data1[getID(l, r)] = 0;
}

int segGetmax(int l, int r, int pos) {
	if (data1[getID(l, r)]) {
		return data1[getID(l, r)];
	}
	if (l == r) {
		return -1;
	}
	int k = l + r >> 1;
	if (pos <= k) {
		return segGetmax(l, k, pos);
	} else {
		return segGetmax(k + 1, r, pos);
	}
}

void fill(int i, int t) {
	segSetmax(0, n - 1, in[i], out[i], t);
}

void update2(int l, int r) {
	int k = l + r >> 1;
	data2[getID(l, r)] = max(data2[getID(l, k)], data2[getID(k + 1, r)]);
}

void segInsmax(int l, int r, int pos, int val) {
	if (pos < l || pos > r) {
		return;
	}
	if (l == r) {
		data2[getID(l, r)] = val;
		return;
	}
	int k = l + r >> 1;
	segInsmax(l, k, pos, val);
	segInsmax(k + 1, r, pos, val);
	update2(l, r);
}

int segAskmax(int l, int r, int a, int b) {
	if (b < a) {
		return 0;
	}
	if (b < l || r < a) {
		return 0;
	}
	if (a <= l && r <= b) {
		return data2[getID(l, r)];
	}
	int k = l + r >> 1;
	return max(segAskmax(l, k, a, b), segAskmax(k + 1, r, a, b));
}

void clear(int i, int t) {
	segInsmax(0, n - 1, in[i], t);
}

int ask(int i) {
	int f = segGetmax(0, n - 1, in[i]), c = segAskmax(0, n - 1, in[i], out[i]);
	return f > c;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		--t1, --t2;
		edge[t1].push_back(t2);
		edge[t2].push_back(t1);
	}
	getdfs();
	int q, cnt = 0;
	scanf("%d", &q);
	while (q--) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		--t2;
		++cnt;
		if (t1 == 1) {
			fill(t2, cnt);
		} else if (t1 == 2) {
			clear(t2, cnt);
		} else {
			printf("%d\n", ask(t2));
		}
	}
	return 0;
}