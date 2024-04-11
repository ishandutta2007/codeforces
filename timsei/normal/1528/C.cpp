#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const int M = N * 2;

int n, ans = 0, cnt = 0;

struct Tree {
	vector <int> G[N];
	int dlc, L[N], R[N];
	void init() {
		for(int i = 1; i <= n; ++ i) G[i].clear(), L[i] = R[i] = 0;
		dlc = 0;
	}
	
	void add(int x, int y) {
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	void dfs(int x, int f) {
		L[x] = ++ dlc;
		for(int i = 0; i < (int) G[x].size(); ++ i) {
			int V = G[x][i];
			if(V == f) continue;
			dfs(V, x);
		}
		R[x] = dlc;
	}
	
	void doit() {
		dfs(1, 0);
	}
}A, B;

int S[N];
#define lb(x) (x & (-x))

void Add(int x, int v) {
	for(int i = x; i <= n; i += lb(i))
	S[i] += v;
}

int Sum(int x) {
	int res = 0;
	for(int i = x; i; i -= lb(i))
	res += S[i];
	return res;
}

void Dfs(int x, int f) {
	int ll = B.L[x], now = Sum(ll);
	if(now > 0) {
		Add(B.L[now], -now);
		Add(B.R[now] + 1, now);
	}
	else {
		++ cnt; ans = max(ans, cnt);
	}
	ans = max(ans, cnt);
	Add(B.L[x], x);
	Add(B.R[x] + 1, -x);
	for(int i = 0; i < (int) A.G[x].size(); ++ i) {
		int V = A.G[x][i];
		if(V == f) continue;
		Dfs(V, x);
	}
	Add(B.L[x], -x);
	Add(B.R[x] + 1, x);
	if(!now) -- cnt;
	else {
		Add(B.L[now], now);
		Add(B.R[now] + 1, - now);
	}
	return;
}

void rmain() {
	scanf("%d", &n);
	A.init();
	B.init();
	cnt = 0; ans = 0;
	for(int i = 1; i <= n; ++ i) S[i] = 0;
	for(int i = 2, x; i <= n; ++ i) {
		scanf("%d", &x);
		A.add(i, x);
	}
	for(int i = 2, x; i <= n; ++ i) {
		scanf("%d", &x);
		B.add(i, x);
	}
	A.dfs(1, 0);
	B.dfs(1, 0);
	Dfs(1, 0);
	cout << ans << endl;
}

int main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}