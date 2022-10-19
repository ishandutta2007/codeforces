#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

vector <int> G[N], B[N];

int dp[N], Min[N], rd[N], n, m, s, t, Max[N];
void link(int x, int y) {
	G[x].push_back(y);
	++ rd[x];
	B[y].push_back(x);
}

bool vis[N];

vector <int> Q[N];

main(void) {
	scanf("%d%d", &n, &m);
	for(int i = 1, x, y; i <= m; ++ i) {
		scanf("%d%d", &x, &y);
		link(x, y);
	}
	memset(dp, -1, sizeof(dp));
	cin >> s >> t;
	Q[0].push_back(t);
	for(int i = 1; i <= n; ++ i) Min[i] = 2e9;
	for(int i = 0; i <= n; ++ i) {
		if(!Q[i].size()) continue;
		for(int j = 0; j < (int) Q[i].size(); ++ j) {
			int now = Q[i][j];
			dp[Q[i][j]] = i;
			for(auto V : B[now]) {
				-- rd[V];
				Min[V] = min(Min[V], i);
				Max[V] = max(Max[V], i);
				if(!rd[V] && !vis[V]) {
					vis[V] = 1;
					Q[i].push_back(V);
				}
			}
		}
		for(int j = 0; j < (int) Q[i].size(); ++ j) {
			int now = Q[i][j];
			for(auto V : B[now]) {
				if(rd[V] && !vis[V]) {
					vis[V] = 1;
					Q[i + 1].push_back(V);
				}
			}
		}
	}
	cout << dp[s] << endl;
}