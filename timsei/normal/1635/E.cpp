#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m, ty, a, b, t[N], A[N], B[N], dep[N], fa[N], du[N], cnt = 0, Tr[N];

vector <int> G[N], bG[N];

int getf(int x) {
	if(fa[x] == x) {
		dep[x] = 0;
		return x;
	}
	int now = getf(fa[x]);
	dep[x] = dep[x] ^ dep[fa[x]];
	fa[x] = now;
	return now;
}

int merge(int x, int y) {
	int nx = getf(x), ny = getf(y);
	if(nx == ny && dep[x] == dep[y]) return 0;
	if(nx == ny) return 1;
	fa[nx] = ny;
	dep[nx] = dep[x] ^ dep[y] ^ 1;
	return 1;
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) fa[i] = i, Tr[i] = 0;
	for(int i = 1; i <= m; ++ i) {
		scanf("%d%d%d", &t[i], &A[i], &B[i]);
		if(!merge(A[i], B[i])) {
			puts("NO");
			return 0;
		}
	}
	for(int i = 1; i <= n; ++ i) {
		getf(i);
	}
	for(int i = 1; i <= m; ++ i) {
		if(t[i] != 1) t[i] = 0;
		if((dep[A[i]] ^ t[i]) == 1) {
			G[A[i]].push_back(B[i]); ++ du[B[i]];
		} else G[B[i]].push_back(A[i]), ++ du[A[i]];
	}
	queue <int> q;
	for(int i = 1; i <= n; ++ i) if(!du[i]) q.push(i);
	while(!q.empty()) {
		int x = q.front(); q.pop();
		++ cnt;
		A[x] = cnt;
		for(auto V : G[x]) {
			-- du[V];
			if(!du[V]) {
				q.push(V);
			}
		}
	}
	if(cnt != n) {
		puts("NO"); return 0;
	}
	puts("YES");
	for(int i = 1; i <= n; ++ i) {
		if(dep[i] == 0) {
			printf("L %d\n", A[i]);
		} else printf("R %d\n", A[i]);
	}
}