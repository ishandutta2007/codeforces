#include <bits/stdc++.h>
using namespace std;

const int N = 1505 * 2;

int n, x, y, l = -1, r = -1, L = -1, R = -1;
vector <int> G[N], All;
long long ans = 0;

bool vis[N];

void dfs(int x) {
	if(vis[x]) return;
	vis[x] = 1;
	All.push_back(x);
	dfs(G[x][0]);
	dfs(G[x][1]);
}

void upd(int x) {
	if(x <= n) {
		r = max(r, x);
		l = min(l, x);
		return;
	}
	R = max(R, x);
	L = min(L, x);
}

void calc(int x, int y, int k) {
	if(x >= l && x <= r) return;
	if(x >= L && x <= R) return;
	if(y >= l && y <= r) return;
	if(y >= L && y <= R) return;
	int ll = 1, rr = n, LL = n + 1, RR = 2 * n;
	if(x <= n) {
		if(x < l) ll = max(ll, x + 1);
		else rr = min(rr, x - 1);
	} else {
		if(x < L) LL = max(LL, x + 1);
		else RR = min(RR, x - 1);
	}
	if(y <= n) {
		if(y < l) ll = max(ll, y + 1);
		else rr = min(rr, y - 1);
	} else {
		if(y < L) LL = max(LL, y + 1);
		else RR = min(RR, y - 1);
	}
	ans = ans + 1LL * k * (l - ll + 1) * (rr - r + 1) * (L - LL + 1) * (RR - R + 1);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= 2 * n; ++ i) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	ans = 0;
	for(int i = 1; i <= n; ++ i) {
		if(vis[i]) continue;
		All.clear(); dfs(i);
		l = n + 1, r = 0, L = 2 * n + 1, R = 0;
		for(int a = 0; a < (int) All.size(); ++ a) upd(All[a]);
//		cerr << "All" << endl;
//		for(auto x : All) cerr << x << ' ';
//		cerr << endl;
		calc(0, 0, All.size() / 2);
//		cerr << ans << endl;
		for(int a = 0; a < (int) All.size(); ++ a) {
			l = n + 1, r = 0, L = 2 * n + 1, R = 0;
			upd(All[a]);
			for(int len = 2; len < 2 * n; ++ len) {
				upd(All[(a + len - 1) % All.size()]);
				calc(All[(a + (int) All.size() - 1) % All.size()], All[(a + len) % All.size()], len / 2);
//				cerr << a <<' ' << len <<' ' << l <<' ' << r <<' ' << L << ' ' << R <<' ' << ans << endl;
			}
		}
	}
	
	cout << ans << endl;
}