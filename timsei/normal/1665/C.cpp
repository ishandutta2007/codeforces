#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int t, n, x, y, vis[N];

vector <int> G[N], All;

bool pd(int ans) {
	int cur = ans - All.size(), now = 0;
	for(int i = 0; i < (int) All.size(); ++ i) {
		++ now;
		cur -= max(0, now + All[i] - 1 - ans);
	}
	return cur >= 0;
}

void rmain() {
	scanf("%d", &n);
	vis[1] = 1;
	for(int i = 1; i <= n; ++ i) G[i].clear(), vis[i] = 0;
	for(int i = 2, x; i <= n; ++ i) {
		scanf("%d", &x);
		vis[x] = 1;
		G[x].push_back(i);
	}
	int tot = 0;
	for(int i = 1; i <= n; ++ i) if(vis[i]) ++ tot;
	All.clear();
	for(int i = 1; i <= n; ++ i) if(G[i].size()) All.push_back(G[i].size());
	All.push_back(1);
	sort(All.begin(), All.end());
	reverse(All.begin(), All.end());
	int ans = tot + 1;
	int now = 0;
	int l = tot + 1, r = n, res = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(pd(mid)) {
			res = mid; r = mid - 1;
		} else l = mid + 1;
		
	}
	cout << res << endl;
}

int main() {
	for(cin >> t; t --;) {
		rmain();
	}
}