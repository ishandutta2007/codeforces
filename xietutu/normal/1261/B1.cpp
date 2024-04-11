#include <bits/stdc++.h>
using namespace std;

const int MaxN = 200005;

struct re{
	int val, id;
	bool operator () (const re &a, const re &b) {
		return a.val > b.val || (a.val == b.val && a.id < b.id);
	}
}a[MaxN];

int n, m;
int Ans[MaxN], c[MaxN * 4], val[MaxN];

typedef pair <int, int> pii;

vector <pii> Q[MaxN];

void add(int p, int l, int r, int x) {
	++ c[p];
	if (l == r) return;
	int mid = (l + r) >> 1, ll = p << 1;
	if (x <= mid) add(ll, l, mid, x);
	else add(ll | 1, mid + 1, r, x);
}

int query(int p, int l, int r, int K) {
	if (l == r) return val[l];
	int mid = (l + r) >> 1, ll = p << 1;
	if (c[ll] >= K) return query(ll, l, mid, K);
	else return query(ll | 1, mid + 1, r, K - c[ll]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &val[i]);
		a[i] = (re){val[i], i};
	}
	sort(a + 1, a + 1 + n, re());
	for (int i = 1; i <= n; ++ i) Q[i].clear();
	
	scanf("%d", &m);
	for (int i = 1; i <= m; ++ i) {
		int k, pos; scanf("%d%d", &k, &pos);
		Q[k].push_back(pii(pos, i));
	}
	
	for (int i = 1; i <= 4 * n; ++ i) c[i] = 0;
	for (int i = 1; i <= n; ++ i) {
		add(1, 1, n, a[i].id);
		for (auto q : Q[i]) {
			Ans[q.second] = query(1, 1, n, q.first);
		}
	}
	
	for (int i = 1; i <= m; ++ i) printf("%d\n", Ans[i]);
	
	return 0;
}