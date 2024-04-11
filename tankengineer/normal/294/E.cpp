#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5005 << 2;
int n, s[N], t[N], r[N], top, v[N], next[N], head[N], l[N], size[N];
long long sum;
bool vis[N];

void prepare() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf("%d %d %d", &s[i], &t[i], &r[i]);
	}
}

void build(int disuse, int m) {
	memset(head, 0, sizeof(head));
	top = 0;
	for (int i = 1; i <= m; ++i) {
		if (i == disuse) continue;
		++top; v[top] = t[i]; next[top] = head[s[i]]; head[s[i]] = top; l[top] = r[i];
		++top; v[top] = s[i]; next[top] = head[t[i]]; head[t[i]] = top; l[top] = r[i];
	}
}

void dfs_size(const int i) {
	size[i] = 1;
	for (int j = head[i]; j; j = next[j]) {
		if (size[v[j]] == 0) {
			dfs_size(v[j]);
			size[i] += size[v[j]];
		}
	}
}

int dfs_cen(const int i, const int n) {
	vis[i] = true;
	int maxc = n - size[i], rem = -1, tmp;
	for (int j = head[i]; j; j = next[j]) {
		if (!vis[v[j]]) {
			tmp = dfs_cen(v[j], n);
			if (tmp != -1) rem = tmp;
			maxc = max(maxc, size[v[j]]);
		}
	}
	if (maxc <= n / 2) return i; else return rem;
}

void dfs_ans(const int i) {
	vis[i] = true;
	for (int j = head[i]; j; j = next[j]) {
		if (!vis[v[j]]) {
			dfs_ans(v[j]);
			sum = sum + (long long)l[j] * size[v[j]] * (n - size[v[j]]);
		}
	}
}

int main() {
	long long ans = 1ll << 62;
	prepare();
	for (int i = 1; i < n; ++i) {
		build(i, n - 1);
		int ui = s[i], vi = t[i];
		memset(size, 0, sizeof(size));
		dfs_size(ui); dfs_size(vi);
		memset(vis, 0, sizeof(vis));
		int c1 = dfs_cen(ui, size[ui]), c2 = dfs_cen(vi, size[vi]);
		//cout << i << ' ' << c1 << ' ' << c2 << endl;
		memset(size, 0, sizeof(size));
		s[n] = c1; t[n] = c2; r[n] = r[i];
		build(i, n);
		dfs_size(1);
		memset(vis, 0, sizeof(vis));
		sum = 0;
		dfs_ans(1);
		ans = min(sum, ans);
	}
	cout << ans << endl;
	return 0;
}