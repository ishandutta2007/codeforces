#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

int l, r, Min1, Min2, n, a, b, c, P[N], vis[N];

int ask(int x) {
	printf("? %d\n", x);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}

void solve(int x) {
	vector <int> All; 
	int now = ask(x);
	All.push_back(now);
	while(1) {
		int y = ask(x);
		if(y == now) {
			break;
		}
		All.push_back(y);
	}
	int it = All.size(), fo = -1;
	for(int i = 0; i < (int) All.size(); ++ i) {
		P[All[i]] = All[(i + 1) % it];
		vis[All[i]] = 1;
	}
}

void solve() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) vis[i] = 0;
	for(int i = 1; i <= n; ++ i) if(!vis[i]) {
		solve(i);	
	}
	printf("!");
	for(int i = 1; i <= n; ++ i) {
		printf(" %d", P[i]);
	}
	puts("");
	fflush(stdout);
}

int main() {
	int t;
	for(cin >> t; t --;) {
		solve();
	}
}