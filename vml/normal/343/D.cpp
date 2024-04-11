#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

#define lld I64d

struct elem {
	int sum;
	bool delta;
	elem(): sum(0), delta(false) {}
	elem(int sum, bool delta): sum(sum), delta(delta) {}
};

const int MAXN = 500010;
vector <int> ed[MAXN];
int parent[MAXN];
int t = 0;
int n;
pair <int, int> segments[MAXN];
elem tree[4 * MAXN];
int number;

void dfs(int v, int p) {
	parent[v] = p;
	t++;
	segments[v].first = t;
	for (int i = 0; i < (int) ed[v].size(); i++) {
		if (ed[v][i] != p) {
			dfs(ed[v][i], v);
		}
	}
	segments[v].second = t;
}

void sets(int l, int r, int it) {
	tree[it].delta = true;
	tree[it].sum = r - l + 1;
}

void reculc(int l, int r, int it) {
	tree[it].sum = tree[2 * it].sum + tree[2 * it + 1].sum;
}

void push(int l, int r, int it) {
	if (tree[it].delta) {
		int m = (l + r) / 2;
		sets(l, m, 2 * it);
		sets(m + 1, r, 2 * it + 1);
		tree[it].delta = false;
	}
}

void change(int l, int r, int lm, int rm, int it) {
	if (l == lm && r == rm) {
		number += tree[it].sum;
		sets(l, r, it);
	} else {
		push(l, r, it);
		int m = (l + r) / 2;
		if (rm <= m) {
			change(l, m, lm, rm, 2 * it);
		} else if (lm > m) {
			change(m + 1, r, lm, rm, 2 * it + 1);
		} else {
			change(l, m, lm, m, 2 * it);
			change(m + 1, r, m + 1, rm, 2 * it + 1);
		}
		reculc(l, r, it);
	}
}

void erase(int l, int r, int x, int it) {
	if (l == r) {
		tree[it].sum = 0;
	} else {
		push(l, r, it);
		int m = (l + r) / 2;
		if (x <= m) {
			erase(l, m, x, 2 * it);
		} else {
			erase(m + 1, r, x, 2 * it + 1);
		}
		reculc(l, r, it);
	}
}

bool find(int l, int r, int lm, int rm, int it) {
	bool ans;
	if (l == lm && r == rm) {
		if (l != r) {
			push(l, r, it);
			reculc(l, r, it);
		}
		ans = tree[it].sum == r - l + 1;
	} else {
		push(l, r, it);
		int m = (l + r) / 2;
		if (rm <= m) {
			ans = find(l, m, lm, rm, 2 * it);
		} else if (lm > m) {
			ans = find(m + 1, r, lm, rm, 2 * it + 1);
		} else {
			ans = find(l, m, lm, m, 2 * it) && find(m + 1, r, m + 1, rm, 2 * it + 1);
		}
		reculc(l, r, it);
	}
	return ans;
}

int main() {
#ifdef ONLINE_JUDGE
	//freopen("circuit.in", "r", stdin);
	//freopen("circuit.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	dfs(1, -1);
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int c;
		int v;
		scanf("%d %d", &c, &v);
		if (c == 1) {
			number = 0;
			change(1, n, segments[v].first, segments[v].second, 1);
			if (number != segments[v].second - segments[v].first + 1 && v != 1) {
				erase(1, n, segments[parent[v]].first, 1);
			}
		} else if (c == 2) {
			erase(1, n, segments[v].first, 1);
		} else {
			printf("%d\n", find(1, n, segments[v].first, segments[v].second, 1));
		}
	}
	return 0;
}

/*
5
1 2
2 3
3 4
4 5
4
1 1
2 2
1 2
3 1
*/