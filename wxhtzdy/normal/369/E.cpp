#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+5;

vector<int> st[4 * N];

void dodaj(int node, int l, int r, int x, int y) {
	st[node].push_back(y);
	if (l >= r) return;
	int mid = (l + r) / 2;
	if (x <= mid) dodaj(node * 2, l, mid, x, y);
	else dodaj(node * 2 + 1, mid + 1, r, x, y);
}

void sredi(int node, int l, int r) {
	sort(st[node].begin(), st[node].end());
	if (l >= r) return;
	int mid = (l + r) / 2;
	sredi(node * 2, l, mid);
	sredi(node * 2 + 1, mid + 1, r);
}

int upit(int node, int l, int r, int ll, int rr) {
	if (l > r || l > rr || r < ll) return 0;
	if (ll <= l && r <= rr) {
		auto it = lower_bound(st[node].begin(), st[node].end(), rr + 1);
		return it - st[node].begin();
	}
	int mid = (l + r) / 2;
	return upit(node * 2, l, mid, ll, rr) + upit(node * 2 + 1, mid + 1, r, ll, rr);
}

int main() {
	int n, m; 
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int l, r; 
		scanf("%d%d", &l, &r);
		dodaj(1, 1, N, l, r);
	}
	sredi(1, 1, N);
	while (m--) {
		int cnt;
		scanf("%d", &cnt);
		vector<int> points = {0, N};
		for (int i = 0; i < cnt; i++) {
			int x; 
			scanf("%d", &x);
			points.push_back(x);
		}
		sort(points.begin(), points.end());
		int ans = 0;
		for (int i = 0; i < (int) points.size() - 1; i++) {
			ans += upit(1, 1, N, points[i] + 1, points[i + 1] - 1);
		}
		printf("%d\n", n - ans);
	}
	return 0;
}