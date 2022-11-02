#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <time.h>
#include <cstdlib>

using namespace std;

const int MAXN = 100010;
int v[MAXN];
int ans[MAXN];
int tree[4 * MAXN];

int search(int lm, int rm, int l, int r, int it) {
	if (l == lm && r == rm) {
		return tree[it];
	} else {
		int m = (l + r) / 2;
		if (rm <= m) {
			return search(lm, rm, l, m, 2 * it);
		} else if (lm > m) {
			return search(lm, rm, m + 1, r, 2 * it + 1);
		} else {
			return max(search(lm, m, l, m, 2 * it), search(m + 1, rm, m + 1, r, 2 * it + 1));
		}
	}
}

void insert(int el, int l, int r, int it, int ans) {
	if (l == r) {
		tree[it] = ans;
	} else {
		int m = (l + r) / 2;
		if (el <= m) {
			insert(el, l, m, 2 * it, ans);
		} else {
			insert(el, m + 1, r, 2 * it + 1, ans);
		}
		tree[it] = max(tree[2 * it], tree[2 * it + 1]);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	int res = 0;
	for (int i = n - 1; i >= 0; i--) {
		ans[i] = search(v[i], n, 1, n, 1) + 1;
		res = max(res, ans[i]);
		insert(v[i], 1, n, 1, ans[i]);
	}
	printf("%d", res);
	return 0;
}