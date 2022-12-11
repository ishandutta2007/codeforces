#include <iostream>
#include <vector>

using namespace std;

struct node{
	int l, r, summ;
	bool rev = 0;
	node() {};
	node(int l, int r, int summ) {
		this->l = l;
		this->r = r;
		this->summ = summ;
	}
};

const int MAX_N = 1 << 18;
pair <int, int> segm[MAX_N + 1];
node t[2 * MAX_N];
int T = 0;
vector <int> g[MAX_N + 1];
int on[MAX_N + 1];

void DFS(int v) {
	t[MAX_N + T] = node(T + 1, T + 1, on[v]);
	T++;
	segm[v].first = T;
	for (int i = 0; i < g[v].size(); i++) {
		DFS(g[v][i]);
	}
	segm[v].second = T;
}

void relax(int num) {
	t[num].summ = t[2 * num].summ + t[2 * num + 1].summ;
}

void full(int num, bool rev) {
	t[num].rev ^= rev;
	if (rev) {
		t[num].summ = (t[num].r - t[num].l + 1) - t[num].summ;
	}
}

void push(int num) {
	full(2 * num, t[num].rev);
	full(2 * num + 1, t[num].rev);
	t[num].rev = 0;
}

void build(int l, int r, int num) {
	if (l == r) {
		return;
	}
	int m = (l + r) / 2;
	build(l, m, 2 * num);
	build(m + 1, r, 2 * num + 1);
	t[num] = node(l, r, t[2 * num].summ + t[2 * num + 1].summ);
}

void update(int l, int r, int a, int b, int num) {
	if (a > r || b < l) {
		return;
	}
	if (a <= l && r <= b) {
		full(num, 1);
		return;
	}
	push(num);
	int m = (l + r) / 2;
	update(l, m, a, b, 2 * num);
	update(m + 1, r, a, b, 2 * num + 1);
	relax(num);
}

int find_summ(int l, int r, int a, int b, int num) {
	if (a > r || b < l) {
		return 0;
	}
	if (a <= l && r <= b) {
		return t[num].summ;
	}
	push(num);
	int m = (l + r) / 2;
	return find_summ(l, m, a, b, 2 * num) + find_summ(m + 1, r, a, b, 2 * num + 1);
}

int main() {
	int n, v, m;
	string s;
	scanf("%d\n", &n);
	for (int u = 2; u <= n; u++) {
		scanf("%d ", &v);
		g[v].push_back(u);
	}
	scanf("\n");
	for (int i = 1; i <= n; i++) {
		scanf("%d ", &on[i]);
	}
	scanf("\n");
	DFS(1);
	for (int i = n; i < MAX_N; i++) {
		t[MAX_N + i] = node(i + 1, i + 1, 0);
	}
	build(1, MAX_N, 1);
	scanf("%d\n", &m);
	for (int i = 0; i < m; i++) {
		cin >> s;
		scanf("%d/n", &v);
		//cin >> s >> v;
		//cout << s;
		if (s == "get") {
			printf("%d\n", find_summ(1, MAX_N, segm[v].first, segm[v].second, 1));
		} else {
			update(1, MAX_N, segm[v].first, segm[v].second, 1);
		}
	}
	return 0;
}