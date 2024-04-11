#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int M = N * 2;

int t, n, m, x, y, cnt, fir[N], ne[M], to[M], fa[N];

void add(int x, int y) {
	ne[++ cnt] = fir[x];
	fir[x] = cnt;
	to[cnt] = y;
}

void link(int x, int y) {
	add(x, y);
	add(y, x);
}

#define Foreachson(i, x) for(int i = fir[x]; i; i = ne[i])

vector <int> A, B;

void dfs(int x, int f) {
	fa[x] = f;
	Foreachson(i, x) {
		int V = to[i];
		if(V == f) continue;
		dfs(V, x);
	}
}

bool vis[N];

int main() {
	for(cin >> t; t --> 0;) {
		memset(fir, 0, sizeof(fir));
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		scanf("%d", &n);
		for(int i = 1; i < n; ++ i) {
			scanf("%d%d", &x, &y);
			link(x, y);
		}
		A.clear(); B.clear();
		int k;
		cin >> k;
		for(int i = 1; i <= k; ++ i) {
			scanf("%d", &x); A.push_back(x);
			vis[x] = 1;
		}
		cin >> k;
		for(int i = 1; i <= k; ++ i) {
			scanf("%d", &x); B.push_back(x);
		}
		dfs(A[0], 0);
		cout << "B " << B[0] << endl;
		fflush(stdout);
		cin >> x;
		if(vis[x]) {
			cout << "C " << x << endl;
			continue;
		}
		else {
			while(!vis[x]) x = fa[x];
			cout << "A " << x << endl;
			fflush(stdout);
			cin >> y;
			int ok = 0;
			for(int i = 0; i < (int)B.size(); ++ i) {
				if(B[i] == y) {
					ok = 1; break;
				}
			}
			if(ok) cout << "C " << x << endl;
			else cout << "C " << -1 << endl;
		}
	}
}