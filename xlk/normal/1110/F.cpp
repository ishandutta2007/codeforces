#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int > > a[500020];
vector<pair<int, pair<int, int> > > b[500020];
long long z[500020];
long long d[500020];
int ss, n, q;
int L[500020];
int R[500020];
long long mn[2000020];
long long ad[2000020];
void bd(int x, int l, int r) {
	if (l == r - 1) {
		if (a[l + 1].size() == 0) {
			mn[x] = d[l + 1];
		} else {
			mn[x] = 1e18;
		}
		return;
	}
	int m = (l + r) / 2;
	bd(x * 2, l, m);
	bd(x * 2 + 1, m, r);
	mn[x] = min(mn[x * 2], mn[x * 2 + 1]);
}

void push(int x) {
	mn[x * 2] += ad[x];
	ad[x * 2] += ad[x];
	mn[x * 2 + 1] += ad[x];
	ad[x * 2 + 1] += ad[x];
	ad[x] = 0;
}

void cg(int x, int l, int r, int L, int R, long long V) {
	if (L <= l && r <= R) {
		mn[x] += V;
		ad[x] += V;
		return;
	}
	if (r <= L || R <= l) {
		return;
	}
	push(x);
	int m = (l + r) / 2;
	cg(x * 2, l, m, L, R, V);
	cg(x * 2 + 1, m, r, L, R, V);
	mn[x] = min(mn[x * 2], mn[x * 2 + 1]);
}

long long qy(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return mn[x];
	}
	if (r <= L || R <= l) {
		return (long long)1e18;
	}
	push(x);
	int m = (l + r) / 2;
	return min(qy(x * 2, l, m, L, R), qy(x * 2 + 1, m, r, L, R));
}

void dfs(int x) {
	L[x] = ss++;
	for (int i = 0; i < a[x].size(); i++) {
		d[a[x][i].first] = d[x] + a[x][i].second;
		dfs(a[x][i].first);
	}
	R[x] = ss;
}
void print() {
	printf("{\n");
	for (int i = 0; i < n; i++) {
		printf("%lld\n", qy(1, 0, n, i, i + 1));
	}
	printf("}\n");
}
void ddd(int x) {
	for (int i = 0; i < b[x].size(); i++) {
		int l = b[x][i].second.first;
		int r = b[x][i].second.second;
//		print();
		z[b[x][i].first] = d[x] + qy(1, 0, n, L[l], L[r] + 1);
//		printf("%d %d %d %d\n", 0, n, L[l], L[r] + 1);
//		printf("%d\n", qy(1, 0, n, 4, 5));
		// l - 1, r
	}
	for (int i = 0; i < a[x].size(); i++) {
		cg(1, 0, n, L[a[x][i].first], R[a[x][i].first], -2 * a[x][i].second);
		ddd(a[x][i].first);
		cg(1, 0, n, L[a[x][i].first], R[a[x][i].first], 2 * a[x][i].second);
	}
}
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(make_pair(i, y));
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	dfs(1);
	bd(1, 0, n);
	for (int i = 0; i < q; i++) {
		int x, l, r;
		scanf("%d%d%d", &x, &l, &r);
		b[x].push_back(make_pair(i, make_pair(l, r)));
	}
	ddd(1);
	for (int i = 0; i < q; i++) {
		printf("%lld\n", z[i]);
	}
	return 0;
}