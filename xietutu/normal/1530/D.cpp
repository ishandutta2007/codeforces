#include <bits/stdc++.h>
using namespace std;

int n, Ans;
int a[200005], vis[200005], du[200005], st[200005], cnt;

void dfs(int u) {
	vis[u] = 1; st[++ cnt] = u;
	if (!vis[a[u]]) dfs(a[u]);
	else {
		for (int i = 1; i <= cnt; ++ i) {
			if (st[i] == a[u]) {
				//circle;
				for (int j = i; j <= cnt; ++ j) {
					if (du[st[j]] > 1) {
						if (j == i) a[u] = 0;
						else a[st[j - 1]] = 0;
						break;
					}
				}
			}
		}
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++ i) vis[i] = du[i] = 0;
		Ans = 0;
		for (int i = 1; i <= n; ++ i) {
			scanf("%d", &a[i]);
			++ du[a[i]];
		}
		
		for (int i = 1; i <= n; ++ i) {
			if (!vis[i]) {
				cnt = 0;
				dfs(i);
			}
		}
		
		for (int i = 1; i <= n; ++ i) vis[i] = 0;
		for (int i = 1; i <= n; ++ i) {
			if (a[i] == 0) continue;
			if (!vis[a[i]]) {
				++ Ans;
				vis[a[i]] = i;
			} else a[i] = 0;
		}
		
		vector <int> v1, v2, v;
		for (int i = 1; i <= n; ++ i) {
			if (a[i] != 0 && vis[i] == 0) {
				v1.push_back(i);
			} else
			if (a[i] == 0 && vis[i] != 0) {
				v2.push_back(i);
			} else if (a[i] == 0 && vis[i] == 0) {
				v.push_back(i);
			}
		}
		if (v.size() == 1) {
			if (v1.size() == 0) {
				for (int i = 1; i <= n; ++ i) {
					if (a[i] != 0) {
						a[v[0]] = a[i];
						a[i] = v[0];
					}
				}
				-- Ans;
			} else {
				int tmp1 = v1.back();
				v1.pop_back();
				a[v[0]] = tmp1;
				v1.push_back(v[0]);
			}
			v.pop_back();
		}
		for (int i = 0; i < v1.size(); ++ i) {
			vis[v1[i]] = v2[i];
			a[v2[i]] = v1[i];
		}
		for (int i = 0; i < v.size(); ++ i) {
			if (i == v.size() - 1) {
				a[v[i]] = v[0];
			} else {
				a[v[i]] = v[i + 1];
			}
		}
		printf("%d\n", Ans);
		for (int i = 1; i <= n; ++ i) printf("%d%c", a[i], i == n ? '\n' : ' ');
	}
	return 0;
}