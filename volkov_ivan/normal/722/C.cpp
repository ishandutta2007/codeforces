#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100000;
int parents[MAX_N + 1];
int sz[MAX_N + 1];
int arr[MAX_N + 1];
int perm[MAX_N + 1];
long long summ[MAX_N + 1];

int find_parent(int v) {
	if (parents[v] == -1) {
		return -1;
	}
	if (parents[v] == v) {
		return v;
	}
	parents[v] = find_parent(parents[v]);
	return parents[v];
}

int merge_dsu(int u, int v) {
	u = find_parent(u);
	v = find_parent(v);
	if (u == v || v == -1) {
		return u;
	}
	if (u == -1) {
		return v;
	}
	if (sz[u] < sz[v]) {
		parents[u] = v;
		summ[v] += summ[u];
		return v;
	}
	else {
		parents[v] = u;
		summ[u] += summ[v];
		return u;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> perm[i];
	}
	for (int i = 1; i <= n; i++) {
		parents[i] = -1;
	}
	vector <long long> ans;
	int now, old;
	long long now_ans = 0;
	for (int i = n; i > 0; i--) {
		ans.push_back(now_ans);
		now = perm[i];
		parents[now] = now;
		sz[now] = 1;
		summ[now] = arr[now];
		old = now;
		if (now != 1) {
			now = merge_dsu(now, now - 1);
		}
		if (old != n) {
			now = merge_dsu(now, old + 1);
		}
		now_ans = max(now_ans, summ[now]);
	}
	for (int i = n - 1; i >= 0; i--) {
		cout << ans[i] << endl;
	}
	return 0;
}